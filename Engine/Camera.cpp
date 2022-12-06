#include "Camera.h"

Camera* Camera::Main = nullptr;
Camera::Camera(Transform* t, float o)
{
	Screen* screen = Render::Instance()->screen;
	if (!Main)
		Main = this;
	transform = t;
	position = transform->position - screen->resolution/2;
	orthoScale = o;
}


Vector2 Camera::WorldToScreenPoint(Vector2 x)
{
	Screen * screen = Render::Instance()->screen;
	return (x+ transform->position) / orthoScale;
}
void Camera::SetPosition(Vector2 pos)
{
	Screen* screen = Render::Instance()->screen;
	transform->position = pos;
	position = transform->position - screen->resolution / 2;
}

Vector2	 Camera::GetPosition()
{
	return position;
}