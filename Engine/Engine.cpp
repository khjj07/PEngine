#include "Engine.h"


Engine::Engine()
{
	render = Render::Instance();
	timer = new Timer();
}

void Engine::Run(Scene *scene)
{
	currentScene = scene;
	double dt = 0;
	__int64  s=0, e=0, periodFrequency;

	QueryPerformanceFrequency((LARGE_INTEGER*)&periodFrequency);
	double timeScale = 1.0 / (double)periodFrequency;
	state = EngineState::Run;
	MSG msg = {};
	while (state == EngineState::Run)
	{
		Start();
		QueryPerformanceCounter((LARGE_INTEGER*)&s);
		Collide();
		Update(dt);
		render->Update();
		timer->Update(dt);
		state = Win32api::getWin()->updateMsg(&msg);
		QueryPerformanceCounter((LARGE_INTEGER*)&e);
		dt = (double)(e - s) * timeScale;
	}
	Win32api::getWin()->release();
	Win32api::releaseWin();
}

EngineState Engine::MessageHandling()
{

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

EngineState Engine::OnInput()
{
	return EngineState::Run;
}