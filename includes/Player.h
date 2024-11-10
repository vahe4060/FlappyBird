#pragma once
#include "GameObject.h"

class Player: public GameObject
{
public:
	Player(int x, int y, int w, int h, const char* id);
	~Player();
	void update() override;
	void draw() override;
	void jump();
private:

};

