#include "RectangleRenderer.h"


RectangleRenderer::RectangleRenderer(Transform* t, Vector4 p, Vector4 b) : Renderer(t)
{
	pen = p;
	brush = b;
}

void RectangleRenderer::Draw(HDC *hdc)
{
	HPEN MyPen = CreatePen(PS_SOLID, 5, pen.Rgb());
	HPEN OldPen = (HPEN)SelectObject(*hdc, MyPen);

	HBRUSH MyBrush = CreateSolidBrush(brush.Rgb());
	HBRUSH OldBrush = (HBRUSH)SelectObject(*hdc, MyBrush);

	Rectangle(*hdc, transform->position.x, transform->position.y, size.x, size.y);
	SelectObject(*hdc, OldPen);
	DeleteObject(MyPen);
	SelectObject(*hdc, OldBrush);
	DeleteObject(MyBrush);
}