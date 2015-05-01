#include "ofMain.h"
#include "pixelServer.h"

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

		pixelServer server;
		
        ofImage testImg;
		ofVideoGrabber grabber;
};




//#pragma once
//
//#include "ofMain.h"
//#include "ofxNetwork.h"
//
//const static int gPORT(12346);
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
//
//	void sendImage();
//private:
//	ofImage mTestImage;
//	ofxTCPServer mTCPServer;
//};
//
