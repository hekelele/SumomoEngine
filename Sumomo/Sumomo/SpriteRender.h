﻿#pragma once
#include "Drawable.h"
#include "Transform.h"
class SpriteRender :
	public Drawable
{
public:
	SpriteRender(Bitmap* sprite);
	~SpriteRender();

	virtual void Draw(Graphics* graphics);
	
	inline SpriteRender* setSpriteRect(Rect r) { this->imageRect = r; return this; }
	inline SpriteRender* setSize(float ww, float hh) { this->width = ww; this->height = hh; return this; }
	SpriteRender* setPivot(float x, float y);
private:
	Bitmap* sourceImage;
	Rect imageRect;
	Vector3 pivot;
	float width;
	float height;
};

