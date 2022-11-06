#include "BoxScript.h"


BoxScript::BoxScript(Transform* t)
{
	transform = t;
}
	

void BoxScript::Update(double dt)
{
	direction = Vector2(1, 0);
	velocity = direction * speed * dt;

	transform->position += velocity;
}