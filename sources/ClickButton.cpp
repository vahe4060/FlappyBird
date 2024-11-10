#include "ClickButton.h"
#include "InputHandler.h"

ClickButton::ClickButton(int x, int y, int w, int h, const char* id, const char* path)
			: GameObject(x, y, w, h, id)
{
	clicked_ = false;
	TextureManager::instance()->load(path, id_);
}

void ClickButton::update()
{
	if (InputHandler::instance()->getMousePos().first > x_
		&& InputHandler::instance()->getMousePos().first <x_ + width_
		&& InputHandler::instance()->getMousePos().second > y_
		&& InputHandler::instance()->getMousePos().second < y_ + height_)
	{
		if (InputHandler::instance()->isMouseButtonDown(0))
		clicked_ = true;
	}
	else
		clicked_ = false;
}

void ClickButton::draw()
{
	TextureManager::instance()->draw(id_, x_, y_, width_, height_);
}

 ClickButton::~ClickButton()
{
	GameObject::~GameObject();
}