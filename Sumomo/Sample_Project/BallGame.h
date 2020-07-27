#pragma once
#include "SumomoGame.h"
class BallGame :
	public SumomoGame
{
public:
	BallGame(HINSTANCE hInst, int width, int height);
	GameObject* makeBall(float radius, float e, Vector3 beginVelocity, Vector3 beginPosition);
	void makeGameObjects();
};

