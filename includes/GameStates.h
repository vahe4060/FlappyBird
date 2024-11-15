#pragma once
#include <iostream>
#include "Obstacle.h"
#include "Player.h"
#include <vector>
#include "ClickButton.h"

class GameStateMachine;

class GameState
{
public:
	GameState(int score, GameStateMachine *parent);
	virtual ~GameState();
	virtual void update() = 0;
	virtual void render() = 0;
	int getScore() { return score_; }
protected:
	int drawScore_(int score, int x, int y, int zoom);
	int score_;
	GameStateMachine *parent_;
};


class PlayState : public GameState
{
public:
	PlayState(GameStateMachine *parent);
	virtual ~PlayState();
	virtual void update() override;
	virtual void render() override;
protected:
	Player bird_;
	std::vector<Obstacle> objects_;
	ClickButton pauseButton_;
	bool pause_;
};


class MenuState : public GameState
{
public:
	static int record_;
	MenuState(GameStateMachine *parent);
	virtual ~MenuState();
	virtual void update() override;
	virtual void render() override;
protected:
	Player bird_;
};


class GameOverState : public GameState
{
public:
	GameOverState(int score, GameStateMachine *parent);
	virtual ~GameOverState();
	virtual void update() override;
	virtual void render() override;
protected:
	ClickButton retryButton_;
	ClickButton menuButton_;
};

