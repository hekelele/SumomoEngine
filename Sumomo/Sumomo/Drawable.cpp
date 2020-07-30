#include "Drawable.h"
#include "SumomoGame.h"
#include "GameObject.h"
#include "Transform.h"
using namespace Gdiplus;
using namespace Sumomo;
#include <iostream>
using namespace std;

void Drawable::Draw(Graphics * graphic)
{
	tranformFromParent(this->gameObject->transform.parent, graphic);
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

void Drawable::tranformFromParent(Transform * tpointer, Graphics* g)
{
	if (tpointer == nullptr) {
		return;
	}
	
	tranformFromParent(tpointer->parent, g);

	Vector3 pp = tpointer->position;
	Vector3 rp = tpointer->rotation;
	g->TranslateTransform(pp.x, pp.y);
	g->RotateTransform(rp.z);
	return;
}

