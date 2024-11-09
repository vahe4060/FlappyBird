#pragma once
#include "GameObject.h"

class Obstacle :public GameObject
{
public:
	Obstacle(const LoaderParams* params);
	~Obstacle();
	void update() override;
	void draw() override;
	
	int getX() { return xpos; }
	int getY() { return (ypos + 50); }
private:
	void genNext();

};