#include "GameStateMachine.h"

GameStateMachine::~GameStateMachine()
{
	while (!states.empty())
	{
		popState();
	}
}

void GameStateMachine::popState()
{
	if (!states.empty())
	{
		if (states.back()->onExit())
		{
			delete states.back();
			states.pop_back();
		}
	}
}

void GameStateMachine::pushState(GameState* newstate)
{
	states.push_back(newstate);
	states.back()->onEnter();
}

void GameStateMachine::update()
{
	if (!states.empty())
		states.back()->update();
}

void GameStateMachine::render()
{
	if (!states.empty())
		states.back()->render();
}