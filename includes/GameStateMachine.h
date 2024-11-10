#pragma once
#include "GameStates.h"
#include <iostream>
#include <vector>

class GameStateMachine
{
public:
	~GameStateMachine();
	void popState();
	void pushState(GameState *);
	void update();
	void render();
private:
	std::vector<GameState *> states_;
};

