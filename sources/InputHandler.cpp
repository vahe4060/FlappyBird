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
	keystate = const_cast<Uint8*>(SDL_GetKeyboardState(NULL));
}

void InputHandler::clear()
{
	for (int i = 0; i < 3; i++)
		MouseButtons[i] = false;
}

std::pair<int, int> InputHandler::getMousePos()
{
	return MousePosition;
}



bool InputHandler::isMouseButtonDown(int buttonNumber)
{
	return MouseButtons[buttonNumber];
}


bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (keystate != nullptr)
	{
		if (keystate[key] == 1)
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
		//SDL_Delay(10);
	}

}

void InputHandler::onMouseMotion(SDL_Event& Event)
{
	MousePosition.first = Event.motion.x;
	MousePosition.second = Event.motion.y;
}

void InputHandler::onMouseButtonDown(SDL_Event& Event)
{
	if (Event.button.button == SDL_BUTTON_LEFT)
	{
		MouseButtons[0] = true;
		return;
	}

	if (Event.button.button == SDL_BUTTON_MIDDLE)
	{
		MouseButtons[1] = true;
		return;
	}

	if (Event.button.button == SDL_BUTTON_RIGHT)
	{
		MouseButtons[2] = true;
		return;
	}
}

void InputHandler::onMouseButtonUp(SDL_Event& Event)
{
	if (Event.button.button == SDL_BUTTON_LEFT)
	{
		MouseButtons[0] = false;
		return;
	}

	if (Event.button.button == SDL_BUTTON_MIDDLE)
	{
		MouseButtons[1] = false;
		return;
	}

	if (Event.button.button == SDL_BUTTON_RIGHT)
	{
		MouseButtons[2] = false;
		return;
	}
}

void InputHandler::onKeyDown(SDL_Event& Event)
{
	if (Event.key.type == SDL_SCANCODE_RIGHT)
	{
		keystate[SDL_SCANCODE_RIGHT] = true;
		return;
	}

	if (Event.key.type == SDL_SCANCODE_LEFT)
	{
		keystate[SDL_SCANCODE_LEFT] = true;
		return;
	}

	if (Event.key.type == SDL_SCANCODE_UP)
	{
		keystate[SDL_SCANCODE_UP] = true;
		return;
	}

	if (Event.key.type == SDL_SCANCODE_DOWN)
	{
		keystate[SDL_SCANCODE_DOWN] = true;
		return;
	}
	//Uint32 key = Event.key.type;
	//keystate[key] = true;

}

void InputHandler::onKeyUp(SDL_Event& Event)
{
	if (Event.key.type == SDL_SCANCODE_RIGHT)
	{
		keystate[SDL_SCANCODE_RIGHT] = false;
		return;
	}

	if (Event.key.type == SDL_SCANCODE_LEFT)
	{
		keystate[SDL_SCANCODE_LEFT] = false;
		return;
	}

	if (Event.key.type == SDL_SCANCODE_UP)
	{
		keystate[SDL_SCANCODE_UP] = false;
		return;
	}

	if (Event.key.type == SDL_SCANCODE_DOWN)
	{
		keystate[SDL_SCANCODE_DOWN] = false;
		return;
	}

	//Uint32 key = Event.key.type;
	//keystate[key] = false;
}


