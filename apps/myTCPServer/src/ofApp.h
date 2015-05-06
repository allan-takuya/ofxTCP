#include "ofMain.h"
//#include "pixelServer.h"
#include "ofxTCPImageServer.h"

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
private:
	ofxTCPImageServer mTCPImageServer;
	ofImage testImg;
	ofVideoGrabber grabber;
};
