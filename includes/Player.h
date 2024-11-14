#pragma once
#include "GameObject.h"

class Obstacle;

class Player: public GameObject
{
public:
	Player(int x, int y, int w, int h, const char *id);
	~Player();
	void update() override;
	void draw() override;
	bool isCollidingObstacle(Obstacle *other);
private:
	void jump();
};

