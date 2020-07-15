#pragma once
#include "GameObject.h"
#include "BorderConstrain.h"
#include <vector>
using namespace std;

extern vector<GameObject*> GameObjectList;
extern int running;

void makeGameObjects();
void deleteGameObjects();

void initGame();
void resetGame();
void endGame();