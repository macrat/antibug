#pragma once

#include <ofMain.h>

#define min(x, y)  (x < y ? x : y)


class Spark {
private:
	ofPoint pos, speed, mouse;
	const float size;
	const ofColor color;
	bool lock;

public:
	Spark(ofPoint pos) : pos(pos), size(ofRandom(1.0, 3.0)), color(ofRandom(200, 255), ofRandom(190, 240), ofRandom(160, 200), ofRandom(0, 255)) {}

	void update() {
		mouse.set(ofGetMouseX(), ofGetMouseY());

		if(!lock){
			speed = speed*0.98 + (mouse - pos) / 1000.0 + ofPoint(ofRandom(-1.0, 1.0), ofRandom(-1.0, 1.0));

			if(((int)ofRandom(0, 100)) == 0){
				lock = true;
			}
		}else if(((int)ofRandom(0, 10)) == 0){
			lock = false;
		}

		pos += speed;
	}

	void hit(const ofPoint& base) {
		speed += (pos - base).normalize() * 12;
	}

	float distance(const ofPoint& base) const {
		return pos.distance(base);
	}

	void draw() const {
		ofFill();
		ofSetColor(color);
		ofDrawCircle(pos, 2);
	}
};
