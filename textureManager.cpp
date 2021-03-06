#include "textureManager.h"
#include <cassert>
#include "game.h"

textureManager::textureManager() 
{
}

textureManager::~textureManager()
{
}

textureManager* textureManager::instance_ = nullptr;

textureManager* textureManager::instance()
{
	if (instance_ == nullptr)
	{
		instance_ = new textureManager();
	}

	assert(instance_);

	return instance_;
}



bool textureManager::load(const char* path, const char* id)
{
	SDL_Surface* tempsurf = nullptr;
	tempsurf = IMG_Load(path);
	if (!tempsurf) return false;

	SDL_Texture* tempTexture = nullptr;
	tempTexture = SDL_CreateTextureFromSurface(game::instance()->getRenderer(), tempsurf);
	if (!tempTexture) return false;

	textureMap[id] = tempTexture;
	SDL_FreeSurface(tempsurf);
	return true;
}

void textureManager::erase(const char* id)
{
	textureMap.erase(id);
}


void textureManager::draw(const char* id, int xpos, int ypos, int width, int height, int frame, int zoom,int rotateAngle)
{
	SDL_Rect srcRect, destRect;

	srcRect.w = width;
	destRect.w = zoom * width;
	srcRect.h = height;
	destRect.h = zoom * height;

	destRect.x = xpos;
	destRect.y = ypos;

	srcRect.y = 0;
	srcRect.x = width * frame;

	
	SDL_RenderCopyEx(game::instance()->getRenderer(), textureMap[id], &srcRect, &destRect, rotateAngle, NULL, SDL_FLIP_NONE);
}