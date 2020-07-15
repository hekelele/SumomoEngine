#pragma once
#include <Windows.h>
#include "Behaviour.h"

class Drawable :public Behaviour
{
public:
	virtual void Draw(HDC hDC);
	int visible;
	Drawable();
	virtual ~Drawable();
};

