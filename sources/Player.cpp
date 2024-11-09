#include "Player.h"
#include "Game.h"

Player::Player(const LoaderParams* params) : GameObject(params)
{
	if (!TextureManager::instance()->load("./assets/player.png", id))
		std::cout << "Cannot load ./assets/player.png" << std::endl;
}

Player::~Player()
{
	GameObject::~GameObject();
}

void Player::update()
{
	rotateAngle = 45;
	ypos+=10;
	if (InputHandler::instance()->isKeyDown(SDL_SCANCODE_SPACE) || InputHandler::instance()->isMouseButtonDown(0))
		jump();

	if (ypos >= WinHeight) {
		std::cout << "Game Over\n";
	
	}
	SDL_Delay(60);
}

void Player::draw()
{
	if (currentFrame == 2) currentFrame = 0;
	else currentFrame++;
		
	TextureManager::instance()->draw("Player", xpos, ypos, width, height, currentFrame, 2,rotateAngle);

}

void Player::jump()
{
	ypos -= 20;
	rotateAngle = -45;
}

