#pragma once
#include "GameObject.h"

class Obstacle :public GameObject
{
public:
	Obstacle(int x, int y, int w, int h, const char *id, int tubeHeight = 600);
	~Obstacle();
	void update() override;
	void draw() override;
	int tubeSpacing() { return h() - 2 * tubeHeight_; }
	int tubeHeight() { return tubeHeight_; }
private:
	int tubeHeight_;
};
