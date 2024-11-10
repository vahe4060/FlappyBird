#include "GameStateMachine.h"

GameStateMachine::~GameStateMachine()
{
	while (!states_.empty())
	{
		popState();
	}
}

void GameStateMachine::popState()
{
	if (!states_.empty())
	{
		if (states_.back()->onExit())
		{
			delete states_.back();
			states_.pop_back();
		}
	}
}

void GameStateMachine::pushState(GameState* newstate)
{
	states_.push_back(newstate);
	states_.back()->onEnter();
}

void GameStateMachine::update()
{
	if (!states_.empty())
		states_.back()->update();
}

void GameStateMachine::render()
{
	if (!states_.empty())
		states_.back()->render();
}