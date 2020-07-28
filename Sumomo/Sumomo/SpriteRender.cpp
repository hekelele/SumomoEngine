#include "SpriteRender.h"
using namespace Gdiplus;

SpriteRender::SpriteRender(Bitmap * sprite)
{
	this->sourceImage = sprite;
}

SpriteRender::~SpriteRender()
{
}

void SpriteRender::Draw(Graphics * graphic)
{
	Rect targetRect(0, 0, 200, 200);
	graphic->DrawImage(this->sourceImage, targetRect, 0, 0, 256, 256, UnitPixel);
}
