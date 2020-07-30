#pragma once
#include "AnimationTrack.h"
#include "Transform.h"


class AnimationClip
{
public:
	AnimationClip(int track, int frame_length);
	~AnimationClip();
	void registerTranform(Transform* target, int track);
	void animate(float time);

private:
	AnimationTrack* tracks;
	int track_count;
	int animation_length;

	void assignTransform2Track(Transform* target, int track);
};

