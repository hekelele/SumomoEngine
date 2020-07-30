#pragma once
#include "AnimationClip.h"
#include "Behaviour.h"

class Animator:Behaviour
{
public:
	Animator();
	~Animator();

	Animator* newAnimation(int track, int length);
	Animator* registerTransform(Transform* target, int track);

	void Update();

	void Play();
	void Pause();
	void Rewind();
	void Jump(float t);

	void setFrame(float time);

private:
	AnimationClip* ac;
	int track_coun;
	int animation_length;
	int playing;
	float playSpeed;
	float animation_time;
};

