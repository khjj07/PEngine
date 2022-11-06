#pragma once
#include "Common.h"
#include "resource.h"
#include "Protocols.h"
class Win32api
{
public:
    HINSTANCE   m_hInstance;
    HWND        m_hWnd;
private:
    static Win32api* m_pMyWin;

public:
    static void createWin();
    static Win32api* getWin();
    static void releaseWin();

private:
    Win32api();
    static LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    LRESULT CALLBACK myProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

public:
    bool init(HINSTANCE hInstance);
    EngineState updateMsg(MSG *msg);
    void release();
};
