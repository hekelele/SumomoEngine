#include "BorderConstrain.h"

BorderConstrain::BorderConstrain(int _width, int _height)
{
	this->width = _width;
	this->height = _height;
}

BorderConstrain::~BorderConstrain()
{
}

void BorderConstrain::Start()
{
	this->dc = this->gameObject->getComponment<Dynamic>();
	this->cc = this->gameObject->getComponment<Circle>();
}

void BorderConstrain::Update()
{
	Vector3 p;
	p = this->gameObject->transform.position;
	if (p.x - cc->radius < 0) {
		dc->velocity.x = -dc->velocity.x;
		dc->setPosition(Vector3(cc->radius, p.y, p.z));
		
	}else if(p.x + cc->radius > width) {
		dc->velocity.x = -dc->velocity.x;
		dc->setPosition(Vector3(width - cc->radius, p.y, p.z));
	}
	if (p.y - cc->radius<0) {
		dc->velocity.y = -dc->velocity.y;
		dc->setPosition(Vector3(p.x, cc->radius, p.z));
	}
	else if(p.y + cc->radius > height)
	{
		dc->velocity.y = -dc->velocity.y;
		dc->setPosition(Vector3(p.x, height - cc->radius, p.z));
	}
}
