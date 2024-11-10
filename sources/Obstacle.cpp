#include "Game.h"
#include "Obstacle.h"
#include <time.h>

Obstacle::Obstacle(int x, int y, int w, int h, const char* id)
	: GameObject(x, y, w, h, id) 
{
	if (!TextureManager::instance()->load("./assets/obstacle.png", id_))
		std::cout << "Cannot load ./assets/obstacle.png" << std::endl;
	std::cout << "Constructed " << id_ << std::endl;
}

Obstacle::~Obstacle()
{
	std::cout << "Destructed " << id_ << std::endl;
	GameObject::~GameObject();
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
