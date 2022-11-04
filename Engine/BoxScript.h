#pragma once
#include "Common.h"
#include "Component.h"
class BoxScript : public Component
{
public:
	virtual void Update(double dt);
	Vector2 direction;
	Vector2 velocity;
	float speed=10;
	float fraction=0.1;

private:

};

void BoxScript::Update(double dt)
{
	velocity = direction * speed * dt;


	velocity -= velocity * fraction;
}