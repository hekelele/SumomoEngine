#include "SpriteGame.h"
#include "SpriteRender.h"
using namespace Sumomo;

#include <iostream>
using namespace std;

SpriteGame::SpriteGame(HINSTANCE hInst, int width, int height):SumomoGame(hInst,width,height)
{
	Bitmap* bit = resLoader.loadImage(L".\\assets\\sumomo.png");
	Bitmap* bit2 = resLoader.loadImage(L".\\assets\\sumomo.png");
	GameObject* g = new GameObject();
	SpriteRender* sr = new SpriteRender(bit);
	g->appendBehaviour(sr);

	GameObjectList.push_back(g);
}

void SpriteGame::makeGameObjects()
{
}
