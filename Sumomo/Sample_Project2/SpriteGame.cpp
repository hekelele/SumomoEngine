#include "SpriteGame.h"
#include "SpriteRender.h"
using namespace Sumomo;

#include <iostream>
using namespace std;

SpriteGame::SpriteGame(HINSTANCE hInst, int width, int height):SumomoGame(hInst,width,height)
{
	Bitmap* bit = resLoader.loadImage(L".\\assets\\arm.png");
	
	GameObject* root = new GameObject();
	root->transform.position = Vector3(0, 0, 0);
	root->transform.rotation = Vector3(0, 0, -45);
	GameObjectList.push_back(root);

	GameObject* g = new GameObject();
	SpriteRender* sr = (new SpriteRender(bit))
		->setSize(100,100)
		->setSpriteRect(Rect(0,0, 256, 256))
		->setPivot(128, 30);
	g->appendBehaviour(sr);
	g->transform.position = Vector3(0, 200, 0);
	g->transform.rotation = Vector3(0, 0, -15);
	g->transform.setParenting(&root->transform);
	GameObjectList.push_back(g);
	

	GameObject* g2 = new GameObject();
	SpriteRender* sr2 = (new SpriteRender(bit))
		->setSize(100, 100)
		->setSpriteRect(Rect(0, 0, 256, 256))
		->setPivot(128,30);
	g2->appendBehaviour(sr2);
	g2->transform.rotation = Vector3(0, 0, 45);
	g2->transform.setParenting(&(g->transform));
	g2->transform.position = Vector3(0, 80, 0);

	GameObjectList.push_back(g2);

}

void SpriteGame::makeGameObjects()
{
}
