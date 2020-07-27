#include "Circle.h"

Circle::Circle(float _radius, Color255 penColor, float penSize, Color255 brushColor) :
	VectorGraph(penColor, penSize, brushColor)
{
	this->radius = _radius;
}

Circle::~Circle()
{
}

void Circle::Draw(HDC hDC)
{
	if (!this->visible) {
		return;
	}

	SelectObject(hDC, hPen);
	SelectObject(hDC, hBrush);
	Vector3 pos = this->gameObject->transform.position;
	Ellipse(hDC, int(pos.x - this->radius),
		int(pos.y - this->radius),
		int(pos.x + this->radius),
		int(pos.y + this->radius));
	MoveToEx(hDC, int(pos.x), int(pos.y), NULL);
	LineTo(hDC, int(pos.x), int(pos.y - this->radius));
}
