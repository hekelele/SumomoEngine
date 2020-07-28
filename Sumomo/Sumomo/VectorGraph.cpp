#include "VectorGraph.h"


VectorGraph::VectorGraph(Color255 penColor, float penSize, Color255 brushColor)
{
	this->penColor = penColor;
	this->penSize = penSize;
	this->brushColor = brushColor;

}

VectorGraph::VectorGraph():Drawable()
{
	this->penColor = Color255(0, 0, 0);
	this->penSize = 1;
	this->brushColor = Color255(255, 255, 255);
}

VectorGraph::~VectorGraph()
{
}

void VectorGraph::Draw(Graphics * graphics)
{
	Drawable::Draw(graphics);
}
