#include "gameStateMachine.h"

gameStateMachine::~gameStateMachine()
{
	while (!states.empty())
	{
		popState();
	}
}


void gameStateMachine::popState()
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

void gameStateMachine::pushState(gameState* newstate)
{
	states.push_back(newstate);
	states.back()->onEnter();
}

void gameStateMachine::update()
{
	if (!states.empty())
		states.back()->update();
}

void gameStateMachine::render()
{
	if (!states.empty())
		states.back()->render();
}