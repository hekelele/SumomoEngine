#pragma once
#include "AnimationClip.h"
#include "Behaviour.h"
#include <vector>

class Animator:public Behaviour
{
public:
	Animator(int tracks, int frames);
	~Animator();

	Animator* newAnimation(int track, int length);
	Animator* putOnTrack(Transform* target);

	void Update();

	void Play();
	void Pause();
	void Rewind();
	void Jump(float t);

	void setFrame(float time);

	void addKey2Track(const Vector3& move, int track, int time);

	void printAnimation();

	int isFrameOnTrackValid(int time, int track);


	inline int hasClip() { return ac != nullptr; }
	inline float getTime() { return animation_time; }

private:
	AnimationClip* ac;
	int track_coun;
	int animation_length;
	int playing;
	float playSpeed;
	float animation_time;
	vector<Transform*> targets;
};

