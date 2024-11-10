#include "Game.h"
#include <cassert>

Game::Game() 
	: window_(nullptr)
	, renderer_(nullptr)
	, gameStateMachine_(GameStateMachine())
	, score_(0)
	, isRunning_(false)
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
		window_ = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, 
				  				   SDL_WINDOWPOS_CENTERED, WINWIDTH, WINHEIGHT, flags);
		if (!window_)
			return false;
		renderer_ = SDL_CreateRenderer(window_, -1, 0);
		if (!renderer_)
			return false;
		TextureManager::instance()->setRenderer(renderer_);
		if (!TextureManager::instance()->load("./assets/background.png", "background"))
			return false;
		if (!TextureManager::instance()->load("./assets/button.png", "button"))
			return false;
		if (!TextureManager::instance()->load("./assets/numbers.png", "numbers"))
			return false;
		gameStateMachine_.pushState(new MenuState());
		isRunning_ = true;
		return true;
	}
	return false;
}

void Game::clean()
{
	TextureManager::instance()->eraseAll();
	gameStateMachine_.popState();
	gameStateMachine_.popState();
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
}

void Game::update()
{
	InputHandler::instance()->update();
	gameStateMachine_.update();
}

void Game::render()
{
	TextureManager::instance()->draw("background", 0, 0, WINWIDTH, WINHEIGHT, 0);
	gameStateMachine_.render();
	SDL_RenderPresent(renderer_);
}

void Game::handleEvents()
{
}

void Game::quit()
{
	isRunning_ = false;
}

void Game::addScore()
{
	score_++;
}

void Game::resetScore()
{
	score_ = 0;
}

void Game::printScore(int zoom, int x, int y)
{
	int myscore = score_;
	int i = 1;
	while (myscore /= 10)
		i++;
	myscore = score_;

	for (int j = i; j > 0; j--)
	{
		int digit = myscore / pow(10, j - 1);

		TextureManager::instance()->draw("numbers", x - zoom * 10 * j, y, 
										 FONTWIDTH, FONTHEIGHT, digit, zoom);
		myscore -= digit * pow(10, j - 1);
	}
}