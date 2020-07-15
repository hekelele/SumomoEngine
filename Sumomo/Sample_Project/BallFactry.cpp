#include "BallFactry.h"
#include "CircleCollider.h"

GameObject* BallFactry::makeBall(float radius, float e, Vector3 beginVelocity, Vector3 beginPosition)
{
	GameObject* cs = new GameObject();

	Circle* c = new Circle(radius, Color(0, 0, 0), radius/50.0*3, Color(255, 255, 255));
	cs->appendBehaviour(c);

	Dynamic* dm = new Dynamic();
	dm->mass = radius * radius;
	cs->appendBehaviour(dm);

	dm->applyGravity = 0;
	dm->setVelocity(beginVelocity);
	dm->setPosition(beginPosition);

	CircleCollider* cc = new CircleCollider();
	cc->e = e;
	cs->appendBehaviour(cc);

	BorderConstrain* bc = new BorderConstrain(800, 600);
	cs->appendBehaviour(bc);
	return cs;
}
