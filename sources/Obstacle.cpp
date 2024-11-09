#include "Game.h"
#include "Obstacle.h"
#include <time.h>

Obstacle::Obstacle(const LoaderParams* params) :GameObject(params) 
{
	if (!TextureManager::instance()->load("./assets/obstacle.png", id))
		std::cout << "Cannot load ./assets/obstacle.png" << std::endl;
}

Obstacle::~Obstacle()
{
	GameObject::~GameObject();
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

	TextureManager::instance()->draw(id, xpos, ypos - 600, width, height);

}

void Obstacle::genNext()
{
	std::srand(time(0));

	ypos = (rand() % 6) * 100 + 100;
}

