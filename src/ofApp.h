#pragma once

#include <memory>
#include <vector>

#include <ofMain.h>

#include "spark.h"
#include "pulse.h"


class ofApp : public ofBaseApp{
private:
	std::vector< std::shared_ptr<Spark> > sparks;
	std::vector< std::shared_ptr<Pulse> > pulses;

public:
	void setup() override;
	void update() override;
	void draw() override;

	void mousePressed(int x, int y, int key) override;
};
