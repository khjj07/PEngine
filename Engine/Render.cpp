#include "Render.h"

Render::Render()
{
    hdc = GetDC(Win32api::getWin()->m_hWnd);
    hdcBuffer = CreateCompatibleDC(hdc);
}
void Render::Init()
{

}

void Render::Update()
{

    BitBlt(hdc, 0, 0, 300, 300, hdcBuffer, 0, 0, SRCCOPY);
    DeleteDC(hdcBuffer);
    BitBlt(hdcBuffer, 0, 0, 300, 300, hdc, 0, 0, SRCCOPY);
    ReleaseDC(Win32api::getWin()->m_hWnd, hdc);
    InvalidateRect(Win32api::getWin()->m_hWnd, NULL,TRUE);

    hdc = GetDC(Win32api::getWin()->m_hWnd);
    hdcBuffer = CreateCompatibleDC(hdc);
}

void Render::Clear()
{

}