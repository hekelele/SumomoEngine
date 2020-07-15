#include "scripts.h"
#include "main.h"
#include <iostream>
#include "Dynamic.h"
#include "Circle.h"
#include "BallFactry.h"

using namespace std;

vector<GameObject*> GameObjectList;
int running;

void makeGameObjects()
{
	GameObject* ball_01, *ball_02, *ball_03, *ball_04;
	ball_01 = BallFactry::makeBall(50,0.8,Vector3(4, 3, 0), Vector3(400, 150, 0));
	ball_02 = BallFactry::makeBall(50,0.8,Vector3(4, -3, 0), Vector3(400, 450, 0));
	ball_03 = BallFactry::makeBall(10, 1, Vector3(20, 30, 0), Vector3(100, 50, 0));
	ball_04 = BallFactry::makeBall(100, 0.9, Vector3(-1, -1.5, 0), Vector3(200, 300, 0));

	
	GameObjectList.push_back(ball_01);
	GameObjectList.push_back(ball_02);
	GameObjectList.push_back(ball_03);
	GameObjectList.push_back(ball_04);
}

void deleteGameObjects()
{
	for (unsigned int i = 0; i < GameObjectList.size(); i++) {
		delete(GameObjectList[i]);
	}
	GameObjectList.clear();
	running = 0;
}

void initGame()
{
	makeGameObjects();
	for (unsigned int i = 0; i < GameObjectList.size(); i++) {
		GameObjectList[i]->Awake();
	}

	for (unsigned int i = 0; i < GameObjectList.size(); i++) {
		GameObjectList[i]->Start();
	}

	running = 1;
}

void resetGame()
{
	deleteGameObjects();
	initGame();
}

void endGame() {
	deleteGameObjects();
}
