#pragma once

#include "ofxNetwork.h"
#include "ofMain.h"
#include "turbojpeg.h"

const static int INFOSIZE(12);

enum clientState{
	NONE, READY, INFORECEIVING, DATARECEIVING	
};

class ofxTCPImageClient{
	public:
	ofxTCPImageClient();
	~ofxTCPImageClient();

	int getSate(){return mState;};
	string getStateStr();
	float getPctLoaded();
	bool getIsConnect(){ return mIsConnected;};
	bool getHasImageData(){ return mHasImageData;};
	unsigned char* getImageData();
	int getWidth(){return mWidth;};
	int getHeight(){return mHeight;};

	void reset();
	void setup(string ip, int port = 11999);
	void update(int bytesToGet = 2048);


private:
	string mIP;
	int mPort;

	bool mIsConnected;
	int mConnectTime;
	int mDeltaTime;

	clientState mState;
	int mBytesRecieved;
	int mTotalBytes;
	ofxTCPClient mTCP;
	
	unsigned char* mData;
	unsigned char* mImageData;
	int mWidth, mHeight;
	bool mHasImageData;

	tjhandle mHandle;
};