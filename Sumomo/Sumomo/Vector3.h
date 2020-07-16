#pragma once
#include <math.h>

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

	Vector3 operator+(const Vector3& another) {
		Vector3 v3;
		v3.x = this->x + another.x;
		v3.y = this->y + another.y;
		v3.z = this->z + another.z;
		return v3;
	}

	Vector3 operator+=(const Vector3& another) {
		Vector3 v3;
		v3.x = this->x += another.x;
		v3.y = this->y += another.y;
		v3.z = this->z += another.z;
		return v3;
	}

	Vector3 operator-(const Vector3& another) {
		Vector3 v3;
		v3.x = this->x - another.x;
		v3.y = this->y - another.y;
		v3.z = this->z - another.z;
		return v3;
	}

	Vector3 operator-=(const Vector3& another) {
		Vector3 v3;
		v3.x = this->x -= another.x;
		v3.y = this->y -= another.y;
		v3.z = this->z -= another.z;
		return v3;
	}

	Vector3 operator*(const int& scalar) {
		Vector3 v3;
		v3.x = this->x  * scalar;
		v3.y = this->y  * scalar;
		v3.z = this->z  * scalar;
		return v3;
	}

	Vector3 operator*(const float& scalar) {
		Vector3 v3;
		v3.x = this->x  * scalar;
		v3.y = this->y  * scalar;
		v3.z = this->z  * scalar;
		return v3;
	}

	Vector3 operator*(const double& scalar) {
		Vector3 v3;
		v3.x = float(this->x  * scalar);
		v3.y = float(this->y  * scalar);
		v3.z = float(this->z  * scalar);
		return v3;
	}


	friend Vector3 operator*(const int& scalar, Vector3 vec) {
		Vector3 v3;
		v3.x = vec.x  * scalar;
		v3.y = vec.y  * scalar;
		v3.z = vec.z  * scalar;
		return v3;
	}


	friend Vector3 operator*(const float& scalar, Vector3 vec) {
		Vector3 v3;
		v3.x = vec.x  * scalar;
		v3.y = vec.y  * scalar;
		v3.z = vec.z  * scalar;
		return v3;
	}

	friend Vector3 operator*(const double& scalar, Vector3 vec) {
		Vector3 v3;
		v3.x = float(vec.x  * scalar);
		v3.y = float(vec.y  * scalar);
		v3.z = float(vec.z  * scalar);
		return v3;
	}

	Vector3 operator*=(const int& scalar) {
		Vector3 v3;
		float v = (float)scalar;
		v3.x = this->x *= v;
		v3.y = this->y *= v;
		v3.z = this->z *= v;
		return v3;
	}

	Vector3 operator*=(const float& scalar) {
		Vector3 v3;
		v3.x = this->x  *= scalar;
		v3.y = this->y  *= scalar;
		v3.z = this->z  *= scalar;
		return v3;
	}

	Vector3 operator*=(const double& scalar) {
		Vector3 v3;
		float v = (float)scalar;
		v3.x = this->x  *= v;
		v3.y = this->y  *= v;
		v3.z = this->z  *= v;
		return v3;
	}

	Vector3 operator/(const int& scalar) {
		Vector3 v3;
		v3.x = this->x  / scalar;
		v3.y = this->y  / scalar;
		v3.z = this->z  / scalar;
		return v3;
	}

	Vector3 operator/(const float& scalar) {
		Vector3 v3;
		v3.x = this->x  / scalar;
		v3.y = this->y  / scalar;
		v3.z = this->z  / scalar;
		return v3;
	}

	Vector3 operator/(const double& scalar) {
		Vector3 v3;
		v3.x = float(this->x  / scalar);
		v3.y = float(this->y  / scalar);
		v3.z = float(this->z  / scalar);
		return v3;
	}

	friend Vector3 operator/(const int& scalar, Vector3 vec) {
		Vector3 v3;
		v3.x = vec.x  / scalar;
		v3.y = vec.y  / scalar;
		v3.z = vec.z  / scalar;
		return v3;
	}

	friend Vector3 operator/(const float& scalar, Vector3 vec) {
		Vector3 v3;
		v3.x = vec.x  / scalar;
		v3.y = vec.y  / scalar;
		v3.z = vec.z  / scalar;
		return v3;
	}

	friend Vector3 operator/(const double& scalar, Vector3 vec) {
		Vector3 v3;
		v3.x = float(vec.x  / scalar);
		v3.y = float(vec.y  / scalar);
		v3.z = float(vec.z  / scalar);
		return v3;
	}

	Vector3 operator/=(const int& scalar) {
		Vector3 v3;
		float v = (float)scalar;
		v3.x = this->x /= v;
		v3.y = this->y /= v;
		v3.z = this->z /= v;
		return v3;
	}

	Vector3 operator/=(const float& scalar) {
		Vector3 v3;
		v3.x = this->x /= scalar;
		v3.y = this->y /= scalar;
		v3.z = this->z /= scalar;
		return v3;
	}

	Vector3 operator/=(const double& scalar) {
		Vector3 v3;
		float v = (float)scalar;
		v3.x = this->x /= v;
		v3.y = this->y /= v;
		v3.z = this->z /= v;
		return v3;
	}

	static float distanceSqure(Vector3& a, Vector3&b) {
		Vector3 v3 = a - b;
		return (v3.x*v3.x) + (v3.y*v3.y) + (v3.z*v3.z);
	}

	static float distance(Vector3& a, Vector3&b) {
		return sqrtf(distanceSqure(a, b));
	}

	float magnitudeSqure() {
		return (this->x*this->x) + (this->y*this->y) + (this->z*this->z);
	}

	float magnitude(){
		return sqrtf(magnitudeSqure());
	}
};