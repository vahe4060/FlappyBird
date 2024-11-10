#include "ClickButton.h"
#include "Game.h"
#include "GameStates.h"
#include "InputHandler.h"
#include "Obstacle.h"
#include "Player.h"
#include "TextureManager.h"
#include <time.h>
#include <cassert>


PlayState::PlayState()
	: GameState()
	, bird_(100, 600, 17, 12, "player")
	, pauseButton_(380, 10, 35, 35, "pause", "./assets/pause.png")
{
	assert(TextureManager::instance()->load("./assets/numbers.png", "numbers"));
	objects_.reserve(10);
	objects_.emplace_back(200, 200, 39, 1300, "obstacle1");
	objects_.emplace_back(600, 400, 39, 1300, "obstacle2");
}

PlayState::~PlayState()
{
	TextureManager::instance()->erase("numbers");
	objects_.clear();
}

void PlayState::update()
{	
	if (pauseButton_.clicked() 
		|| InputHandler::instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
		pause_ = true;
	if (InputHandler::instance()->isMouseButtonDown(0)) // || InputHandler::instance()->isKeyDown(SDL_SCANCODE_SPACE)) // DOESNT WORK??!
		pause_ = false;
	if (!pause_)
	{
		for (auto &it: objects_)
			it.update();
		bird_.update();
		pauseButton_.update();

		if (bird_.x() >= WINHEIGHT)
		{
			Game::instance()->getStateMachine()->popState();
			Game::instance()->getStateMachine()->pushState(new GameOverState());
		}
		for (auto &it: objects_)
		{
			if (bird_.x() + 34 > it.x() && bird_.y() < it.y() + 39)
			{
				if (bird_.y() < it.y() - 50 || bird_.y() + 24 > it.y() + 50)
				{
					Game::instance()->getStateMachine()->popState();
					Game::instance()->getStateMachine()->pushState(new GameOverState());
					break;
				}
			}
			if (it.x() == 100) Game::instance()->addScore();
		}
	}
}

void PlayState::render()
{
	for (auto &it: objects_)
		it.draw();
	pauseButton_.draw();
	bird_.draw();
	Game::instance()->printScore(3, 240, 50);
}
