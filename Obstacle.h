#pragma once
#include "GameObject.h"

class Obstacle :public gameObject
{
public:
	Obstacle(const loaderParams* params);
	~Obstacle();
	void update() override;
	void draw() override;
	
	int getX() { return xpos; }
	int getY() { return (ypos + 50); }
private:
	void genNext();

};