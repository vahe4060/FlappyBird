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
	y_ += 1;
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
	y_ -= 2;
	rotateAngle_ = -45;
}

bool Player::isCollidingObstacle(Obstacle *other)
{
	// obstacle consists of 600x39 top, 100x39 middle, 600x39 buttom parts
	// if Player isn't inside middle area, then they are colliding
	if ((x() + w() >= other->x() && x() <= other->x() + other->w()))
		if (y() + h()/2 <= other->y() + other->tubeHeight() ||		  // rotated 45
			y() + (h() + w())/2 >= other->y() + other->tubeHeight()   // rotated -45
						 		   + other->tubeSpacing())
			return true;
	return false;
}