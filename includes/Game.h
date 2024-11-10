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

class Game
{
private:
	static Game* instance_;
	Game();
	~Game();

public:
	static Game *instance();
	SDL_Renderer *getRenderer() { return renderer_; }
	GameStateMachine *getStateMachine() { return &gameStateMachine_; }
	bool isRunning() { return isRunning_; }
	bool init(int flags = SDL_WINDOW_SHOWN);
	void clean();
	void update();
	void render();
	void handleEvents();
	void quit();
	void addScore();
	void printScore(int size, int x, int y);
	void resetScore();
private:
	SDL_Window *window_;
	SDL_Renderer *renderer_;
	int score_;
	bool isRunning_;
	GameStateMachine gameStateMachine_;
};

