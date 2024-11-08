#include "Player.h"
#include "Game.h"

player::player(const loaderParams* params) : gameObject(params)
{
	TextureManager::instance()->load("assets/player.png", id);
}

player::~player()
{
	gameObject::~gameObject();
}

void player::update()
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

void player::draw()
{
	if (currentFrame == 2) currentFrame = 0;
	else currentFrame++;
		
	TextureManager::instance()->draw("player", xpos, ypos, width, height, currentFrame, 2,rotateAngle);

}

void player::jump()
{
	ypos -= 20;
	rotateAngle = -45;
}

