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
	void record(const Vector3& move, int time);
	void printKeyFrame(int track, int time);
	int isValid(int time);

private:
	KeyFrame* findPreFrame(int time);
	KeyFrame* findNextFrame(int time);
	int animation_length;
	KeyFrame* frames;
};

