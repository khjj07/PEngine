#include "Engine.h"


Engine::Engine()
{
	render = nullptr;
	screen = nullptr;
}

Engine::Engine(HWND h,MSG message, HACCEL hAccel)
{
	render = nullptr;
	screen = nullptr;
	msg = message;
	hAccelTable = hAccel;
	hWnd = h;
}


void Engine::Run(Scene *scene)
{
	currentScene = scene;
	double dt = 0;
	__int64  s=0, e=0, periodFrequency;

	QueryPerformanceFrequency((LARGE_INTEGER*)&periodFrequency);
	double timeScale = 1.0 / (double)periodFrequency;
	state = EngineState::Run;
	while (state == EngineState::Run)
	{
		Start();
		QueryPerformanceCounter((LARGE_INTEGER*)&e);
		InvalidateRect(hWnd, NULL, TRUE);
		MessageHandling();
		Collide();
		Update(dt);
		QueryPerformanceCounter((LARGE_INTEGER*)&s);
		dt = (double)(e - s) * timeScale;
	}
	
}
EngineState Engine::MessageHandling()
{
	GetMessage(&msg, nullptr, 0, 0);
	if (!TranslateAccelerator(hWnd, hAccelTable, &msg))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return EngineState::Run;
}

EngineState Engine::Start()
{
	currentScene->Start();
	return EngineState::Run;
}

EngineState Engine::Collide()
{
	currentScene->Collide();
	return EngineState::Run;
}

EngineState Engine::Update(double dt)
{
	currentScene->Update(dt);
	return EngineState::Run;
}

EngineState Engine::OnInput(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return EngineState::Run;
}


