#pragma once
#include "Collidable.h"
class CircleCollider : public Collidable
{
public:
	CircleCollider();
	~CircleCollider();

	void Start();
	void  setRadius(float f);
	float getRadius() { return radius; }
protected:
	float radius;
	int initialized;
};

