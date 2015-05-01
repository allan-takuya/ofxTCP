#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(20,20,20);
	server.setup(12354);
	testImg.loadImage("image\\testimageorigin.jpg");
	//grabber.initGrabber(320, 240, true);
}

//--------------------------------------------------------------
void ofApp::update(){
	server.update(1024*200);
	//grabber.grabFrame();
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	string statusStr =  "status: " + server.getStateStr();
	statusStr += " -- sent "+ofToString(server.getPctSent(), 2)+"%";
	
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
		server.sendPixels(pix);
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
//	// TCP�T�[�o�\�P�b�g��p�ӂ��A�ڑ���҂��󂯂�
//	mTCPServer.setup(gPORT);
//	mTestImage.loadImage("image\\testimage.jpg");
//	ofSetWindowShape(mTestImage.getWidth(), mTestImage.getHeight());
//}
//
////--------------------------------------------------------------
//void ofApp::update(){
//
//}
//
////--------------------------------------------------------------
//void ofApp::draw(){
//	// �ڑ�����Ă��邷�ׂẴN���C�A���g����f�[�^���󂯎��
//	// ���̏���`�悷��i
//	// �N���C�A���g���̎擾�FgetNumClients()
//	// �e�N���C�A���g�̃|�[�g�̎擾�FgetClientPort(�N���C�A���gID)
//	// �e�N���C�A���g��IP�A�h���X�̎擾�FgetClientIP(�N���C�A���gID)
//	for(int i=0; i < mTCPServer.getNumClients(); i++){
//		string port = ofToString(mTCPServer.getClientPort(i));
//		string ip = mTCPServer.getClientIP(i);
//		string info = "client " + ofToString(i) + ": from " + ip + " onport: " + port;
//		ofDrawBitmapString(info, 10, 50 * (i + 1));
//	}
//	mTestImage.draw(0,0);
//}
//
////--------------------------------------------------------------
//void ofApp::keyPressed(int key){
//	switch(key){
//	case 's':
//		sendImage();
//		break;
//	default:
//		break;
//	}
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
//	string message;
//	// �}�E�X���N���b�N�������W�𕶎���ɂ��āA���ׂẴN���C�A���g�ɑ��M
//	message = ofToString(mouseX) + "|" + ofToString(mouseY) + "/";
//	for(int i =0; i < mTCPServer.getNumClients(); i++){
//		mTCPServer.send(i, message);
//	}
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
//void ofApp::sendImage(){
//	// Class variables  
//	ofPixels pix;
//	// Function inside update(): send resized color image to TCP server program  
//	pix.setFromPixels(mTestImage.getPixels(), mTestImage.getWidth(), mTestImage.getHeight(), OF_IMAGE_COLOR);  
//	pix.resize(mTestImage.getWidth()/4, mTestImage.getHeight()/4, ofInterpolationMethod::OF_INTERPOLATE_BILINEAR);
//
//	mTCPServer.sendRawBytesToAll( (const char*)pix.getPixels(), pix.getWidth()*pix.getHeight()*3);  
//}