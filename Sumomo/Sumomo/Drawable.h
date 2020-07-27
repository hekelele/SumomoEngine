#pragma once
#include <Windows.h>
#include "Behaviour.h"
#include <gdiplus.h>

class Drawable :public Behaviour
{
public:
	virtual void Draw(HDC hDC);
	int visible;
	Drawable();
	virtual ~Drawable();
};

