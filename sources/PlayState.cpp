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
	if (pauseButton_->clicked() 
		|| InputHandler::instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
		pause_ = true;

	if (InputHandler::instance()->isMouseButtonDown(0)) // || InputHandler::instance()->isKeyDown(SDL_SCANCODE_SPACE)) // DOESNT WORK??!
		pause_ = false;

	if (!pause_)
	{
		for (auto *i : objects_)
		{
			i->update();
		}
		bird_->update();
		pauseButton_->update();

		Game::instance()->printScore(3, 200, 200);

		if (bird_->x() >= WINHEIGHT)
		{
			Game::instance()->getStateMachine()->popState();
			Game::instance()->getStateMachine()->pushState(new GameOverState());
		}

		for (auto *i : objects_)
		{
			if (bird_->x() + 34 > i->x() && bird_->y() < i->y() + 39)
			{
				if (bird_->y() < i->y() - 50 || bird_->y() + 24 > i->y() + 50)
				{
					Game::instance()->getStateMachine()->popState();
					Game::instance()->getStateMachine()->pushState(new GameOverState());
					break;
				}
			}
			if (i->x() == 100) Game::instance()->addScore();
		}
	}
}

void PlayState::render()
{
	for (int i = 0; i < objects_.size(); i++)
	{
		objects_[i]->draw();
	}

	pauseButton_->draw();
	bird_->draw();
	Game::instance()->printScore(3, 240, 50);
}

bool PlayState::onEnter()
{
	if (!TextureManager::instance()->load("./assets/numbers.png", "numbers"))
		return false;
	objects_.push_back(new Obstacle(300, 200, 39, 1300, "obstacle"));
	objects_.push_back(new Obstacle(600, 300, 39, 1300, "obstacle"));
	pauseButton_ = new ClickButton(380, 10, 35, 35, "pause", "./assets/pause.png");
	bird_ = new Player(100, 100, 17, 12, "player");
	return true;
}

bool PlayState::onExit()
{
	TextureManager::instance()->erase("numbers");
	for (int i = 0; i < objects_.size(); i++)
		delete objects_[i];
	delete bird_;
	delete pauseButton_;
	objects_.clear();
	return true;
}
