#include "SpriteGame.h"
#include "SpriteRender.h"
using namespace Sumomo;

#include <iostream>
using namespace std;

SpriteGame::SpriteGame(HINSTANCE hInst, int width, int height):SumomoGame(hInst,width,height)
{
	Bitmap* bit = resLoader.loadImage(L".\\assets\\sumomo.png");
	/*
	GameObject* g = new GameObject();
	SpriteRender* sr = (new SpriteRender(bit))
		->setSize(400,400)
		->setSpriteRect(Rect(0,0,256,256))
		->setPivot(0,0);
	g->appendBehaviour(sr);
	g->transform.position = Vector3(100, 200, 0);

	GameObjectList.push_back(g);
	*/

	GameObject* g2 = new GameObject();
	SpriteRender* sr2 = (new SpriteRender(bit))
		->setSize(100, 100)
		->setSpriteRect(Rect(0, 0, 256, 256))
		->setPivot(0, 0);
	g2->appendBehaviour(sr2);
	g2->transform.rotation = Vector3(0, 0, 0);
	//g2->transform.setParenting(&(g->transform));
	g2->transform.position = Vector3(100, 200, 0);

	GameObjectList.push_back(g2);

}

void SpriteGame::makeGameObjects()
{
}
