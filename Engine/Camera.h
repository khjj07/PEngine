#pragma once
#include "Common.h"
#include "Transform.h"
class Camera : public Component
{
public:
	static Camera* Main;
public:
	Camera(Transform*t,float o);
	Transform* transform;
	float orthoScale = 1;

private:

};

