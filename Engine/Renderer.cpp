#include "Renderer.h"

Renderer::Renderer(Transform* t)
{
	transform = t;
    bmp = (HBITMAP)LoadBitmap(Win32api::getWin()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP1));
}
void Renderer::Update(double dt)
{
    Draw();
}
void Renderer::Draw()
{
    static HDC tmp;
    Render* render = Render::Instance();
    tmp = CreateCompatibleDC(render->hdc);
    SelectObject(tmp, bmp);
    GetObject(bmp, sizeof(BITMAP), &(render->m_btSize));
    BitBlt(render->hdcBuffer, transform->position.x, transform->position.y, render->m_btSize.bmWidth, render->m_btSize.bmHeight, tmp, 0, 0, SRCCOPY);
    DeleteDC(tmp);
}