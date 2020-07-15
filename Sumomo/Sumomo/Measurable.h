#pragma once
#include "Behaviour.h"
#include "GameObject.h"

class Measurable: public Behaviour
{
public:
	virtual void UpdatePhysics();

	int simulating;
	float mass;

	void setPosition(Vector3 pos);

	Measurable();
	virtual ~Measurable();
};

