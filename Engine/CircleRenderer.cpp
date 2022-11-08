#include "CircleRenderer.h"

CircleRenderer::CircleRenderer(Transform* t, int r)
{
	transform = t;
	radius = r;
}

CircleRenderer::CircleRenderer(Transform* t, int r, COLORREF p)
{
	transform = t;
	radius = r;
	penColor = p;
}

CircleRenderer::CircleRenderer(Transform* t, int r, COLORREF p, COLORREF b)
{
	transform = t;
	radius = r;
	penColor = p;
	brushColor = b;

}

void CircleRenderer::Update(double dt)
{
	Draw();
}
void CircleRenderer::Draw()
{
	static HDC tmp;

	Render* render = Render::Instance();

	HPEN hNewPen = CreatePen(PS_SOLID, 1, penColor);
	HPEN hOldPen = (HPEN)SelectObject(render->MemDC, hNewPen);

	HBRUSH hNewBrush = CreateSolidBrush(brushColor);
	HBRUSH hOldBrush = (HBRUSH)SelectObject(render->MemDC, hNewBrush);

	Ellipse(render->MemDC, transform->position.x- radius * transform->scale.x, transform->position.y- radius * transform->scale.x, transform->position.x+radius * transform->scale.x, transform->position.y+radius* transform->scale.x);

	SelectObject(render->MemDC, hOldPen);
	DeleteObject(hNewPen);

	SelectObject(render->MemDC, hOldBrush);
	DeleteObject(hNewBrush);

	DeleteDC(tmp);
}