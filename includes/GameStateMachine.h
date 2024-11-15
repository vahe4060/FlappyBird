#pragma once
#include "GameStates.h"
#include <iostream>
#include <stack>


class GameStateMachine
{
public:
	GameStateMachine();
	~GameStateMachine();
	void start();
	void stop();
	void newPlayState();
	void newGameOverState(int score);
	void newMenuState();
	void update();
	void render();
private:
	void popState();
	void pushState(GameState *);
private:
	std::stack<GameState *> states_;
};

