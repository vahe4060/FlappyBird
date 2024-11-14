#include "Game.h"
#include "Obstacle.h"
#include <time.h>
#include <cassert>

Obstacle::Obstacle(int x, int y, int w, int h, const char* id, int tubeHeight)
	: GameObject(x, y, w, h, id)
	, tubeHeight_(tubeHeight)
{
	assert(TextureManager::instance()->load("./assets/obstacle.png", id_));
	assert((tubeHeight_ * 2 < h) && 
			"No spacing area left with current tubeHeight and image height\n");
}

Obstacle::~Obstacle()
{
}

void Obstacle::update()
{
	x_ -= 1;
	if (x_ < -w()) { 
		x_ = WINWIDTH + 2 * w();
		// we want the tubes not to go out of window
		y_ =  rand() % (WINHEIGHT - tubeHeight()) - (WINHEIGHT - tubeHeight());
	} 
}

void Obstacle::draw()
{
	TextureManager::instance()->draw(id_, x_, y_, width_, height_);
}
