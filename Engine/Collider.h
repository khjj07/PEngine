#pragma once
#include "Common.h"
#include "Component.h"
#include "Transform.h"
#include "GameObject.h"
class GameObject;
class Transform;
class Collider : public Component
{
public:
	Collider();
	~Collider();
	CollisionResponse Collide(Collider* other);
	Transform* transform;
	GameObject* gameObject;
	Rect2D shape;
	bool enter=false;
private:

};
