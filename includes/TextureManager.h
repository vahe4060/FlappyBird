#pragma once
#include <unordered_map>
#include "SDL_image.h"


class TextureManager
{
private:
	TextureManager();
	~TextureManager();
public:
	TextureManager(const TextureManager &) = delete;
	TextureManager &operator=(const TextureManager &) = delete;
	static TextureManager* instance();
	SDL_Renderer *getRenderer() { return renderer_; }
	void setRenderer(SDL_Renderer *r) { renderer_ = r; }
	bool load(const char* path, const char* id);
	void erase(const char* id);
	void draw(const char* id, int xpos, int ypos, int width, int height,
			  int frame = 0, int zoom = 1,int rotateAngle = 0);

private:
	std::unordered_map<const char *, SDL_Texture *> textureMap_;
	SDL_Renderer *renderer_;
};

