#include "PhysicsManager.h"
#include "Collidable.h"
#include "Dynamic.h"
#include <math.h>

void PhysicsManager::Update()
{
	for (unsigned int i = 0; i < physicsObjects.size(); i++) {
		this->physicsObjects[i]->UpdatePhysics();
	}

	for (unsigned int i = 0; i < collidingObjects.size(); i++) {
		Collidable* c1;
		c1 = this->collidingObjects[i];
		for (unsigned int j = i+1; j < collidingObjects.size(); j++) {
			Collidable* c2;
			c2 = this->collidingObjects[j];
			if (c1->getType()==Collidable::CircleCollider
				&&  c2->getType()== Collidable::CircleCollider)
			{
				handleCollision((CircleCollider*)c1, (CircleCollider*)c2);
			}
		}
	}
}

void PhysicsManager::registerBehaviour(Measurable * mes)
{
	this->physicsObjects.push_back(mes);
}

void PhysicsManager::withdrawBehaviour(Measurable * mes)
{
	for (unsigned int i = 0; i < this->physicsObjects.size(); i++) {
		if (this->physicsObjects[i] == mes) {
			this->physicsObjects.erase(this->physicsObjects.begin() + i);
			return;
		}
	}
}

void PhysicsManager::registerBehaviour(Collidable * cld)
{
	this->collidingObjects.push_back(cld);
}

void PhysicsManager::withdrawBehaviour(Collidable * cld)
{
	for (unsigned int i = 0; i < this->collidingObjects.size(); i++) {
		if (this->collidingObjects[i] == cld) {
			this->collidingObjects.erase(this->collidingObjects.begin() + i);
			return;
		}
	}
}

void PhysicsManager::handleCollision(CircleCollider * c1, CircleCollider * c2)
{
	Vector3 sub = c1->gameObject->transform.position - c2->gameObject->transform.position;
	float distance = sub.magnitude();
	float c = c1->getRadius() + c2->getRadius();
	if (distance <= c)
	{
		Vector3 v1, v2, v1_, v2_;
		float mass1, mass2;
		int isDynamic_1, isDynamic_2;
		Dynamic* dc1 = c1->gameObject->getComponment<Dynamic>();
		Dynamic* dc2 = c2->gameObject->getComponment<Dynamic>();
		if (dc1 != nullptr) {
			isDynamic_1 = 1;
			v1 = dc1->velocity;
			mass1 = dc1->mass;
		}
		else
		{
			isDynamic_1 = 0;
			mass1 = 1;
			v1 = Vector3(0, 0, 0);
		}

		if (dc2 != nullptr) {
			isDynamic_2 = 1;
			mass2 = dc2->mass;
			v2 = dc2->velocity;
		}
		else
		{
			isDynamic_2 = 0;
			mass2 = 1;
			v2 = Vector3(0, 0, 0);
		}

		float e = float((c1->e + c2->e) / 2.0);
		float k1 = float((mass1 - e * mass2));
		float k2 = float((1.0 + e)*mass2);
		float k3 = float(1.0 / (mass1 + mass2));
		v1_ = (k1*v1 + k2 * v2)*k3;
		v2_ = e * (v1 - v2) + v1_;


		if (isDynamic_1) {
			dc1->setVelocity(v1_);
			c1->gameObject->transform.position += sub / distance;
		}

		if (isDynamic_2)
		{
			dc2->setVelocity(v2_);
			c1->gameObject->transform.position -= sub / distance;
		}
	}
}


