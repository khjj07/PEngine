#include "Common.h"
#include "Engine.h"
#include "Scene1.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR    lpCmdLine, _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.
    Win32api::createWin();
    Win32api::getWin()->init(hInstance);
    Scene1* scene1 = new Scene1();
    Engine* engine = Engine::Instance();
    engine->Run(scene1);
    return 0;
}