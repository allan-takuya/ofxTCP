#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(20,20,20);
	mTCPImageServer.setup(12354);
	testImg.loadImage("image\\testimageorigin.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){
	mTCPImageServer.update(1024*100);
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	string statusStr =  "status: " + mTCPImageServer.getStateStr();
	statusStr += " -- sent "+ofToString(mTCPImageServer.getPctSent(), 2)+"%";
	
	ofSetColor(255, 0, 255);
	ofDrawBitmapString(statusStr, 10, 20);
	ofDrawBitmapString("server - launch client than hit s key to send current frame", 10, ofGetHeight()-20);

	ofSetColor(255, 255, 255);
	testImg.draw(0, 25);
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
	if( key == 's'){
		unsigned char * pix = testImg.getPixels();
		mTCPImageServer.sendImage(pix, testImg.getWidth(), testImg.getHeight(), 75);
	}
	if( key == 'd'){

	}
    
}

//--------------------------------------------------------------
void ofApp::keyReleased  (int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
   
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(){

}

