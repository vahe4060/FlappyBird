#include "ClickButton.h"
#include "Game.h"
#include "GameStates.h"
#include "InputHandler.h"
#include "Obstacle.h"
#include "Player.h"
#include "TextureManager.h"
#include <time.h>
#include <cassert>


PlayState::PlayState(Game *parent)
	: GameState(0, parent)
	, bird_(100, 600, 17, 12, "player")
	, pauseButton_(380, 10, 35, 35, "pause", "./assets/pause.png")
	, pause_(false)
{
    assert(TextureManager::instance()->load("./assets/background.png",
                                            "background"));
	objects_.reserve(10);
	objects_.emplace_back(300, 200, 39, 1300, "obstacle1");
	objects_.emplace_back(600, 400, 39, 1300, "obstacle2");
}

PlayState::~PlayState()
{
	objects_.clear();
    TextureManager::instance()->erase("background");
}

void PlayState::update()
{	
	if (pauseButton_.clicked() 
		|| InputHandler::instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
		pause_ = true;
	if (InputHandler::instance()->isMouseButtonDown(0))
		pause_ = false;
	if (!pause_)
	{
		for (auto &it: objects_)
			it.update();
		bird_.update();
		pauseButton_.update();

		if (bird_.x() >= WINHEIGHT)
			parent_->gameOver(score_);
		for (auto &it: objects_)
		{
			if (bird_.x() + 34 > it.x() && bird_.y() < it.y() + 39)
			{
				if (bird_.y() < it.y() - 50 || bird_.y() + 24 > it.y() + 50)
				{
					parent_->gameOver(score_);
					break;
				}
			}
			if (it.x() == 100)
				++score_;
		}
	}
}

void PlayState::render()
{
	TextureManager::instance()->draw("background", 0, 0, WINWIDTH, WINHEIGHT, 0);
	for (auto &it: objects_)
		it.draw();
	pauseButton_.draw();
	bird_.draw();
	drawScore_(3, 240, 50);
}
