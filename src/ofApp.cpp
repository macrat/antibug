#include "ofApp.h"


void ofApp::setup() {
	ofBackground(ofColor::black);
	ofEnableBlendMode(OF_BLENDMODE_ADD);

	for(int i=0; i<1024; i++){
		float length = ofRandom(ofGetWidth()+ofGetHeight());
		float angle = ofRandom(0, 2*PI);
		sparks.push_back(std::shared_ptr<Spark>(new Spark(ofPoint(ofGetWidth()/2 + cos(angle)*length, ofGetHeight()/2 + sin(angle)*length))));
	}
}


void ofApp::update() {
	for(auto x: sparks){
		x->update();
	}
	for(auto x: pulses){
		x->update();
	}
	ofRemove(pulses, Pulse::shouldRemove);
}


void ofApp::draw() {
	for(auto x: sparks){
		x->draw();
	}
	for(auto x: pulses){
		x->draw();
	}
}


void ofApp::mousePressed(int x, int y, int key) {
	pulses.push_back(std::shared_ptr<Pulse>(new Pulse(ofPoint(x, y), &sparks)));
}
