#pragma once

#include <iostream>
#include <SDL.h>

class InputHandler
{
private:
	InputHandler();
	~InputHandler();
public:
	InputHandler(const InputHandler &) = delete;
	InputHandler &operator=(const InputHandler &) = delete;
	static InputHandler *instance();
	void update();
	void reset();
	bool isKeyDown(SDL_Scancode key);
	bool isMouseButtonDown(int buttonNumber);
	std::pair<int, int> getMousePos();

private:
	bool mouseButtons_[3];
	Uint8 *keyState_;
	std::pair<int, int> mousePosition_;
	void onKeyDown(SDL_Event&);
	void onKeyUp(SDL_Event&);
	void onMouseButtonDown(SDL_Event&);
	void onMouseButtonUp(SDL_Event&);
	void onMouseMotion(SDL_Event&);
};

