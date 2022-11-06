#pragma once
#include "Common.h"
#include "Component.h"
#include "Transform.h"

class BoxScript : public Component
{
public:
	BoxScript(Transform* t);
	virtual void Update(double dt);
	Vector2 direction;
	Vector2 velocity;
	Transform* transform;
	float speed=10;
	float fraction=0.1;

private:

};

