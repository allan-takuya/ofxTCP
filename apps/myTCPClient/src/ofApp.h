
#include "ofMain.h"
#include "ofxTCPImageClient.h"

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
	ofxTCPImageClient mTCPImageClient;
	ofImage mImage;
};
