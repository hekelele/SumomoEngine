#pragma once
#include "Vector3.h"

struct KeyFrame
{
	Vector3 data;
	int time;
	int valid;

	KeyFrame() :data(0,0,0) { valid = 0; }
	KeyFrame(float xx, float yy, float zz) :data(xx, yy, zz) { valid = 1; }

	KeyFrame* setPosition(float xx, float yy) {
		data.x = xx;
		data.y = yy;
		valid = 1;
		return this;
	}

	KeyFrame* setRotation(float rad) {
		data.z = rad;
		valid = 1;
		return this;
	}

	KeyFrame* validate() {
		valid = 1;
		return this;
	}

	KeyFrame* invalidate() {
		valid = 0;
		data = Vector3(0, 0, 0);
		return this;
	}
};

inline Vector3 lerp(KeyFrame* k1, KeyFrame* k2, float v) {
	Vector3 data;
	float rate = (v - k1->time) / (k2->time - k1->time);
	Vector3 sub(k2->data - k1->data);
	data.x = k1->data.x + sub.x*rate;
	data.y = k2->data.y + sub.y*rate;
	data.z = k2->data.z + sub.z*rate;
	return data;
}


