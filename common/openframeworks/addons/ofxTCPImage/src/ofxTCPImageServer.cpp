#include "ofxTCPImageServer.h"

//-----------------------------------------------------
ofxTCPImageServer::ofxTCPImageServer(){
	mState		= NONE;
	mNumSentBytes = 0;
	mTotalBytes	= 0;
	mData = NULL;
	mWidth = 0, mHeight = 0;
}

//-----------------------------------------------------
ofxTCPImageServer::~ofxTCPImageServer(){

}

//-----------------------------------------------------
string ofxTCPImageServer::getStateStr(){
	switch(mState){
	case NONE:
		return "NONE";
	case READY:
		return "READY";
	case INFORSENDING:
		return "INFORSENDING";
	case DATASENDING:
		return "DATASENDING";
	default:
		return "ERR";
	}
}

//-----------------------------------------------------
float ofxTCPImageServer::getPctSent(){
	return ( (float)mNumSentBytes / mTotalBytes ) * 100;
}	

//-----------------------------------------------------
void ofxTCPImageServer::setup(int port){    
	//setup the server to listen on 11999 
	if(mTCP.setup(port)){
		mState = READY;
	}
	//setup jpeg compress
	mHandle=tjInitCompress();
} 


//-----------------------------------------------------
bool ofxTCPImageServer::sendImage(unsigned char * pixelData, int w, int h, int jpegQuality) { 
	if( mState == NONE || mState == INFORSENDING || mState == DATASENDING) {
		return false;
	}

	int pitch=0, flags=0, jpegsubsamp=0;
	unsigned long size = 0;
	mWidth = w, mHeight = h;
	int  ret = tjCompress2(mHandle, pixelData, w, pitch, h, TJPF_RGB, &mData, &size, jpegsubsamp, jpegQuality, flags);
	mState = INFORSENDING;
	mTotalBytes = (int)size;
	mNumSentBytes = 0;
	return true;
} 

//-----------------------------------------------------
void ofxTCPImageServer::update(int numToSend){

	if( mNumSentBytes >= mTotalBytes ){
		mState = READY;
		tjFree(mData);
		mData = NULL;
	}
	if( mState == DATASENDING && mNumSentBytes < mTotalBytes ){
		if( numToSend + mNumSentBytes > mTotalBytes ){
			numToSend -= ( (numToSend + mNumSentBytes) - mTotalBytes );
		}

		mTCP.sendRawBytesToAll((char *)&mData[mNumSentBytes], numToSend);
		mNumSentBytes += numToSend;
		static int count = 0;
		//std::cout << count++ << " " <<  mNumSentBytes << " " << numToSend << std::endl;

	}
	if(mState == INFORSENDING){
		//send data size
		unsigned char data[INFOSIZE];
		for(int i(0); i < 4; i++){
			data[0+i%4] = mTotalBytes >> 8*i;
			data[4+i%4] = mWidth >> 8*i;
			data[8+i%4] = mHeight >> 8*i;
		}
		mTCP.sendRawBytesToAll((char *)&data[0], 12);
		mState = DATASENDING;
	}
}
