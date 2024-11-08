#pragma once
#include "InputHandler.h"
#include <iostream>
#include "GameStateMachine.h"
#include "Player.h"
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"

#define WinHeight 768
#define WinWidth  432

class Game
{
private:
	static Game* instance_;
	Game();
	~Game();

public:
	static Game* instance();
	SDL_Renderer* getRenderer() { return renderer; }
	GameStateMachine* getStateMachine() { return gameStateMachine; }
	bool init(int flags = SDL_WINDOW_SHOWN);
	void clean();
	void update();
	void render();
	void handleEvents();
	void quit();
	void addscore();
	void printScore(int size, int x, int y);
	void reset();

private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	GameStateMachine *gameStateMachine;
	int score;
public:
	bool isRunning;
};

