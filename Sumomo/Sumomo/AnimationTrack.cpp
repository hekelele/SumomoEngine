#include "AnimationTrack.h"
#include <iostream>
using namespace std;

AnimationTrack::AnimationTrack(int length)
{
	frames = new KeyFrame[length];
	for (int i = 0; i < length; i++) {
		frames[i] = KeyFrame();
	}
	animation_length = length;
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

void AnimationTrack::record(const Vector3 & move, int time)
{
	Vector3 vn = move;
	this->frames[time] = KeyFrame(vn.x, vn.y, vn.z, time);
	this->frames[time].validate();
}

void AnimationTrack::printKeyFrame(int track, int time)
{
	
	if (this->frames[time].isValid()) {
		Vector3 vp = this->frames[time].data;
		cout << "saveKey(" << track << "," << time << ","
			<< vp.x << "," << vp.y << "," << vp.z << ");" << endl;
	}
	
}

int AnimationTrack::isValid(int time)
{
	return this->frames[time].isValid();
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
