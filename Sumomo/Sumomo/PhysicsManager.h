#pragma once
#include <vector>
#include "Measurable.h"
#include "CircleCollider.h"

using namespace std;

class PhysicsManager
{
public:
	vector<Measurable*> physicsObjects;
	vector<Collidable*> collidingObjects;
	void Update();
	void registerBehaviour(Measurable* mes);
	void withdrawBehaviour(Measurable* mes);

	void registerBehaviour(Collidable* cld);
	void withdrawBehaviour(Collidable* cld);

	void handleCollision(CircleCollider* c1, CircleCollider* c2);
};

