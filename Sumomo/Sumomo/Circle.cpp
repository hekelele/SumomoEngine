#include "Circle.h"

Circle::Circle(float _radius, Color255 penColor, float penSize, Color255 brushColor) :
	VectorGraph(penColor, penSize, brushColor)
{
	this->radius = _radius;
	this->R = _radius*2;
}

Circle::~Circle()
{
}

void Circle::Draw(Graphics * graphics)
{
	Drawable::Draw(graphics);
	if (!this->visible) {
		return;
	}
	Vector3 pos = this->gameObject->transform.position;
	SolidBrush brush(this->brushColor.rgb());
	Pen pen(this->penColor.rgb(), this->penSize);
	graphics->FillEllipse(&brush, pos.x-this->radius, pos.y - this->radius,this->R, this->R);
	graphics->DrawEllipse(&pen, pos.x - this->radius, pos.y - this->radius,this->R, this->R);
	graphics->DrawLine(&pen, pos.x, pos.y,
		pos.x, pos.y - this->radius);
}