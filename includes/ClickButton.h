#pragma once
#include "GameObject.h"

class ClickButton: public GameObject
{
public:
	ClickButton(const LoaderParams*, const char* );
	virtual ~ClickButton();

	void update() override;
	void draw() override;
	//void clear() override;
	
	bool clicked = false;
};

