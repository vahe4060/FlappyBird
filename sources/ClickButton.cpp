#include "ClickButton.h"
#include "inputHandler.h"

ClickButton::ClickButton(const loaderParams* params,const char* path) : gameObject(params) 
{
	textureManager::instance()->load(path, id);
}

void ClickButton::update()
{
	if (inputHandler::instance()->getMousePos().first > xpos
		&& inputHandler::instance()->getMousePos().first <xpos + width
		&& inputHandler::instance()->getMousePos().second > ypos
		&& inputHandler::instance()->getMousePos().second < ypos + height)
	{
		if (inputHandler::instance()->isMouseButtonDown(0))
		clicked = true;
	}
	else
		clicked = false;
}

void ClickButton::draw()
{
	textureManager::instance()->draw(id, xpos, ypos, width, height);
}

 ClickButton::~ClickButton()
{
	gameObject::~gameObject();
}