#pragma once
#include "Common.h"
#include "Transform.h"
#include "Component.h"
#include "Engine.h"
#include "Render.h"
#include "resource.h"

class CircleRenderer :public Component
{
public:
	CircleRenderer(Transform* t, int r);
	CircleRenderer(Transform* t, int r, COLORREF p);
	CircleRenderer(Transform* t, int r, COLORREF p, COLORREF b);
	Transform* transform;
	virtual void Draw();
	virtual void Update(double dt);
	int radius;
	COLORREF penColor;
	COLORREF brushColor;
private:

};