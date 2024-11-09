#include "Game.h"
#include <cassert>

Game::Game() 
	: window(nullptr)
	, renderer(nullptr)
	, gameStateMachine(nullptr)
	, score(0)
	, isRunning(false)
{
}

Game::~Game()
{
}

Game* Game::instance_ = nullptr;

Game* Game::instance()
{
	if (instance_ == nullptr)
		instance_ = new Game();
	assert(instance_);
	return instance_;
}

bool Game::init(int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, 
								  SDL_WINDOWPOS_CENTERED, WinWidth, WinHeight, flags);
		if (!window)
			return false;
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (!renderer)
			return false;
		if (!TextureManager::instance()->load("./assets/background.png", "background"))
			return false;
		if (!TextureManager::instance()->load("./assets/button.png", "button"))
			return false;
		if (!TextureManager::instance()->load("./assets/numbers.png", "numbers"))
			return false;
		gameStateMachine = new GameStateMachine();
		gameStateMachine->pushState(new MenuState());
		isRunning = true;
		return true;
	}
	return false;
}

void Game::clean()
{
	TextureManager::instance()->clearAll();

	gameStateMachine->popState();
	gameStateMachine->popState();
	delete gameStateMachine;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void Game::update()
{
	InputHandler::instance()->update();
	gameStateMachine->update();
}

void Game::render()
{
	TextureManager::instance()->draw("background", 0, 0, WinWidth, WinHeight, 0);
	gameStateMachine->render();

	SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{

}

void Game::quit()
{
	isRunning = false;
}

void Game::addscore()
{
	score++;
}

void Game::reset()
{
	score = 0;
}

void Game::printScore(int zoom, int x, int y)
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

		TextureManager::instance()->draw("numbers", x - zoom * 10 * j, y, 8, 10, digit, zoom);
		myscore -= digit * pow(10, j - 1);
	}

}