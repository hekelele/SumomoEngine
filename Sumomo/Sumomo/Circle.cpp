#include "Circle.h"

Circle::Circle(float _radius, Color penColor, float penSize, Color brushColor) :
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

	Ellipse(hDC, int(this->gameObject->transform.position.x - this->radius), 
		int(this->gameObject->transform.position.y - this->radius),
		int(this->gameObject->transform.position.x + this->radius),
		int(this->gameObject->transform.position.y + this->radius));
}
