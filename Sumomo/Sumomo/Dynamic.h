#pragma once
#include "Behaviour.h"
#include "Transform.h"
#include "GameObject.h"
#include "Measurable.h"

class Dynamic: public Measurable
{
public:
	Vector3 velocity;
	Vector3 acceleration;

	int applyGravity;

	void setVelocity(Vector3 velocity);
	void setAcceleration(Vector3 acceleration);

	void UpdatePhysics();

	Dynamic();
	~Dynamic();
};

