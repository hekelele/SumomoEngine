#include "Drawable.h"
#include "main.h"

void Drawable::Draw(HDC hDC)
{
}

Drawable::Drawable()
{
	this->visible = 1;
	renderManager.registerBehaviour(this);
}

Drawable::~Drawable()
{
	renderManager.withdrawBehaviour(this);
}
