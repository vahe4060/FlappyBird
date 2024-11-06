#include "game.h"
#include <cassert>

game::game()
{
}

game::~game()
{

}

game* game::instance_ = nullptr;

game* game::instance()
{
	if (instance_ == nullptr)
		instance_ = new game();

	assert(instance_);
	return instance_;
}


bool game::init(int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		if (flags == 0) flags = SDL_WINDOW_SHOWN;

		window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WinWidth, WinHeight, flags);
		if (!window) return false;

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (!renderer) return false;


		if (!textureManager::instance()->load("assets/background.png", "background")) return false;
		if (!textureManager::instance()->load("assets/button.png", "button")) return false;
		if (!textureManager::instance()->load("assets/numbers.png", "numbers")) return false;

		GameStateMachine = new gameStateMachine();

		GameStateMachine->pushState(new menuState());
		
		isRunning = true;

		
		return true;
	}
	return false;
}


void game::clean()
{
	textureManager::instance()->erase("background");
	textureManager::instance()->erase("button");
	textureManager::instance()->erase("numbers");
	
	GameStateMachine->popState();
	GameStateMachine->popState();
	delete GameStateMachine;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

}


void game::update()
{
	inputHandler::instance()->update();
	GameStateMachine->update();
}

void game::render()
{
	textureManager::instance()->draw("background", 0, 0, WinWidth, WinHeight, 0);
	GameStateMachine->render();

	SDL_RenderPresent(renderer);
}


void game::handleEvents()
{

}


void game::quit()
{
	isRunning = false;
}

void game::addscore()
{
	score++;
}

void game::reset()
{
	score = 0;
}

void game::printScore(int zoom, int x, int y)
{
	int myscore = score;
	int i = 1;
	while (myscore /= 10)
	{
		i++;
	}
	myscore = score;

	for (int j = i; j > 0; j--)
	{
		int digit = myscore / pow(10, j - 1);

		textureManager::instance()->draw("numbers", x - zoom * 10 * j, y, 8, 10, digit, zoom);
		myscore -= digit * pow(10, j - 1);
	}

}