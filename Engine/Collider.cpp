#include "Collider.h"


bool AABB_to_AABB(Rect2D a, Rect2D b)
{
	if (a.max.x < b.min.x || a.min.x > b.max.x) return false;
	if (a.max.y < b.min.y || a.min.y > b.max.y) return false;
	return true;
}


Collider::Collider()
{
}

Collider::~Collider()
{
}



CollisionResponse Collider::Collide(Collider* other)
{
	CollisionResponse result;
	bool check = AABB_to_AABB(shape + transform->position, other->shape + other->transform->position);
	result.other = other;

	if (!enter && check)
	{
		result.state = CollisionState::Enter;
		enter = true;
	}
	else if(enter && !check)
	{
		result.state = CollisionState::Exit;
		enter = false;
	}
	else if (check)
	{
		result.state = CollisionState::Stay;
		enter = true;
	}

	return result;
}