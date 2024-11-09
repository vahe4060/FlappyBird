#include "ClickButton.h"
#include "InputHandler.h"

ClickButton::ClickButton(const LoaderParams* params,const char* path) : GameObject(params) 
{
	TextureManager::instance()->load(path, id);
}

void ClickButton::update()
{
	if (InputHandler::instance()->getMousePos().first > xpos
		&& InputHandler::instance()->getMousePos().first <xpos + width
		&& InputHandler::instance()->getMousePos().second > ypos
		&& InputHandler::instance()->getMousePos().second < ypos + height)
	{
		if (InputHandler::instance()->isMouseButtonDown(0))
		clicked = true;
	}
	else
		clicked = false;
}

void ClickButton::draw()
{
	TextureManager::instance()->draw(id, xpos, ypos, width, height);
}

 ClickButton::~ClickButton()
{
	GameObject::~GameObject();
}