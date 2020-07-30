#include "Animator.h"
#include <iostream>
using namespace std;

Animator::Animator()
{
	this->animation_time = 0;
	this->playSpeed = 1;
	this->playing = 0;
	this->ac = nullptr;
}

Animator::~Animator()
{
	if (ac != nullptr) {
		delete ac;
	}
}

Animator* Animator::newAnimation(int track, int length)
{
	if (ac != nullptr) {
		delete ac;
	}
	ac = new AnimationClip(track, length);
	return this;
}

Animator* Animator::registerTransform(Transform * target, int track)
{
	if (ac != nullptr) {
		ac->registerTranform(target, track);
	}
	else
	{
		cout << "tarck count excessed" << endl;
	}
	return this;
}

void Animator::Update()
{
	if (playing) {
		this->animation_time += float(this->playSpeed / 5.0);
		if (this->animation_time > this->animation_length) {
			this->animation_time -= this->animation_length;
		}
		if (ac != nullptr) {
			ac->animate(this->animation_time);
		}
	}
	
}

void Animator::Play()
{
	this->playing = 1;
}

void Animator::Pause()
{
	this->playing = 0;
}

void Animator::Rewind()
{
	this->animation_time = 0;
}

void Animator::Jump(float t)
{
	this->animation_time = t;
}

void Animator::setFrame(float time)
{
	time = int(time) % this->animation_length + (time - int(time));
	if (ac != nullptr) {
		ac->animate(time);
	}
	
}
