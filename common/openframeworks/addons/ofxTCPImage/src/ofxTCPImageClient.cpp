#include "ofxTCPImageClient.h"


//-----------------------------------------------------
ofxTCPImageClient::ofxTCPImageClient(){
	mIP = "";
	mPort = 0;

	mIsConnected = false;
	mConnectTime = 0;
	mDeltaTime = 0;

	mState			= NONE;
	mTotalBytes		= 0;
	mBytesRecieved	= 0;
	mData			= NULL;
	mImageData		= NULL;
	mWidth = 0, mHeight = 0;
	mHasImageData = false;

	mHandle = tjInitDecompress();
}

//-----------------------------------------------------
ofxTCPImageClient::~ofxTCPImageClient()
{

}

//-----------------------------------------------------
string ofxTCPImageClient::getStateStr(){
	switch(mState){
	case NONE:
		return "NONE";
	case READY:
		return "READY";
	case INFORECEIVING:
		return "INFORECEIVING";
	case DATARECEIVING:
		return "DATARECEIVING";
	default:
		return "ERR";
	}
}

//-----------------------------------------------------
float ofxTCPImageClient::getPctLoaded(){
	return ( (float)mBytesRecieved / mTotalBytes ) * 100;

}

//-----------------------------------------------------
void ofxTCPImageClient::reset(){
	mIP = "";
	mPort = 0;

	mIsConnected = false;
	mConnectTime = 0;
	mDeltaTime = 0;

	mState			= NONE;
	mTotalBytes		= 0;
	mBytesRecieved	= 0;
	mWidth = 0, mHeight = 0;
	mHasImageData = false;

	if(mData != NULL){
		tjFree(mData);
		mData = NULL;
	}
	if(mImageData != NULL){
		tjFree(mImageData);
		mImageData = NULL;
	}
	mTCP.close();
}

//-----------------------------------------------------
void ofxTCPImageClient::setup(string ip, int port){
	mIP = ip, mPort = port;
	if(mTCP.setup(ip, port)){
		mState = READY;
		mIsConnected = true;
	}
} 


//-----------------------------------------------------
void ofxTCPImageClient::update(int bytesToGet){
	if(mIsConnected){
		if( mState == INFORECEIVING || mState == DATARECEIVING ){
			if( bytesToGet + mBytesRecieved >= mTotalBytes ){
				bytesToGet -= ( ( bytesToGet + mBytesRecieved ) - mTotalBytes );
			}

			char* tmpBuffer;
			tmpBuffer = (char *)malloc(bytesToGet);
			int numRecieved = mTCP.receiveRawBytes(tmpBuffer, bytesToGet);

			if( numRecieved > 0 ){
				mState = DATARECEIVING;
				memcpy(&mData[mBytesRecieved],tmpBuffer, numRecieved);
				mBytesRecieved += numRecieved;
				static int count = 0;
				//std::cout << count++ << " " <<  mBytesRecieved << " " << bytesToGet << std::endl;
			}

			if( mBytesRecieved >= mTotalBytes ){
				mState = READY;
				int pitch=3*mWidth, flags=0, jpegsubsamp=0;
				mImageData = tjAlloc(pitch*mHeight);
				tjDecompress2(mHandle, mData, mTotalBytes, mImageData, mWidth, pitch, mHeight, TJPF_RGB, flags);
				mHasImageData = true;
			}
			free(tmpBuffer);
		}

		if(mState == READY){
			char tmpBuffer[INFOSIZE];
			int numRecieved = mTCP.receiveRawBytes(tmpBuffer, INFOSIZE);
			if(numRecieved == INFOSIZE){
				mTotalBytes = (((unsigned char)tmpBuffer[0]) | ((unsigned char)tmpBuffer[1] << 8) | ((unsigned char)tmpBuffer[2] << 16) |  ((unsigned char)tmpBuffer[3] << 24));
				mData = tjAlloc(mTotalBytes);
				mWidth = (((unsigned char)tmpBuffer[4]) | ((unsigned char)tmpBuffer[5] << 8) | ((unsigned char)tmpBuffer[6] << 16) |  ((unsigned char)tmpBuffer[7] << 24));
				mHeight = (((unsigned char)tmpBuffer[8]) | ((unsigned char)tmpBuffer[9] << 8) | ((unsigned char)tmpBuffer[10] << 16) |  ((unsigned char)tmpBuffer[11] << 24));
				mState = INFORECEIVING;
			}
		}
	} else {
		//reconnection
		mDeltaTime = ofGetElapsedTimeMillis() - mConnectTime;
		if(mDeltaTime > 10000){
			mIsConnected = mTCP.setup(mIP, mPort);
			mConnectTime = ofGetElapsedTimeMillis();
		}
	}
}
unsigned char* ofxTCPImageClient::getImageData(){
	if(mHasImageData){
		return mImageData;
	} else {
		return 0;
	}
}
