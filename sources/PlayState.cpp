#include "ClickButton.h"
#include "Game.h"
#include "GameStates.h"
#include "InputHandler.h"
#include "Obstacle.h"
#include "Player.h"
#include "TextureManager.h"
#include <time.h>

void PlayState::update()
{	
	if (pauseButton->clicked || InputHandler::instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
		pause = true;

	if (InputHandler::instance()->isMouseButtonDown(0) ) // || InputHandler::instance()->isKeyDown(SDL_SCANCODE_SPACE)) // DOESNT WORK??!
		pause = false;

	

	if (!pause)
	{
		for (auto *i : objects)
		{
			i->update();
		}
		Player->update();
		pauseButton->update();

		Game::instance()->printScore(3, 200, 200);

		if (Player->getX() >= WinHeight)
		{
			Game::instance()->getStateMachine()->popState();
			Game::instance()->getStateMachine()->pushState(new GameOverState());
		}

		for (auto *i : objects)
		{
			if (Player->getX() + 34 > i->getX() && Player->getX() < i->getX() + 39)
			{
				if (Player->getY() < i->getY() - 50 || Player->getY() + 24 > i->getY() + 50)
				{
					Game::instance()->getStateMachine()->popState();
					Game::instance()->getStateMachine()->pushState(new GameOverState());
					break;
				}
			}
			if (i->getX() == 100) Game::instance()->addscore();
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
	Game::instance()->printScore(3, 240, 50);


}

bool PlayState::onEnter()
{
	if (!TextureManager::instance()->load("assets/numbers.png", "numbers")) return false;
	

	objects.push_back(new Obstacle(new loaderParams(300, 200, 39, 1300, "obstacle")));
	objects.push_back(new Obstacle(new loaderParams(600, 300, 39, 1300, "obstacle")));

	pauseButton = new ClickButton(new loaderParams(380, 10, 35, 35, "pause"), "assets/pause.png");
	Player = new player(new loaderParams(100, 100, 17, 12, "player"));

	return true;
}

bool PlayState::onExit()
{
	TextureManager::instance()->erase("numbers");

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
