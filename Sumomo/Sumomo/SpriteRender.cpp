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
	if (this->visible == 0) {
		return;
	}
	Drawable::Draw(graphics);

	Vector3 t = this->gameObject->transform.position;
	Rect targetRect(int(t.x - this->pivot.x), 
		int(t.y - this->pivot.y),
		int(this->width), int(this->height));

	graphics->TranslateTransform(t.x, t.y);
	graphics->RotateTransform(this->gameObject->transform.rotation.z);
	graphics->TranslateTransform(-t.x, -t.y);
	

	graphics->DrawImage(this->sourceImage, targetRect, 
		imageRect.X,imageRect.Y,imageRect.Width,imageRect.Height, UnitPixel);
}

void SpriteRender::DrawGizmos(Graphics * graphics)
{
	if (this->gizmo_visible != 1) {
		return;
	}
	Drawable::DrawGizmos(graphics);
	Vector3 t = this->gameObject->transform.position;
	Rect r2(int(t.x - 4), int(t.y - 4), 8, 8);
	SolidBrush b(Color(50, 255, 50));
	Pen p(Color(50, 255, 50));
	Rect targetRect(int(t.x - this->pivot.x),
		int(t.y - this->pivot.y),
		int(this->width), int(this->height));

	graphics->TranslateTransform(t.x, t.y);
	graphics->RotateTransform(this->gameObject->transform.rotation.z);
	graphics->TranslateTransform(-t.x, -t.y);

	graphics->DrawRectangle(&p, targetRect);
	graphics->FillEllipse(&b, r2);
}

SpriteRender * SpriteRender::setPivot(float x, float y)
{
	float xrate, yrate;
	xrate = float((x - imageRect.X) / (imageRect.Width));
	yrate = float((y - imageRect.Y) / (imageRect.Height));

	this->pivot = Vector3(xrate*width, yrate*height, 0);

	return this;
}

