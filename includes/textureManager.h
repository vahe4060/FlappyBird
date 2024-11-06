#pragma once
#include <map>
#include "SDL_image.h"


class textureManager
{
private:
	textureManager();
	~textureManager();
	static textureManager* instance_;

public:
	static textureManager* instance();

	bool load(const char* path, const char* id);
	void erase(const char* id);

	void draw(const char* id, int xpos, int ypos, int width, int height, int frame = 0, int zoom = 1,int rotateAngle = 0);


private:
	std::map<const char*, SDL_Texture*> textureMap;

};

