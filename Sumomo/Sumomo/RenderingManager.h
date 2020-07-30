#pragma once
#include <vector>
#include <Windows.h>
#include "Drawable.h"
#include <Gdiplus.h>
#include "Color.h"
#pragma comment(lib, "Gdiplus.lib")
using namespace Gdiplus;
using namespace std;

class RenderingManager
{
public:
	RenderingManager();
	~RenderingManager();

	vector<Drawable*> renderingObjects;
	int width = 800;
	int height = 600;
	int debugMode = 1;
	void Draw(Gdiplus::Graphics* graphics_);
	void registerBehaviour(Drawable* drw);
	void withdrawBehaviour(Drawable* drw);
	void setBackgroundColor(int r, int g, int b);
private:
	Color255 BackgroundColor;
};

