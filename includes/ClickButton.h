#pragma once
#include "GameObject.h"

class ClickButton: public GameObject
{
public:
	ClickButton(int x, int y, int w, int h, const char* id, const char *path);
	virtual ~ClickButton();
	void update() override;
	void draw() override;
	bool clicked() { return clicked_; }
private:
	bool clicked_;
};
