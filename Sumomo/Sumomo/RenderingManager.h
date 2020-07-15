#pragma once
#include <vector>
#include <Windows.h>
#include "Drawable.h"
using namespace std;

class RenderingManager
{
public:
	vector<Drawable*> renderingObjects;
	HDC currentHDC;
	int width = 800;
	int height = 600;
	void Draw(HDC hDC);
	void registerBehaviour(Drawable* drw);
	void withdrawBehaviour(Drawable* drw);
};

