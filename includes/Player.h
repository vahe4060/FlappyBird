#pragma once
#include "GameObject.h"

class Player:public GameObject
{
public:
	Player(const LoaderParams* params);
	virtual ~Player();

	void update() override;
	void draw() override;

	void jump();
	int xPos() { return xpos; }
	int yPos() { return ypos; }
private:

};

