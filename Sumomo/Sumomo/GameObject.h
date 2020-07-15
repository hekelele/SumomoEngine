#pragma once
#include <vector>
#include "Transform.h"
#include <iostream>
using namespace std;

#ifndef GAMEOBJECT
#define GAMEOBJECT

class Behaviour;

class GameObject
{
public:
	vector<Behaviour*> componments;
	Transform transform;

	GameObject();
	virtual ~GameObject();

	virtual void Awake();
	virtual void Start();
	virtual void Update();

	template<typename T>
	T* getComponment();


	void appendBehaviour(Behaviour* beh);
};

#endif // !GAMEOBJECT


template<typename T>
inline T* GameObject::getComponment()
{
	for (unsigned int i = 0; i < componments.size(); i++) {
		if (typeid(T) == typeid(*componments[i])) {
			return (T*)componments[i];
		}
	}
	return nullptr;
}