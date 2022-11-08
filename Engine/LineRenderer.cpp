#include "LineRenderer.h"

LineRenderer::LineRenderer(Vector2 s, Vector2 e)
{
	start = s;
	end = e;
}

LineRenderer::LineRenderer(Vector2 s, Vector2 e, COLORREF p)
{
	start = s;
	end = e;
	penColor = p;
}

LineRenderer::LineRenderer(Vector2 s, Vector2 e, COLORREF p, COLORREF b)
{
	start = s;
	end = e;
	penColor = p;
	brushColor = b;
}


void LineRenderer::Update(double dt)
{
	Draw();
}
void LineRenderer::Draw()
{
	static HDC tmp;

	Render* render = Render::Instance();

	HPEN hNewPen = CreatePen(PS_SOLID, 1, penColor);
	HPEN hOldPen = (HPEN)SelectObject(render->MemDC, hNewPen);

	HBRUSH hNewBrush = CreateSolidBrush(brushColor);
	HBRUSH hOldBrush = (HBRUSH)SelectObject(render->MemDC, hNewBrush);

	MoveToEx(render->MemDC, start.x, start.y,NULL);
	LineTo(render->MemDC, end.x, end.y);

	SelectObject(render->MemDC, hOldPen);
	DeleteObject(hNewPen);

	SelectObject(render->MemDC, hOldBrush);
	DeleteObject(hNewBrush);

	DeleteDC(tmp);
}