#include "AnimationClip.h"
#include <iostream>

using namespace std;

AnimationClip::AnimationClip(int track, int frame_length)
{
	this->tracks = new AnimationTrack[track];
	for (int i = 0; i < track; i++) {
		this->tracks[i] = AnimationTrack(frame_length);
	}
	this->track_count = track;
	this->animation_length = frame_length;
}

AnimationClip::~AnimationClip()
{
	delete[] tracks;
}

void AnimationClip::registerTranform(Transform * target, int track)
{
	assignTransform2Track(target, track);
}

void AnimationClip::animate(float time)
{
	for (int i = 0; i < track_count; i++) {
		AnimationTrack* at = &this->tracks[i];
		if (at->target != nullptr) {
			Vector3 data = at->getLerpAnimation(time);
			at->target->position = Vector3(data.x, data.y, 0);
			at->target->rotation = Vector3(0, 0, data.z);
		}
	}
}

void AnimationClip::assignTransform2Track(Transform * target, int track)
{
	if (track > this->track_count) {
		cout << "Track num excesseed" << endl;
		return;
	}
	else
	{
		this->tracks[track].setTarget(target);
	}
}
