#pragma once
#include "SumomoGame.h"

class SpriteGame :
	public SumomoGame
{
public:
	SpriteGame(HINSTANCE hInst, int width, int height);
	void makeGameObjects();
};

