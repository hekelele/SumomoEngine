﻿#pragma once
#include <Windows.h>
#include "Behaviour.h"
#include <Gdiplus.h>
#pragma comment(lib, "Gdiplus.lib")
#include "Transform.h"
using namespace Gdiplus;

class Drawable :public Behaviour
{
public:
	virtual void Draw(Graphics* graphic);
	virtual void DrawGizmos(Graphics* graphic);
	int visible;
	int gizmo_visible;
	Drawable();
	virtual ~Drawable();
	virtual void tranformFromParent(Transform* tpointer, Graphics* g);
};

