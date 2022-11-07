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