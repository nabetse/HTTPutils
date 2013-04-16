#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);

	ofAddListener(httpUtils.newResponseEvent,this,&testApp::newResponse);
	httpUtils.start();

	ofBackground(255,255,255);
	ofSetColor(0,0,0);
	counterMouse = 0;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofDrawBitmapString(requestStr,20,20);
	ofDrawBitmapString(responseStr,20,60);
}

//--------------------------------------------------------------
void testApp::newResponse(ofxHttpResponse & response){
	responseStr = ofToString(response.status) + ": " + (string)response.responseBody;
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
	ofxHttpForm form;
	form.action = "http://lamariamedia.com/returnsame.php";
	form.method = OFX_HTTP_POST;
	form.addFormField("number", ofToString(counter));
	form.addFile("file","4.jpg");
	httpUtils.addForm(form);
	requestStr = "message sent: " + ofToString(counter);
	counter++;
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	ofxHttpForm form;
	form.action = "http://lamariamedia.com/variables.php";
	form.method = OFX_HTTP_POST;
	form.addFormField("click", ofToString(counterMouse));
	string mensaje = "(" + ofToString(x) + "," + ofToString(y) + ")";
	form.addFormField("coord", mensaje);
	httpUtils.addForm(form);
	requestStr = "message sent: " + ofToString(counterMouse);
	counterMouse++;
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

