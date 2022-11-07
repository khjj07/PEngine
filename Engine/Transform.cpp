#include "Transform.h"
Transform::Transform()
{
	position = Vector2();
}
Transform::Transform(Vector2 pos)
{
	position = pos;
	scale = Vector2(1, 1);
}

Transform::Transform(Vector2 pos, float rot)
{
	position = pos;
	rotation = rot;
	scale = Vector2(1,1);
}

Transform::Transform(Vector2 pos, float rot, Vector2 Scale)
{
	position = pos;
	rotation = rot;
	scale = scale;
}

void Transform::Update(double dt)
{
	Vector2 up = Vector2(cosf(rotation+90), sinf(rotation+90));
	Vector2 down = Vector2(cosf(rotation + 270), sinf(rotation + 270));
	Vector2 right = Vector2(cosf(rotation), sinf(rotation));
	Vector2 left = Vector2(cosf(rotation + 180), sinf(rotation + 180));
	rotation = rotation>=360 ? rotation - 360 : rotation;
}

void Transform::AddComponent(Component* newComponent)
{
	componentList->push_back(newComponent);
}