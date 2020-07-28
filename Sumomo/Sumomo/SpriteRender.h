#pragma once
#include "Drawable.h"
class SpriteRender :
	public Drawable
{
public:
	SpriteRender(Bitmap* sprite);
	~SpriteRender();

	void Draw(Graphics* graphic);

private:
	Bitmap* sourceImage;
};

