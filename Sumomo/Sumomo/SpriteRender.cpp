#include "SpriteRender.h"
#include "GameObject.h"
using namespace Gdiplus;


SpriteRender::SpriteRender(Bitmap * sprite)
{
	this->sourceImage = sprite;
	this->width = 100;
	this->height = 100;
	this->imageRect = Rect(0, 0, 100, 100);
	this->pivot = Vector3(0, 0, 0);
}

SpriteRender::~SpriteRender()
{
}

void SpriteRender::Draw(Graphics * graphics)
{
	Drawable::Draw(graphics);
	Vector3 t = this->gameObject->transform.position;
	Rect targetRect(int(t.x+this->pivot.x- this->width/2.0), int(t.y+this->pivot.y-this->height/2.0),
		int(this->width), int(this->height));

	graphics->DrawImage(this->sourceImage, targetRect, 
		imageRect.X,imageRect.Y,imageRect.Width,imageRect.Height, UnitPixel);
}

