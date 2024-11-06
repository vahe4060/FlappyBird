#include "Player.h"
#include "game.h"

player::player(const loaderParams* params) : gameObject(params)
{
	textureManager::instance()->load("assets/player.png", id);
}

player::~player()
{
	gameObject::~gameObject();
}

void player::update()
{
	rotateAngle = 45;
	ypos+=10;
	if (inputHandler::instance()->isKeyDown(SDL_SCANCODE_SPACE) || inputHandler::instance()->isMouseButtonDown(0))
		jump();

	if (ypos >= WinHeight) {
		std::cout << "game Over\n";
	
	}
	SDL_Delay(60);
}

void player::draw()
{
	if (currentFrame == 2) currentFrame = 0;
	else currentFrame++;
		
	textureManager::instance()->draw("player", xpos, ypos, width, height, currentFrame, 2,rotateAngle);

}

void player::jump()
{
	ypos -= 20;
	rotateAngle = -45;
}

