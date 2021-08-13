#pragma once
#include "GameObject.h"

class player:public gameObject
{
public:
	player(const loaderParams* params);
	virtual ~player();

	void update() override;
	void draw() override;

	void jump();
	int xPos() { return xpos; }
	int yPos() { return ypos; }
private:

};

