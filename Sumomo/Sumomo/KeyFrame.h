#pragma once
#include "Vector3.h"
#include <iostream>
using namespace std;

struct KeyFrame
{
	Vector3 data;
	int time;
	int valid;

	KeyFrame() :data(0, 0, 0) { valid = 0; }
	KeyFrame(float xx, float yy, float zz, int t) :data(xx, yy, zz) { valid = 0; time = t; }

	int isValid() {
		if (valid != 1) {
			return 0;
		}
		return 1;
	}

	KeyFrame* setPosition(float xx, float yy) {
		data.x = xx;
		data.y = yy;
		return this;
	}

	KeyFrame* setRotation(float rad) {
		data.z = rad;
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
	if (k2->time - k1->time <= 0.001) {
		rate = 1;
	}
	Vector3 sub(k2->data - k1->data);
	data.x = k1->data.x + sub.x*rate;
	data.y = k1->data.y + sub.y*rate;
	data.z = k1->data.z + sub.z*rate;
	return data;
}


