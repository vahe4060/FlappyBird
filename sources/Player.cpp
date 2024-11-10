#include "Player.h"
#include "Game.h"

Player::Player(int x, int y, int w, int h, const char* id) 
	: GameObject(x, y, w, h, id)
{
	if (!TextureManager::instance()->load("./assets/player.png", id_))
		std::cout << "Cannot load ./assets/player.png" << std::endl;
}

Player::~Player()
{
	GameObject::~GameObject();
}

void Player::update()
{
	rotateAngle_ = 45;
	y_ += 10;
	if (InputHandler::instance()->isKeyDown(SDL_SCANCODE_SPACE) 
	    || InputHandler::instance()->isMouseButtonDown(0))
		jump();

	if (y_ >= WINHEIGHT)
		std::cout << "Game Over\n";
	SDL_Delay(60);
}

void Player::draw()
{
	if (currentFrame_ == 2) 
		currentFrame_ = 0;
	else 
		currentFrame_++;
	TextureManager::instance()->draw(id_, x_, y_, width_, height_,
									 currentFrame_, 2, rotateAngle_);
}

void Player::jump()
{
	y_ -= 20;
	rotateAngle_ = -45;
}

