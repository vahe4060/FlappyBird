#include "GameStateMachine.h"
#include <cassert>

GameStateMachine::GameStateMachine()
{
}

GameStateMachine::~GameStateMachine()
{
	while (!states_.empty()) {
		delete states_.top();
		states_.pop();
	}
}

void GameStateMachine::pushState(GameState *state)
{
	states_.push(state);
}

void GameStateMachine::popState()
{
	assert(!states_.empty());
	delete states_.top();
	states_.pop();
}

void GameStateMachine::update()
{
	assert(!states_.empty());
	states_.top()->update();
}

void GameStateMachine::render()
{
	assert(!states_.empty());
	states_.top()->render();
}
