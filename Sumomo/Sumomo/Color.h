#pragma once
#include <windows.h>

struct Color255 {
	int r;
	int g;
	int b;
	int a;

	Color255() {
		this->r = 0;
		this->g = 0;
		this->b = 0;
	}

	Color255(int _r, int _g, int _b) {
		this->r = _r;
		this->g = _g;
		this->b = _b;
	}

	Color rgb() {
		return Color(r, g, b);
	}
};