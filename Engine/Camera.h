#pragma once
#include "Common.h"
#include "Transform.h"
#include "Screen.h"
#include "Render.h"

class Camera : public Component
{
public:
	static Camera* Main;
public:
	Camera(Transform*t,float o);
	Transform* transform;
	float orthoScale = 1;
	Vector2 WorldToScreenPoint(Vector2 x);
	void	SetPosition(Vector2 pos);
	Vector2	GetPosition();
private:
	Vector2 position;
};

