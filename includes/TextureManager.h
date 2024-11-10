#pragma once
#include <map>
#include "SDL_image.h"


class TextureManager
{
private:
	TextureManager();
	~TextureManager();
	static TextureManager* instance_;

public:
	static TextureManager* instance();
	SDL_Renderer *getRenderer() { return renderer_; }
	void setRenderer(SDL_Renderer *r) { renderer_ = r; }
	void eraseAll();
	bool load(const char* path, const char* id);
	void erase(const char* id);
	void draw(const char* id, int xpos, int ypos, int width, int height,
			  int frame = 0, int zoom = 1,int rotateAngle = 0);

private:
	std::map<const char *, SDL_Texture *> textureMap_;
	SDL_Renderer *renderer_;
};

