#include "Render.h"

Render::Render()
{
    screen = new Screen(Vector2(1920, 1080));
    hdc = GetDC(Win32api::getWin()->m_hWnd);
    hBit = CreateCompatibleBitmap(hdc, screen->resolution.x, screen->resolution.y);
    MemDC = CreateCompatibleDC(hdc);
    HBITMAP OldBit=(HBITMAP)SelectObject(MemDC, hBit);
    DeleteObject(OldBit);
}
Render::~Render()
{
    ReleaseDC(Win32api::getWin()->m_hWnd, hdc);
    DeleteDC(MemDC);
    DeleteObject(hBit);
}


void Render::Init()
{

}

void Render::Update()
{
    BitBlt(hdc, 0, 0, screen->resolution.x, screen->resolution.y, MemDC, 0, 0, SRCCOPY);
    ReleaseDC(Win32api::getWin()->m_hWnd, hdc);
    InvalidateRect(Win32api::getWin()->m_hWnd, NULL, false);
    hdc = GetDC(Win32api::getWin()->m_hWnd);
    Rectangle(MemDC, -1, -1,screen->resolution.x + 1, screen->resolution.y + 1);

}

void Render::Clear()
{

}