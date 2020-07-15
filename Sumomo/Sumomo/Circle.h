#pragma once
#include "VectorGraph.h"
class Circle :
	public VectorGraph
{
public:
	using VectorGraph::VectorGraph;

	Circle(float radius, Color penColor, float penSize, Color brushColor);
	~Circle();

	float radius;

	void Draw(HDC hDC);
};

