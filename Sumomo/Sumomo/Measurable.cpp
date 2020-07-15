#include "Measurable.h"
#include "main.h"

void Measurable::UpdatePhysics()
{

}


void Measurable::setPosition(Vector3 pos)
{
	this->gameObject->transform.position = pos;
}

Measurable::Measurable()
{
	this->simulating = 1;
	this->mass = 1;
	phyManager.registerBehaviour(this);
}

Measurable::~Measurable()
{
	phyManager.withdrawBehaviour(this);
}
