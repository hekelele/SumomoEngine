#pragma once
#include <Windows.h>
#include "Behaviour.h"
#include "GameObject.h"
#include "Drawable.h"
#include "Color.h"

class VectorGraph: public Drawable
{
public:
	VectorGraph(Color penColor, float penSize, Color brushColor);
	VectorGraph();
	~VectorGraph();

	HPEN hPen;
	HBRUSH hBrush;

	void Draw(HDC hDC);
	
};

