#include "Game.h"
#include "Obstacle.h"
#include <time.h>
#include <cassert>

Obstacle::Obstacle(int x, int y, int w, int h, const char* id)
	: GameObject(x, y, w, h, id) 
{
	assert(TextureManager::instance()->load("./assets/obstacle.png", id_));
}

Obstacle::~Obstacle()
{
}

void Obstacle::update()
{
	x_ -= 5;
	if (x_ < -150) { 
		x_ = 480;
		genNext();
	} 
}

void Obstacle::draw()
{
	TextureManager::instance()->draw(id_, x_, y_ - 600, width_, height_);
}

void Obstacle::genNext()
{
	std::srand(time(0));
	y_ = (rand() % 6) * 100 + 100;
}
