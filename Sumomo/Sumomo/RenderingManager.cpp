#include "RenderingManager.h"
#include <iostream>

using namespace std;

void RenderingManager::Draw(HDC hDC)
{
	int inter = width / 8;
	HPEN hPen;
	HBRUSH hBrush;
	hBrush = CreateSolidBrush(RGB(255, 255, 255));
	hPen = CreatePen(PS_SOLID, 3 * width / 800, RGB(0, 0, 0));
	SelectObject(hDC, hPen);
	SelectObject(hDC, hBrush);

	//背景
	Rectangle(hDC, -inter, -inter, width + inter, height + inter);


	// ペンを削除
	DeleteObject(hPen);
	// ブラシを削除
	DeleteObject(hBrush);

	this->currentHDC = hDC;
	for (unsigned int i = 0; i < renderingObjects.size(); i++) {
		this->renderingObjects[i]->Draw(hDC);
	}
}

void RenderingManager::registerBehaviour(Drawable* drw)
{
	this->renderingObjects.push_back(drw);
}

void RenderingManager::withdrawBehaviour(Drawable * drw)
{
	for (unsigned int i = 0; i < this->renderingObjects.size(); i++) {
		if (this->renderingObjects[i] == drw) {
			this->renderingObjects.erase(this->renderingObjects.begin() + i);
			return;
		}
	}
}


