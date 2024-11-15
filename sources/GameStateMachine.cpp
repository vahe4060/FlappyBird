#include "GameStateMachine.h"
#include <cassert>

GameStateMachine::GameStateMachine()
{
}

GameStateMachine::~GameStateMachine()
{
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

void GameStateMachine::start()
{
	pushState(new MenuState(this));
}

void GameStateMachine::stop()
{
	while (!states_.empty()) {
		delete states_.top();
		states_.pop();
	}
}

void GameStateMachine::newPlayState()
{
	popState();
	pushState(new PlayState(this));
}

void GameStateMachine::newGameOverState(int score)
{
	popState();
	pushState(new GameOverState(score, this));
	if (score > MenuState::record_)
		MenuState::record_ = score;
}

void GameStateMachine::newMenuState()
{
	popState();
	pushState(new MenuState(this));
}

