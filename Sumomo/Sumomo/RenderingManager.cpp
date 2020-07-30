#include "RenderingManager.h"
#include <iostream>
using namespace Gdiplus;
using namespace std;
RenderingManager::RenderingManager()
{
	this->BackgroundColor = Color255(255, 255, 255);
}

RenderingManager::~RenderingManager()
{
}

void RenderingManager::Draw(Gdiplus::Graphics* graphics_)
{
	graphics_->SetInterpolationMode(InterpolationModeBilinear);
	SolidBrush brush(Color(BackgroundColor.r, BackgroundColor.g, BackgroundColor.b));
	graphics_->FillRectangle(&brush, 0, 0, this->width, this->height);
	for (unsigned int i = 0; i < renderingObjects.size(); i++) {
		this->renderingObjects[i]->Draw(graphics_);
		graphics_->ResetTransform();
	}
	if (debugMode) {
		for (unsigned int i = 0; i < renderingObjects.size(); i++) {
			this->renderingObjects[i]->DrawGizmos(graphics_);
			graphics_->ResetTransform();
		}
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

void RenderingManager::setBackgroundColor(int r, int g, int b)
{
	this->BackgroundColor = Color255(r, g, b);
}


