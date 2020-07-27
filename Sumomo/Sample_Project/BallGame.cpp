#include "BallGame.h"
#include "SumomoGame.h"
#include <iostream>
#include "Dynamic.h"
#include "Circle.h"
#include "BorderConstrain.h"

using namespace std;
using namespace Sumomo;

BallGame::BallGame(HINSTANCE hInst):SumomoGame(hInst)
{
}

GameObject * BallGame::makeBall(float radius, float e, Vector3 beginVelocity, Vector3 beginPosition)
{
	GameObject* cs = new GameObject();

	Circle* c = new Circle(radius, Color255(0, 0, 0), radius / 50.0f * 3, Color255(255, 255, 255));
	cs->appendBehaviour(c);

	Dynamic* dm = new Dynamic();
	dm->mass = radius * radius;
	cs->appendBehaviour(dm);

	dm->applyGravity = 0;
	dm->setVelocity(beginVelocity);
	dm->setPosition(beginPosition);

	CircleCollider* cc = new CircleCollider();
	cc->e = e;
	cs->appendBehaviour(cc);

	BorderConstrain* bc = new BorderConstrain(800, 600);
	cs->appendBehaviour(bc);
	return cs;
}

void BallGame::makeGameObjects()
{
	GameObject* ball_01, *ball_02, *ball_03, *ball_04;
	ball_01 = this->makeBall(50, 0.8f, Vector3(4, 3, 0), Vector3(400, 150, 0));
	ball_02 = this->makeBall(50, 0.8f, Vector3(4, -3, 0), Vector3(400, 450, 0));
	ball_03 = this->makeBall(10, 1, Vector3(20, 30, 0), Vector3(100, 50, 0));
	ball_04 = this->makeBall(100, 0.9f, Vector3(-1, -1.5f, 0), Vector3(200, 300, 0));


	GameObjectList.push_back(ball_01);
	GameObjectList.push_back(ball_02);
	GameObjectList.push_back(ball_03);
	GameObjectList.push_back(ball_04);
}
