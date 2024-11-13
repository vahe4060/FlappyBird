#include "Player.h"
#include "Game.h"
#include <cassert>

Player::Player(int x, int y, int w, int h, const char* id) 
	: GameObject(x, y, w, h, id)
{
	assert(TextureManager::instance()->load("./assets/player.png", id_));
}

Player::~Player()
{
}

void Player::update()
{
	rotateAngle_ = 45;
	y_ += 10;
	if (InputHandler::instance()->isKeyDown(SDL_SCANCODE_SPACE) 
	    || InputHandler::instance()->isMouseButtonDown(0))
		jump();
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

