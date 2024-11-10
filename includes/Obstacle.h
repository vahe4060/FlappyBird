#pragma once
#include "GameObject.h"

class Obstacle :public GameObject
{
public:
	Obstacle(int x, int y, int w, int h, const char *id);
	~Obstacle();
	void update() override;
	void draw() override;
	int x() override { return x_; }
	int y() override { return (y_ + 50); }
private:
	void genNext();
};