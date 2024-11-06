#pragma once
#include "LoaderParams.h"
#include "SDL.h"
#include "SDL_image.h"
#include "textureManager.h"

class gameObject
{
public:
	gameObject(const loaderParams* params) :
		xpos(params->getX()),
		ypos(params->getY()),
		width(params->width()),
		height(params->heigt()),
		id(params->id()),
		currentFrame(0)
	{
		delete params;
	}

	virtual ~gameObject() 
	{
		textureManager::instance()->erase(id);
	}

	virtual void update() = 0;
	virtual void draw() = 0;
	//virtual void clear() { textureManager::instance()->erase(id); }
	 int getX() { return xpos; }
 	 int getY() { return ypos; }
protected:
	int xpos, ypos;
	int width, height;
	int currentFrame;
	int rotateAngle = 0;
	
	const char* id;
};

