#pragma once
#include <iostream>
#include "Obstacle.h"
#include "Player.h"
#include <vector>
#include "ClickButton.h"

class gameState
{
public:
	virtual void update() = 0;
	virtual void render() = 0;
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;


private:

};



class PlayState : public gameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onExit();
	virtual bool onEnter();

	void pauseGame();

private:
	player* Player = nullptr;
	std::vector<Obstacle*> objects;

	ClickButton* pauseButton = nullptr;
	ClickButton* retry = nullptr;
	ClickButton* mainMenu = nullptr;

	bool pause = false;
};




class menuState : public gameState
{
public:
	menuState();

	void update() override;
	void render() override;
	bool onEnter() override;
	bool onExit() override;

private:
	player* bird = nullptr;// = new player(new loaderParams(180, 250, 17, 12, "player"));
};




class gameOverState : public gameState
{
public:
	gameOverState();

	void update() override;
	void render() override;
	bool onEnter() override;
	bool onExit() override;


private:

	ClickButton* retry = nullptr;
};

