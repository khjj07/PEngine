#include "Collider.h"


bool AABB_to_AABB(Rect2D a, Rect2D b)
{
	if (a.max.x < b.min.x || a.min.x > b.max.x) return false;
	if (a.max.y < b.min.y || a.min.y > b.max.y) return false;
	return true;
}

bool OBB_to_OBB(Collider* a, Collider* b)
{
	float distance = (a->transform->position- b->transform->position).Length();

	Vector2 center_a = (a->shape.max + a->shape.min)/2;
	Vector2 center_b = (b->shape.max + b->shape.min) / 2;

	float right_a= (a->shape.max - center_a)* a->transform->right;
	float left_a = (a->shape.max - center_a) * a->transform->left;
	float up_a = (a->shape.max - center_a) * a->transform->up;
	float down_a = (a->shape.max - center_a) * a->transform->down;

	Vector2 up_b = b->transform->up*((b->shape.max - center_b) * b->transform->up);
	Vector2 right_b = b->transform->right*((b->shape.max - center_b) * b->transform->right);
	float right_res = a->transform->right * up_b + a->transform->right * right_b + right_a;
	float left_res = a->transform->right * up_b + a->transform->right * right_b + left_a;
	float up_res = a->transform->right * up_b + a->transform->right * right_b + up_a;
	float down_res = a->transform->right * up_b + a->transform->right * right_b + down_a;

	if (distance < right_res || distance < left_res || distance < up_res || distance < down_res)
		return true;
	else
		return false;
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
	bool check = OBB_to_OBB(this, other);
	//AABB_to_AABB(shape + transform->position, other->shape + other->transform->position);
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