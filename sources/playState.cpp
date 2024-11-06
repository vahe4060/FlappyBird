#include "ClickButton.h"
#include "game.h"
#include "gameStates.h"
#include "inputHandler.h"
#include "Obstacle.h"
#include "Player.h"
#include "textureManager.h"
#include <time.h>

void PlayState::update()
{	
	if (pauseButton->clicked || inputHandler::instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
		pause = true;

	if (inputHandler::instance()->isMouseButtonDown(0) ) // || inputHandler::instance()->isKeyDown(SDL_SCANCODE_SPACE)) // DOESNT WORK??!
		pause = false;

	

	if (!pause)
	{
		for (auto *i : objects)
		{
			i->update();
		}
		Player->update();
		pauseButton->update();

		game::instance()->printScore(3, 200, 200);

		if (Player->getX() >= WinHeight)
		{
			game::instance()->getStateMachine()->popState();
			game::instance()->getStateMachine()->pushState(new gameOverState());
		}

		for (auto *i : objects)
		{
			if (Player->getX() + 34 > i->getX() && Player->getX() < i->getX() + 39)
			{
				if (Player->getY() < i->getY() - 50 || Player->getY() + 24 > i->getY() + 50)
				{
					game::instance()->getStateMachine()->popState();
					game::instance()->getStateMachine()->pushState(new gameOverState());
					break;
				}
			}
			if (i->getX() == 100) game::instance()->addscore();
		}

	}
}

void PlayState::render()
{
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->draw();
	}

	Player->draw();
	pauseButton->draw();
	game::instance()->printScore(3, 240, 50);


}

bool PlayState::onEnter()
{
	if (!textureManager::instance()->load("assets/numbers.png", "numbers")) return false;
	

	objects.push_back(new Obstacle(new loaderParams(300, 200, 39, 1300, "obstacle")));
	objects.push_back(new Obstacle(new loaderParams(600, 300, 39, 1300, "obstacle")));

	pauseButton = new ClickButton(new loaderParams(380, 10, 35, 35, "pause"), "assets/pause.png");
	Player = new player(new loaderParams(100, 100, 17, 12, "player"));

	return true;
}

bool PlayState::onExit()
{
	textureManager::instance()->erase("numbers");

	Player->~player();
	pauseButton->~ClickButton();
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->~Obstacle();
		delete objects[i];
	}

	delete Player;
	delete pauseButton;
	objects.clear();

	return true;
}
