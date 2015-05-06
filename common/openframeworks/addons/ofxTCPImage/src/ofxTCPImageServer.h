#pragma once 

#include "ofxNetwork.h"
#include "turbojpeg.h"

//#define NUM_BYTES_IN_IMG (1434 * 717 * 3)

const static int INFOSIZE(12);

enum serverState{
	NONE, READY, INFORSENDING, DATASENDING	
};

class ofxTCPImageServer{
public:
	ofxTCPImageServer();
	~ofxTCPImageServer();
	int getSate(){ return mState;};
	string getStateStr();
	float getPctSent();
	void setup(int port = 11999);
	bool sendImage(unsigned char * pixelData, int w, int h, int jpegQuality);
	void update(int numToSend = 2048);

private:
	ofxTCPServer mTCP;
	serverState mState;
	int mNumSentBytes;
	int mTotalBytes;

	tjhandle mHandle;

	unsigned char* mData;
	int mWidth, mHeight;
};