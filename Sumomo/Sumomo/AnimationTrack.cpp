#include "AnimationTrack.h"

AnimationTrack::AnimationTrack(int length)
{
	frames = new KeyFrame[length];
	for (int i = 0; i < length; i++) {
		frames[i] = KeyFrame();
	}
}

AnimationTrack::~AnimationTrack()
{
	delete[] frames;
}

Vector3 AnimationTrack::getLerpAnimation(float time)
{
	Vector3 temp;

	KeyFrame* prekf = findPreFrame(int(time));
	KeyFrame* nextkf = findNextFrame(int(time));
	if (prekf == nullptr && nextkf == nullptr) {
		return Vector3();
	}
	else if(prekf!=nullptr && nextkf!=nullptr)
	{
		return lerp(prekf, nextkf, time);
	}
	else if (prekf != nullptr) {
		return prekf->data;
	}
	else {
		return nextkf->data;
	}
}

KeyFrame * AnimationTrack::findPreFrame(int time)
{
	while (time >= 0) {
		if (this->frames[time].valid) {
			return &this->frames[time];
		}
		time--;
	}
	return nullptr;
}

KeyFrame * AnimationTrack::findNextFrame(int time)
{
	while (time < animation_length) {
		if (this->frames[time].valid) {
			return &this->frames[time];
		}
		time++;
	}
	return nullptr;
}
