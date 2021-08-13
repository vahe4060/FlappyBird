#pragma once
#include "GameObject.h"

class ClickButton: public gameObject
{
public:
	ClickButton(const loaderParams*, const char* );
	virtual ~ClickButton();

	void update() override;
	void draw() override;
	//void clear() override;
	
	bool clicked = false;
};

