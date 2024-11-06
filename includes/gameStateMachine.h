#pragma once
#include "gameStates.h"
#include <iostream>
#include <vector>

class gameStateMachine
{
public:
	~gameStateMachine();
	void popState();
	void pushState(gameState*);
	void update();
	void render();
private:
	std::vector<gameState*> states;
};

