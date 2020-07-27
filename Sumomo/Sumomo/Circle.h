#pragma once
#include "VectorGraph.h"
class Circle :
	public VectorGraph
{
public:
	using VectorGraph::VectorGraph;

	Circle(float radius, Color255 penColor, float penSize, Color255 brushColor);
	~Circle();

	float R;
	float radius;

	void Draw(Graphics* graphics);
};

