#include "Animator.h"
#include <iostream>
using namespace std;


Animator::Animator(int tracks, int frames)
{
	this->animation_time = 0;
	this->playSpeed = 1;
	this->playing = 0;
	this->ac = nullptr;
	this->track_coun = tracks;
	this->animation_length = frames;
}

Animator::~Animator()
{
	if (ac != nullptr) {
		delete ac;
	}
	targets.clear();
}

Animator* Animator::newAnimation(int track, int length)
{
	if (ac != nullptr) {
		delete ac;
	}
	ac = new AnimationClip(track, length);
	for (unsigned int i = 0; i < targets.size(); i++) {
		ac->registerTranform(targets[i], i);
	}
	return this;
}

Animator* Animator::putOnTrack(Transform * target)
{
	targets.push_back(target);
	return this;
}


void Animator::Update()
{
	if (playing) {
		this->animation_time += float(this->playSpeed / 5.0);
		if (this->animation_time > this->animation_length) {
			this->animation_time = 0;
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

void Animator::addKey2Track(const Vector3& move, int track, int time)
{
	this->ac->record(track, move, time);
}

void Animator::printAnimation()
{
	if (this->ac != nullptr) {
		ac->printAnimation();
	}
}

int Animator::isFrameOnTrackValid(int time, int track)
{
	if (this->ac != nullptr) {
		return ac->isFrameOnTrackValid(time, track);
	}

	return 0;
}
