#pragma once
#include "BorderConstrain.h"

class BallFactry
{
public:
	static GameObject* makeBall(float radius,float e, Vector3 beginVelocity, Vector3 beginPosition);
};

