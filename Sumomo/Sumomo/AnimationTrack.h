#pragma once
#include "KeyFrame.h"
#include "Transform.h"

class AnimationTrack
{
public:
	Transform* target;

	AnimationTrack(int length=0);
	~AnimationTrack();

	AnimationTrack* setTarget(Transform* nt) { target = nt; return this; }
	Vector3 getLerpAnimation(float time);

private:
	KeyFrame* findPreFrame(int time);
	KeyFrame* findNextFrame(int time);
	int animation_length;
	KeyFrame* frames;
};

