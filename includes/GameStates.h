#pragma once
#include <iostream>
#include "Obstacle.h"
#include "Player.h"
#include <vector>
#include "ClickButton.h"

class GameState
{
public:
	virtual void update() = 0;
	virtual void render() = 0;
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;
private:
};


class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onExit();
	virtual bool onEnter();
	void pauseGame();
private:
	Player* bird_ = nullptr;
	std::vector<Obstacle*> objects_;
	ClickButton* pauseButton_ = nullptr;
	ClickButton* retryButton_ = nullptr;
	ClickButton* menuButton_ = nullptr;
	bool pause_ = false;
};


class MenuState : public GameState
{
public:
	void update() override;
	void render() override;
	bool onEnter() override;
	bool onExit() override;
private:
	Player* bird_;
};


class GameOverState : public GameState
{
public:
	GameOverState();
	void update() override;
	void render() override;
	bool onEnter() override;
	bool onExit() override;
private:
	ClickButton* retryButton_;
};

