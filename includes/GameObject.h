#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include <iostream>

class GameObject
{
public:
	GameObject(int x, int y, int w, int h, const char *id)
		: x_(x)
		, y_(y)
		, width_(w)
		, height_(h)
		, currentFrame_(0)
		, rotateAngle_(0)
		, id_(id)
	{
	}
	virtual ~GameObject()
	{
		TextureManager::instance()->erase(id_);
	}
	virtual void update() = 0;
	virtual void draw() = 0;
	int x() { return x_; }
 	int y() { return y_; }
 	int w() { return width_; }
 	int h() { return height_; }
protected:
	int x_, y_;
	int width_, height_;
	int currentFrame_;
	int rotateAngle_;
	const char *id_;
};

