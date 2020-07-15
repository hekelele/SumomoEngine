#pragma once
#include "Behaviour.h"

class Collidable : public Behaviour
{
public:
	enum ColliderType
	{
		CircleCollider,
		RectangleCollider,
		None
	};

	Collidable();
	virtual ~Collidable();

	ColliderType getType();

	float e;

protected:
	ColliderType type;

};

