#include "Camera.h"

Camera* Camera::Main = nullptr;
Camera::Camera(Transform* t, float o)
{
	if (!Main)
		Main = this;
	transform = t;
	orthoScale = o;
}