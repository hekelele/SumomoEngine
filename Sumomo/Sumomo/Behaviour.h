#pragma once
#include <Windows.h>

#ifndef BEHAVIOUR
#define BEHAVIOUR


class GameObject;

class Behaviour
{
public:
	Behaviour();
	virtual ~Behaviour();
	GameObject* gameObject;

	virtual void Awake();
	virtual void Start();
	virtual void Update();
};


#endif




