#pragma once
#include <iostream>
#include "Obstacle.h"
#include "Player.h"
#include <vector>
#include "ClickButton.h"

class Game;


class GameState
{
public:
	GameState(int score, Game *parent);
	virtual ~GameState();
	virtual void update() = 0;
	virtual void render() = 0;
	int getScore() { return score_; }
protected:
	void drawScore_(int zoom, int x, int y);
	int score_;
	Game *parent_;
};


class PlayState : public GameState
{
public:
	PlayState(Game *parent);
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
	MenuState(int record, Game *parent);
	virtual ~MenuState();
	virtual void update() override;
	virtual void render() override;
protected:
	Player bird_;
};


class GameOverState : public GameState
{
public:
	GameOverState(int score, Game *parent);
	virtual ~GameOverState();
	virtual void update() override;
	virtual void render() override;
protected:
	ClickButton retryButton_;
};

