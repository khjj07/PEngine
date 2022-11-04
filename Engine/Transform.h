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
	Vector2 position;
	Vector2 rotation;
	Vector2 scale;
	GameObject* gameObject;
private:

};