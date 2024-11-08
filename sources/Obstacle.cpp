#include "Game.h"
#include "Obstacle.h"
#include <time.h>

Obstacle::Obstacle(const loaderParams* params) :gameObject(params) 
{
	TextureManager::instance()->load("assets/obstacle.png", id);

}

Obstacle::~Obstacle()
{
	gameObject::~gameObject();
}


void Obstacle::update()
{
	xpos-=5;
	if (xpos < -150) { 
		xpos = 480;
	
		genNext();
	} 
}

void Obstacle::draw()
{

	TextureManager::instance()->draw("obstacle", xpos, ypos - 600, width, height);

}

void Obstacle::genNext()
{
	std::srand(time(0));

	ypos = (rand() % 6) * 100 + 100;
}

