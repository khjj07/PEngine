#pragma once
#include "Common.h"
#include "Transform.h"
#include "Component.h"
#include "Engine.h"
#include "Render.h"
#include "resource.h"

class Renderer :public Component
{
public:
	Renderer(Transform* t, int img);
	Transform* transform;
	virtual void Draw();
	virtual void Update(double dt);
	HBITMAP bmp;
	BITMAP btSize;
	int image;
private:

};