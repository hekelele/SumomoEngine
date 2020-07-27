#pragma once
#include <Windows.h>
#include "Behaviour.h"
#include "GameObject.h"
#include "Drawable.h"
#include "Color.h"

class VectorGraph: public Drawable
{
public:
	VectorGraph(Color255 penColor, float penSize, Color255 brushColor);
	VectorGraph();
	~VectorGraph();

	float penSize;
	Color255 penColor;
	Color255 brushColor;

	void Draw(Graphics* graphics);
	
};

