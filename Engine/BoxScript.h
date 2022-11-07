#pragma once
#include "Common.h"
#include "Component.h"
#include "Transform.h"
#include "Timer.h"
#include "Animation.h"

class BoxScript : public Component
{
public:
	BoxScript(Transform* t);
	virtual void Start();
	virtual void Update(double dt);
	Vector2 direction;
	Vector2 velocity;
	Transform* transform;
	float speed=200;
	float fraction=0.1;

private:

};

