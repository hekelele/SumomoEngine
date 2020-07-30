#include "SumomoGame.h"

namespace Sumomo {
	Gdiplus::GdiplusStartupInput m_gdiplusStartupInput;
	ULONG_PTR m_pGdiToken;
	vector<GameObject*> GameObjectList;
	RenderingManager renderManager;
	PhysicsManager   phyManager;
	ResourceLoader   resLoader;
}

using namespace Sumomo;


SumomoGame::SumomoGame(HINSTANCE hInst, int width, int height)
{
	Gdiplus::GdiplusStartup(&m_pGdiToken, &m_gdiplusStartupInput, NULL);
	renderManager.width = width;
	renderManager.height = height;
}

SumomoGame::~SumomoGame()
{
}

void SumomoGame::initGame()
{
	makeGameObjects();
	for (unsigned int i = 0; i < GameObjectList.size(); i++) {
		GameObjectList[i]->Awake();
	}

	for (unsigned int i = 0; i < GameObjectList.size(); i++) {
		GameObjectList[i]->Start();
	}

	this->playGame();
}

void SumomoGame::resetGame()
{
	this->pauseGame();
	deleteGameObjects();
	initGame();
}

void SumomoGame::endGame()
{
	this->pauseGame();
	deleteGameObjects();
}

void SumomoGame::updateGame()
{
	for (unsigned int i = 0; i < GameObjectList.size(); i++) {
		GameObjectList[i]->Update();
	}
}

void SumomoGame::makeGameObjects()
{
}

void SumomoGame::deleteGameObjects()
{
	for (unsigned int i = 0; i < GameObjectList.size(); i++) {
		delete(GameObjectList[i]);
	}
	GameObjectList.clear();
}
