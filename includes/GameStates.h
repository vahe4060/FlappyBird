#pragma once
#include <iostream>
#include "Obstacle.h"
#include "Player.h"
#include <vector>
#include "ClickButton.h"


class GameState
{
public:
	GameState() {};
	virtual ~GameState() {};
	virtual void update() = 0;
	virtual void render() = 0;
private:
};

class PlayState : public GameState
{
public:
	PlayState();
	~PlayState();
	virtual void update();
	virtual void render();
	void pauseGame();
private:
	Player bird_;
	std::vector<Obstacle> objects_;
	ClickButton pauseButton_;
	bool pause_ = false;
};

class MenuState : public GameState
{
public:
	MenuState();
	~MenuState();
	void update() override;
	void render() override;
private:
	Player bird_;
};


class GameOverState : public GameState
{
public:
	GameOverState();
	~GameOverState();
	void update() override;
	void render() override;
private:
	ClickButton retryButton_;
};

