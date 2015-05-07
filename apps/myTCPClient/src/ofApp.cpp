#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(60,60,70);
}

//--------------------------------------------------------------
void ofApp::update(){
	mTCPImageClient.update(1024*100);

	if( mTCPImageClient.getHasImageData()){
		mImage.allocate(mTCPImageClient.getWidth(), mTCPImageClient.getHeight(), OF_IMAGE_COLOR);
		mImage.setFromPixels((const unsigned char*)mTCPImageClient.getImageData(), mTCPImageClient.getWidth(), mTCPImageClient.getHeight(), OF_IMAGE_COLOR);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	string statusStr =  "status: " + mTCPImageClient.getStateStr();
	statusStr += " -- loaded "+ofToString(mTCPImageClient.getPctLoaded(), 2)+"%";

	ofSetColor(255, 0, 255);
	ofDrawBitmapString(statusStr, 10, 20);
	ofDrawBitmapString("client - launch server than hit c key to connect - r to reset the state", 10, ofGetHeight()-20);

	ofSetColor(255, 255, 255);
	if( mTCPImageClient.getHasImageData() ){
		mImage.draw(0, 25);
	}
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
	if( key == 'c'){
		mTCPImageClient.setup("192.168.11.2", 12354);
	}
	if(key == 'r'){
		mTCPImageClient.reset();
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

