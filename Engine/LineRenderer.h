#pragma once
#include "Common.h"
#include "Transform.h"
#include "Component.h"
#include "Engine.h"
#include "Render.h"
#include "resource.h"

class LineRenderer :public Component
{
public:
	LineRenderer(Vector2 s, Vector2 e);
	LineRenderer(Vector2 s, Vector2 e, COLORREF p);
	LineRenderer(Vector2 s, Vector2 e, COLORREF p,COLORREF b);
	Transform* transform;
	virtual void Draw();
	virtual void Update(double dt);
	Vector2 start;
	Vector2 end;
	COLORREF penColor;
	COLORREF brushColor;
private:

};