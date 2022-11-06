// Engine.cpp : ���ø����̼ǿ� ���� �������� �����մϴ�.
//

#include "Common.h"
#include "Engine.h"
#include "Scene1.h"
#include "Win32api.h"

Win32api* Win32api::m_pMyWin = nullptr;

Win32api::Win32api() :
    m_hInstance(NULL),
    m_hWnd(NULL)
{
}

void Win32api::createWin()
{
    if (!m_pMyWin)
        m_pMyWin = new Win32api();
}

Win32api* Win32api::getWin()
{
    return m_pMyWin;
}

void Win32api::releaseWin()
{
    if (m_pMyWin)
    {
        delete m_pMyWin;
        m_pMyWin = nullptr;
    }
}

bool Win32api::init(HINSTANCE hInstance)
{
    //������ Ŭ���� ���
    WNDCLASSEXW wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = wndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ENGINE));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = 0;
    wcex.lpszClassName = L"className";
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
    RegisterClassExW(&wcex);


    //������ ����
    m_hWnd = CreateWindowW(L"className", nullptr, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!m_hWnd)
        return false;

    //�ʱ�ȭ �۾��� ���⿡
    m_hInstance = hInstance;

    ShowWindow(m_hWnd, SW_SHOWDEFAULT);
    UpdateWindow(m_hWnd);

    return true;
}

EngineState Win32api::updateMsg(MSG *msg)
{
    while (PeekMessage(msg, NULL, 0, 0, PM_REMOVE))
    {
        if (msg->message == WM_QUIT) {
            return EngineState::Stop;
        }
        TranslateMessage(msg);
        DispatchMessage(msg);
    }
    return EngineState::Run;

   
}

void Win32api::release()
{
}

LRESULT Win32api::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    return m_pMyWin->myProc(hWnd, message, wParam, lParam);
}

LRESULT Win32api::myProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�.
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

