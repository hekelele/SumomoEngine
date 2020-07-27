#include "Collidable.h"
#include "SumomoGame.h"
using namespace Sumomo;

Collidable::Collidable()
{
	this->type = None;
	this->e = 1;
	phyManager.registerBehaviour(this);
}

Collidable::~Collidable()
{
	phyManager.withdrawBehaviour(this);
}

Collidable::ColliderType Collidable::getType()
{
	return this->type;
}
