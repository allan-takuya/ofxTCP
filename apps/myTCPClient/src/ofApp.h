
#include "ofMain.h"
#include "pixelClient.h"

class ofApp : public ofSimpleApp{

	public:

		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased (int key);

		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();
		
		pixelClient client;
		ofTexture tex;
		
		bool pixelsLoaded;
		
};

//#pragma once
//
//#include "ofMain.h"
//#include "ofxNetwork.h"
//
//const static string gIPADDR("192.168.11.2");
//const static int  gPORT(12346);
//
//
//class ofApp : public ofBaseApp{
//public:
//	void setup();
//	void update();
//	void draw();
//
//	void keyPressed(int key);
//	void keyReleased(int key);
//	void mouseMoved(int x, int y);
//	void mouseDragged(int x, int y, int button);
//	void mousePressed(int x, int y, int button);
//	void mouseReleased(int x, int y, int button);
//	void windowResized(int w, int h);
//	void dragEvent(ofDragInfo dragInfo);
//	void gotMessage(ofMessage msg);
//private:
//	ofxTCPClient mTCPClient;
//	bool mIsConnected;
//	string mMessage;
//	unsigned char* mMessageBytes;
//	int mConnectTime;
//	int mDeltaTime;
//
//	ofImage mTestImage;
//	int mReceived;
//};