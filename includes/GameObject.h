#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"

class GameObject
{
public:
	GameObject(int x, int y, int w, int h, const char* id) :
		x_(x),
		y_(y),
		width_(w),
		height_(h),
		id_(id),
		currentFrame_(0),
		rotateAngle_(0)
	{
	}

	virtual ~GameObject() 
	{
		TextureManager::instance()->erase(id_);
	}

	virtual void update() = 0;
	virtual void draw() = 0;
	//virtual void clear() { TextureManager::instance()->erase(id); }
	virtual int x() { return x_; }
 	virtual int y() { return y_; }
protected:
	int x_, y_;
	int width_, height_;
	int currentFrame_;
	int rotateAngle_;
	const char* id_;
};

