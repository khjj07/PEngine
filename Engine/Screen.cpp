#include "Screen.h"

Screen::Screen(Vector2 res)
{
	resolution = res;
	rt = { 0,0,(long)resolution.x,(long)resolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(Win32api::getWin()->m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom-rt.top, 0);
}