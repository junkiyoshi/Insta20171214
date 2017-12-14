#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	for (int x = 0; x <= ofGetWidth(); x += 1) {
		this->heights.push_back(ofNoise(x * 0.05) * -100);
	}

	this->body_color = ofColor(255);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofBeginShape();

	for (int x = 0; x <= ofGetWidth(); x += 1) {
		ofVertex(x, 0);
	}

	int y = 0;
	int min_y = ofGetHeight();
	for (int x = ofGetWidth(); x >= 0; x -= 1) {

		this->heights[x] += ofNoise(x * 0.005 + ofGetFrameNum() * 0.005) * 10;
		ofVertex(x, this->heights[x]);

		if (min_y > this->heights[x]) {
			min_y = this->heights[x];
		}
	}

	ofEndShape(true);

	if (min_y >= ofGetHeight()) {
		for (int x = 0; x <= ofGetWidth(); x += 1) {
			this->heights[x] = ofNoise(x * 0.05 + ofGetFrameNum()) * -100;
		}
		
		ofBackground(this->body_color);
		this->body_color.setHsb(ofRandom(255), 255, 255);
		ofSetColor(this->body_color);
	}
}


//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(1920, 1080, OF_WINDOW);
	ofRunApp(new ofApp());
}