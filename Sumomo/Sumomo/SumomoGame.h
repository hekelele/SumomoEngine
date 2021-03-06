﻿#pragma once
#include "RenderingManager.h"
#include "PhysicsManager.h"
#include "ResourceLoader.h"
#include <windows.h>
#include <Gdiplus.h>
using namespace Gdiplus;
#pragma comment(lib, "Gdiplus.lib")

namespace Sumomo {
	extern RenderingManager renderManager;
	extern PhysicsManager   phyManager;
	extern ResourceLoader   resLoader;
	extern ULONG_PTR m_pGdiToken;
	extern vector<GameObject*> GameObjectList;
}

class SumomoGame
{
public:
	SumomoGame(HINSTANCE hInst, int width, int height);

	virtual ~SumomoGame();

	virtual void initGame();
	virtual void resetGame();
	virtual void endGame();
	virtual void updateGame();
	inline virtual void updateTimer(int t) { timerTime = t; };

	virtual void makeGameObjects();
	virtual void deleteGameObjects();

	virtual inline void playGame() { this->running = 1; }
	virtual inline void pauseGame() { this->running = 0; }

	inline int isRunning() { return this->running; }
	inline int getTime() { return timerTime; }


private:
	int running;
	int timerTime;

};

