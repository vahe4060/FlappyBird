#pragma once
#include "InputHandler.h"
#include <iostream>
#include "GameStateMachine.h"
#include "Player.h"
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"

#define WINHEIGHT 768
#define WINWIDTH 432
#define FONTWIDTH 8
#define FONTHEIGHT 10
#define FPS 165
#define FRAME_MS 1000.0 / FPS

class Game
{
private:
	Game();
	~Game();
	Game(const Game &) = delete;
	Game &operator=(const Game &) = delete;
public:
	static Game *instance();
	void run();
	void quit();
	bool isRunning() { return isRunning_; }
private:
	bool init(int flags = SDL_WINDOW_SHOWN);
	void cleanup();
	void update();
	void render();
	void handleEvents();
private:
	SDL_Window *window_;
	SDL_Renderer *renderer_;
	int record_;
	bool isRunning_;
	GameStateMachine gameStateMachine_;
};
