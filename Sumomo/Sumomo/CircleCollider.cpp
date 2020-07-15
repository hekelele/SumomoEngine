#include "CircleCollider.h"
#include "Circle.h"


CircleCollider::CircleCollider():Collidable()
{
	this->initialized = 0;
}

CircleCollider::~CircleCollider()
{
}

void CircleCollider::Start()
{
	if (!initialized) {
		this->type = Collidable::CircleCollider;
		Circle* c = this->gameObject->getComponment<Circle>();
		if (c != nullptr) {
			this->radius = c->radius;
		}
		else
		{
			this->radius = 1;
		}
	}
}

void CircleCollider::setRadius(float f)
{
	this->radius = f;
	this->initialized = 1;
}
