#include "Drawable.h"
#include "SumomoGame.h"
using namespace Gdiplus;
using namespace Sumomo;

void Drawable::Draw(Graphics * graphic)
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
