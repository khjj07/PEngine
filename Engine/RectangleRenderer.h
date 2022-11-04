#pragma once
#include "Renderer.h"
#include "Transform.h"
class RectangleRenderer :public Renderer
{
public:
	RectangleRenderer(Transform* t,Vector4 pen, Vector4 brush);
	Vector2 size;
	Vector4 pen;
	Vector4 brush;
	virtual void Draw(HDC* hdc);

private:

};
