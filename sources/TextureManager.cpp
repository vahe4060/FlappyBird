#include "TextureManager.h"
#include <cassert>
#include "Game.h"

TextureManager::TextureManager() 
	: renderer_(nullptr)
{
}

TextureManager::~TextureManager()
{
	for(auto &it: textureMap_)
		SDL_DestroyTexture(it.second);
	textureMap_.clear();
}

TextureManager *TextureManager::instance()
{
	static TextureManager instance_;
	return &instance_;
}

bool TextureManager::load(const char *path, const char *id)
{
	assert(renderer_);
	SDL_Surface *tempSurf = IMG_Load(path);
	textureMap_[id] = SDL_CreateTextureFromSurface(renderer_, tempSurf);
	SDL_FreeSurface(tempSurf);
	return (textureMap_[id] != NULL);
}

void TextureManager::erase(const char* id)
{
	SDL_DestroyTexture(textureMap_[id]);
	textureMap_.erase(id);
}

void TextureManager::draw(const char* id, int x, int y, int w, int h, 
						  int frame, int zoom, int rotateAngle)
{
	assert(renderer_);
	assert(textureMap_[id]);
	SDL_Rect srcRect = {.x = w * frame, .y = 0, .w = w, .h = h};
	SDL_Rect destRect = {.x = x, .y = y, .w = zoom * w, .h = zoom * h};
	SDL_RenderCopyEx(renderer_, textureMap_[id], &srcRect, &destRect,
					 rotateAngle, NULL, SDL_FLIP_NONE);
}
