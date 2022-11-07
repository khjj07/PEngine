#pragma once
#include "Common.h"
#include "Component.h"
#include "GameObject.h"
class GameObject;
class Transform : public Component
{
public:
	Transform();
	Transform(Vector2 pos);
	Transform(Vector2 pos, float rot);
	Transform(Vector2 pos, float rot, Vector2 Scale);
	virtual void Update(double dt);
	Vector2 position;
	float rotation;
	Vector2 scale;
	Vector2 up = Vector2(0,1);
	Vector2 down = Vector2(0, -1);
	Vector2 right = Vector2(1, 0);
	Vector2 left = Vector2(-1, 0);
	GameObject* gameObject;
private:

};