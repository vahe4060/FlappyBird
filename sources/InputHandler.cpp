#include "InputHandler.h"
#include <cassert>
#include "Game.h"


InputHandler* InputHandler::instance_ = nullptr;

InputHandler* InputHandler::instance()
{
	if (instance_ == nullptr)
		instance_ = new InputHandler();

	return instance_;
}

InputHandler::~InputHandler()
{
	std::cout << "\n\ninput handler went out of scope....\n\n";
}

InputHandler::InputHandler()
{
	clear();
	keyState_ = const_cast<Uint8*>(SDL_GetKeyboardState(NULL));
}

void InputHandler::clear()
{
	for (int i = 0; i < 3; i++)
		mouseButtons_[i] = false;
}

std::pair<int, int> InputHandler::getMousePos()
{
	return mousePosition_;
}

bool InputHandler::isMouseButtonDown(int buttonNumber)
{
	return mouseButtons_[buttonNumber];
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (keyState_ != nullptr)
	{
		if (keyState_[key] == 1)
			return true;
		else
			return false;
	}
	return false;
}



void InputHandler::update()
{
	SDL_Event Event;

	while (SDL_PollEvent(&Event))
	{
		switch (Event.type)
		{
		case SDL_MOUSEBUTTONUP:
		{
			onMouseButtonUp(Event);  break;
		}
		case SDL_MOUSEBUTTONDOWN:
		{
			onMouseButtonDown(Event); break;
		}
		case SDL_MOUSEMOTION:
		{
			onMouseMotion(Event); break;
		}
		case SDL_KEYDOWN:
		{
			onKeyDown(Event); break;
		}
		case SDL_KEYUP:
		{
			onKeyUp(Event); break;
		}

		case SDL_QUIT:
		{
			Game::instance()->quit(); break;
		}
		default:
			break;
		}
	}

}

void InputHandler::onMouseMotion(SDL_Event& Event)
{
	mousePosition_.first = Event.motion.x;
	mousePosition_.second = Event.motion.y;
}

void InputHandler::onMouseButtonDown(SDL_Event& Event)
{
	if (Event.button.button == SDL_BUTTON_LEFT)
	{
		mouseButtons_[0] = true;
		return;
	}
	if (Event.button.button == SDL_BUTTON_MIDDLE)
	{
		mouseButtons_[1] = true;
		return;
	}
	if (Event.button.button == SDL_BUTTON_RIGHT)
	{
		mouseButtons_[2] = true;
		return;
	}
}

void InputHandler::onMouseButtonUp(SDL_Event& Event)
{
	if (Event.button.button == SDL_BUTTON_LEFT)
	{
		mouseButtons_[0] = false;
		return;
	}
	if (Event.button.button == SDL_BUTTON_MIDDLE)
	{
		mouseButtons_[1] = false;
		return;
	}
	if (Event.button.button == SDL_BUTTON_RIGHT)
	{
		mouseButtons_[2] = false;
		return;
	}
}

void InputHandler::onKeyDown(SDL_Event& Event)
{
	if (Event.key.type == SDL_SCANCODE_RIGHT)
	{
		keyState_[SDL_SCANCODE_RIGHT] = true;
		return;
	}
	if (Event.key.type == SDL_SCANCODE_LEFT)
	{
		keyState_[SDL_SCANCODE_LEFT] = true;
		return;
	}
	if (Event.key.type == SDL_SCANCODE_UP)
	{
		keyState_[SDL_SCANCODE_UP] = true;
		return;
	}
	if (Event.key.type == SDL_SCANCODE_DOWN)
	{
		keyState_[SDL_SCANCODE_DOWN] = true;
		return;
	}
	//Uint32 key = Event.key.type;
	//keyState_[key] = true;
}

void InputHandler::onKeyUp(SDL_Event& Event)
{
	if (Event.key.type == SDL_SCANCODE_RIGHT)
	{
		keyState_[SDL_SCANCODE_RIGHT] = false;
		return;
	}
	if (Event.key.type == SDL_SCANCODE_LEFT)
	{
		keyState_[SDL_SCANCODE_LEFT] = false;
		return;
	}
	if (Event.key.type == SDL_SCANCODE_UP)
	{
		keyState_[SDL_SCANCODE_UP] = false;
		return;
	}
	if (Event.key.type == SDL_SCANCODE_DOWN)
	{
		keyState_[SDL_SCANCODE_DOWN] = false;
		return;
	}
	//Uint32 key = Event.key.type;
	//keyState_[key] = false;
}


