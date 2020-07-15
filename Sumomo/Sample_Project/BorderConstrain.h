#pragma once
#include <math.h>
#include <Windows.h>
#include "Dynamic.h"
#include "Circle.h"

class BorderConstrain: public Behaviour
{
public:

	BorderConstrain(int width, int height);
	~BorderConstrain();

	void Start();
	void Update();

private:
	Dynamic* dc;
	Circle* cc;
	int width;
	int height;
};

