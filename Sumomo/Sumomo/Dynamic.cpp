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
		this->velocity.x += this->acceleration.x;
		this->velocity.y += this->acceleration.y;
		this->velocity.z += this->acceleration.z;

		this->velocity.y += this->applyGravity*G;

		this->gameObject->transform.position.x += this->velocity.x;
		this->gameObject->transform.position.y -= this->velocity.y;
		this->gameObject->transform.position.z += this->velocity.z;
	}
	
}

Dynamic::Dynamic():Measurable()
{

}

Dynamic::~Dynamic()
{
}
