#include "Game.h"
#include <cassert>

Game::Game() 
	: window_(nullptr)
	, renderer_(nullptr)
	, record_(0)
	, isRunning_(false)
	, gameStateMachine_()
{
}

Game::~Game()
{
}

void Game::run()
{
	int frameStart, frameEnd, FrameDuration;

    if (!init()) {
        std::cerr << "Couldn't initialize Game\n";
        return;
    }
    while (isRunning())
    {
        frameStart = SDL_GetTicks();
        update();
        handleEvents();
        render();
        frameEnd = SDL_GetTicks();
        FrameDuration = frameEnd - frameStart;
        if (FRAME_MS > FrameDuration) SDL_Delay(FRAME_MS - FrameDuration);
    }
    exit();
}

void Game::exit()
{
	gameStateMachine_.popState();
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
}

Game *Game::instance()
{
	static Game	instance_;
	return &instance_;
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
		gameStateMachine_.pushState(new MenuState(record_, this));
		isRunning_ = true;
		return true;
	}
	return false;
}

void Game::update()
{
	InputHandler::instance()->update();
	gameStateMachine_.update();
}

void Game::render()
{
	SDL_RenderClear(renderer_);
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

void Game::newGame()
{
	gameStateMachine_.popState();
	gameStateMachine_.pushState(new PlayState(this));
}

void Game::gameOver(int score)
{
	gameStateMachine_.popState();
	gameStateMachine_.pushState(new GameOverState(score, this));
	if (score > record_)
		record_ = score;
}

void Game::openMenu()
{
	gameStateMachine_.popState();
	gameStateMachine_.pushState(new MenuState(record_, this));
}
