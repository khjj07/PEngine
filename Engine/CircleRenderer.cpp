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


	int pos_x = transform->position.x - radius / Camera::Main->orthoScale * transform->scale.x - Camera::Main->GetPosition().x;
	int pos_y = transform->position.y - radius / Camera::Main->orthoScale * transform->scale.x - Camera::Main->GetPosition().y;
	int size_x = 2*radius * transform->scale.x / Camera::Main->orthoScale;
	int size_y = 2*radius * transform->scale.x / Camera::Main->orthoScale;

	Ellipse(render->MemDC, pos_x, pos_y, pos_x+ size_x, pos_y + size_y);

	SelectObject(render->MemDC, hOldPen);
	DeleteObject(hNewPen);

	SelectObject(render->MemDC, hOldBrush);
	DeleteObject(hNewBrush);

	DeleteDC(tmp);
}