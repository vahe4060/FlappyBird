#pragma once
#include "GameStates.h"
#include <iostream>
#include <stack>

class GameStateMachine
{
public:
	GameStateMachine();
	~GameStateMachine();
	void popState();
	void pushState(GameState *);
	void update();
	void render();
private:
	std::stack<GameState *> states_;
};

