#pragma once
#include <Windows.h>
#include "Behaviour.h"
#include <Gdiplus.h>
#pragma comment(lib, "Gdiplus.lib")
using namespace Gdiplus;

class Drawable :public Behaviour
{
public:
	virtual void Draw(Graphics* graphic);
	int visible;
	Drawable();
	virtual ~Drawable();
};

