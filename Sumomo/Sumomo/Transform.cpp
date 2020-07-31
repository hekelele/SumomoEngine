#include "Transform.h"
#include "GameObject.h"

Transform::Transform() {
	this->position = Vector3(0, 0, 0);
	this->rotation = Vector3(0, 0, 0);
	this->scale = Vector3(1, 1, 1);
	this->parent = nullptr;
	this->gameObject = nullptr;
}

Transform::Transform(GameObject * gg)
{
	this->position = Vector3(0, 0, 0);
	this->rotation = Vector3(0, 0, 0);
	this->scale = Vector3(1, 1, 1);
	this->parent = nullptr;
	this->gameObject = gg;
}

Transform * Transform::setParenting(Transform * father)
{
	this->parent = father;
	return this;
}

Transform * Transform::setParenting(GameObject * father)
{
	this->parent = &father->transform;
	return this;
}

Vector3 Transform::getAniVector()
{
	return Vector3(this->position.x,this->position.y,this->rotation.z);
}
