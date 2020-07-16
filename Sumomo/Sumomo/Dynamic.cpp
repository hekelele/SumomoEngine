#include "Dynamic.h"
#include "constant.h"
#include <iostream>

void Dynamic::setVelocity(Vector3 _velocity)
{
	this->velocity = _velocity;
}

void Dynamic::setAcceleration(Vector3 _acceleration)
{
	this->acceleration = _acceleration;
}

void Dynamic::UpdatePhysics()
{
	if (this->simulating) {
		this->velocity += this->acceleration;
		this->velocity.y += this->applyGravity*G;

		this->gameObject->transform.position += this->velocity;
	}
	
}

Dynamic::Dynamic():Measurable()
{

}

Dynamic::~Dynamic()
{
}
