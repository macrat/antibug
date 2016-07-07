#pragma once

#include <memory>
#include <vector>

#include <ofMain.h>

#include "spark.h"


class Pulse {
private:
	const ofPoint pos;
	float size, speed;
	const std::vector< std::shared_ptr<Spark> >* targets;

public:
	Pulse(ofPoint pos, std::vector< std::shared_ptr<Spark> >* targets) : pos(pos), targets(targets) {
		size = 0.0;
		speed = 1.0;
	}

	void update() {
		speed += 0.1;
		size += speed;

		for(auto x: *targets){
			if(size-16 <= x->distance(pos) && x->distance(pos) <= size+6){
				x->hit(pos);
			}
		}
	}

	void draw() const {
		ofNoFill();
		ofSetColor(ofColor::green, 255 - size/2.0);
		ofSetLineWidth(size/12);
		ofDrawCircle(pos, size);
	}

	bool isAlive() const {
		return size <= 512;
	}

	static bool shouldRemove(std::shared_ptr<Pulse> x) {
		return !x->isAlive();
	}
};
