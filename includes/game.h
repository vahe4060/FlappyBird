#pragma once
#include "inputHandler.h"
#include <iostream>
#include "gameStateMachine.h"
#include "Player.h"
#include "SDL.h"
#include "SDL_image.h"
#include "textureManager.h"

#define WinHeight 768
#define WinWidth  432

class game
{
private:
	static game* instance_;
	game();
	~game();

public:
	static game* instance();
	SDL_Renderer* getRenderer() { return renderer; }
	gameStateMachine* getStateMachine() { return GameStateMachine; }
	bool init(int flags = 0);
	void clean();
	void update();
	void render();
	void handleEvents();
	void quit();
	void addscore();
	void printScore(int size, int x, int y);
	void reset();

private:

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	gameStateMachine* GameStateMachine = nullptr;
	
	
	int score = 0;
public:
	bool isRunning;
};

