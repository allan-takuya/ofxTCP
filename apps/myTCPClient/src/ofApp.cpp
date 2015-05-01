#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(60,60,70);
	tex.allocate(1434, 717, GL_RGB);
	pixelsLoaded = false;
}

//--------------------------------------------------------------
void ofApp::update(){
	client.update(1024*200);

	if( client.getState() == COMPLETE ){
		tex.loadData(client.pixels, 1434, 717, GL_RGB);
		pixelsLoaded = true;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	string statusStr =  "status: " + client.getStateStr();
	statusStr += " -- loaded "+ofToString(client.getPctLoaded(), 2)+"%";

	ofSetColor(255, 0, 255);
	ofDrawBitmapString(statusStr, 10, 20);
	ofDrawBitmapString("client - launch server than hit c key to connect - r to reset the state", 10, ofGetHeight()-20);

	ofSetColor(255, 255, 255);
	if( pixelsLoaded ){
		tex.draw(0, 25);
	}
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
	if( key == 'c'){
		client.setup("192.168.11.2", 12354);
	}
	if(key == 'r'){
		client.reset();
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




//#include "ofApp.h"
//
////--------------------------------------------------------------
//void ofApp::setup(){
//	ofSetWindowShape(1500, 800);
//	ofBackground(0, 0, 0);
//	ofSetVerticalSync(true);
//	ofSetFrameRate(30);
//	// TCP�̃\�P�b�g���쐬���A�T�[�o�ɐڑ�����B
//	// �ڑ��ɐ�������ƁAtrue��Ԃ��A���s�����false��Ԃ�
//	mIsConnected = mTCPClient.setup(gIPADDR, gPORT);
//	// �T�[�o�֍Đڑ�����ۂ̃^�C�}�[
//	mConnectTime = 0;
//	mDeltaTime = 0;
//	// �ڍׂȃ��b�Z�[�W���o�͂���i�f�o�b�K�̃R���\�[���Ŋm�F�ł��܂��j
//	mTCPClient.setVerbose(true);
//	mTestImage.allocate(358, 179, OF_IMAGE_COLOR);
//	mReceived = 0;
//
//}
//
////--------------------------------------------------------------
//void ofApp::update(){
//	if(mIsConnected){
//		//char* pixels = NULL;
//		//if(mTCPClient.receiveRawBytes(pixels, totalSize) == TRUE){
//		//	mtestImage.setFromPixels((unsigned char*)pixels, 717, 358, OF_IMAGE_COLOR);
//		//}
//
//		// �\�P�b�g����f�[�^��ǂݍ���
//		string str = mTCPClient.receive();
//		if(str.length() > 0){
//			mMessage = str;
//		}
//
//		//int totalPixels = 358*179*3;
//		//int i = 0;  
//		//if (mReceived == totalPixels){  
//		//	mTestImage.setFromPixels(mMessageBytes, 320, 240, OF_IMAGE_COLOR);  
//		//	mReceived = 0;  
//		//} else {  
//		//	mReceived = mTCPClient.receiveRawBytes(( char *) mMessageBytes, 500);  
//		//	char * recByte;  
//		//	if (mReceived > 0) {  
//		//		int remainderCount = totalPixels - mReceived;  
//		//		while (remainderCount > 0){  
//		//			mTCPClient.receiveRawBytes(recByte, 1);  
//		//			memcpy(&mMessageBytes[mReceived], recByte, 1); // this is kinda dumb, I know  
//		//			mReceived++;  
//		//			remainderCount--;  
//		//		}  
//		//		std::cout << mReceived << std::endl;
//		//	}  
//		//}   
//
//	} else {
//		// �܂��T�[�o�ɐڑ����ĂȂ�������A�Đڑ������݂�
//		// ���̗�ł�10�b(10000msec)���ƂɎ��݂�
//		mDeltaTime = ofGetElapsedTimeMillis() - mConnectTime;
//		if(mDeltaTime > 10000){
//			mIsConnected = mTCPClient.setup(gIPADDR, gPORT);
//			mConnectTime = ofGetElapsedTimeMillis();
//		}
//	}
//}
//
////--------------------------------------------------------------
//void ofApp::draw(){
//	mTestImage.draw(0,0);
//	int mx(0), my(0);
//	// �T�[�o����󂯎���������񂩂�A���W�����o���`�悷��
//	vector<string> strPnt = ofSplitString(mMessage, "/");
//	for(int i = 0; i < strPnt.size() - 1; i++){
//		vector<string> point = ofSplitString(strPnt[i], "|");
//		mx = atof(point[0].c_str());
//		my = atof(point[1].c_str());
//	}
//	ofRect(mx, my, 50, 50);
//}
//
////--------------------------------------------------------------
//void ofApp::keyPressed(int key){
//
//}
//
////--------------------------------------------------------------
//void ofApp::keyReleased(int key){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseMoved(int x, int y){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseDragged(int x, int y, int button){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mousePressed(int x, int y, int button){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseReleased(int x, int y, int button){
//
//}
//
////--------------------------------------------------------------
//void ofApp::windowResized(int w, int h){
//
//}
//
////--------------------------------------------------------------
//void ofApp::gotMessage(ofMessage msg){
//
//}
//
////--------------------------------------------------------------
//void ofApp::dragEvent(ofDragInfo dragInfo){ 
//
//}
//
