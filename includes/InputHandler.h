#pragma once

#include <iostream>
#include <SDL.h>

class InputHandler
{
private:
	static InputHandler* instance_;
	InputHandler();
	~InputHandler();
public:
	static InputHandler* instance();

	void update();
	void clear();

	bool isKeyDown(SDL_Scancode key);
	bool isMouseButtonDown(int buttonNumber);
	std::pair<int, int> getMousePos();

private:

	bool MouseButtons[3];
	Uint8* keystate = nullptr;
	std::pair<int, int> MousePosition;


	void onKeyDown(SDL_Event&);
	void onKeyUp(SDL_Event&);
	void onMouseButtonDown(SDL_Event&);
	void onMouseButtonUp(SDL_Event&);
	void onMouseMotion(SDL_Event&);
};

