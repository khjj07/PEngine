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
	Vector2 position;
	float rotation;
	Vector2 scale;
	GameObject* gameObject;
private:

};