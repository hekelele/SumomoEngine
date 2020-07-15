#include "VectorGraph.h"


void VectorGraph::Draw(HDC hDC)
{
	
}

VectorGraph::VectorGraph(Color penColor, float penSize, Color brushColor)
{
	hBrush = CreateSolidBrush(RGB(brushColor.r, brushColor.g, brushColor.b));
	hPen = CreatePen(PS_SOLID, penSize, RGB(penColor.r, penColor.g, penColor.b));
}

VectorGraph::VectorGraph():Drawable()
{
	hBrush = CreateSolidBrush(RGB(255, 255, 255));
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
}

VectorGraph::~VectorGraph()
{
	DeleteObject(hPen);
	DeleteObject(hBrush);
}
