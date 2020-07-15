#pragma once
struct Vector3 {
	float x;
	float y;
	float z;
	Vector3() {
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}
	Vector3(float _x, float _y, float _z) {
		this->x = _x;
		this->y = _y;
		this->z = _z;
	}
};