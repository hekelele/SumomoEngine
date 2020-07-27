#include "Drawable.h"
#include "SumomoGame.h"
using namespace Sumomo;

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
