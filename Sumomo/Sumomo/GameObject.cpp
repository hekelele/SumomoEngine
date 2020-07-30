#include "GameObject.h"
#include "Behaviour.h"
#include <iostream>
using namespace std;

GameObject::GameObject()
{
	this->transform = Transform(this);
}

GameObject::~GameObject()
{
	for (unsigned int i = 0; i < this->componments.size(); i++) {
		delete this->componments[i];
	}
	this->componments.clear();
}

void GameObject::Awake()
{
	for (unsigned int i = 0; i < this->componments.size(); i++) {
		this->componments[i]->Awake();
	}
}

void GameObject::Start()
{
	for (unsigned int i = 0; i < this->componments.size(); i++) {
		this->componments[i]->Start();
	}
}

void GameObject::Update()
{
	for (unsigned int i = 0; i < this->componments.size(); i++) {
		this->componments[i]->Update();
	}
}

void GameObject::appendBehaviour(Behaviour* beh)
{
	this->componments.push_back(beh);
	beh->gameObject = this;
}
