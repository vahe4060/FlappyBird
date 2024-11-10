#include "TextureManager.h"
#include <cassert>
#include "Game.h"

TextureManager::TextureManager() 
{
}

TextureManager::~TextureManager()
{
}

TextureManager* TextureManager::instance_ = nullptr;

TextureManager* TextureManager::instance()
{
	if (instance_ == nullptr)
	{
		instance_ = new TextureManager();
	}

	assert(instance_);

	return instance_;
}

void TextureManager::clearAll()
{
	erase("background");
	erase("button");
	erase("numbers");
}

bool TextureManager::load(const char* path, const char* id)
{
	SDL_Surface* tempSurf = nullptr;
	tempSurf = IMG_Load(path);
	if (!tempSurf) return false;

	SDL_Texture* tempTexture = nullptr;
	tempTexture = SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), tempSurf);
	if (!tempTexture) return false;

	textureMap_[id] = tempTexture;
	SDL_FreeSurface(tempSurf);
	return true;
}

void TextureManager::erase(const char* id)
{
	textureMap_.erase(id);
}


void TextureManager::draw(const char* id, int xpos, int ypos, int width, 
						  int height, int frame, int zoom,int rotateAngle)
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

	
	SDL_RenderCopyEx(Game::instance()->getRenderer(), textureMap_[id], &srcRect,
					 &destRect, rotateAngle, NULL, SDL_FLIP_NONE);
}