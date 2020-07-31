#pragma once
#include "Vector3.h"

class GameObject;

#ifndef TRANSFORM
#define TRANSFORM

struct Transform
{
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

	Transform* parent;

	Transform();
	Transform(GameObject* gg);
	
	Transform* setParenting(Transform* father);
	Transform* setParenting(GameObject* father);
	GameObject* gameObject;

	Vector3 getAniVector();
};

#endif
