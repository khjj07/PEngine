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


	
		QueryPerformanceCounter((LARGE_INTEGER*)&s);
		if (!objectBuffer.empty())
		{
			vector<GameObject*>::iterator iter=objectBuffer.begin();
			for (; iter < objectBuffer.end(); iter++)
			{
				currentScene->Push(*iter);
			}
			objectBuffer.clear();
		}
		if (!removeObjectBuffer.empty())
		{
			vector<GameObject*>::iterator iter = removeObjectBuffer.begin();
			for (; iter < removeObjectBuffer.end(); iter++)
			{
				currentScene->Pop(*iter);
				(*iter)->OnDestroy();
				delete (*iter);
			}
			removeObjectBuffer.clear();
		}
		if (nextScene)
		{
			currentScene = nextScene;
			currentScene->OnEnable();
		}
		Start();
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

GameObject* Engine::Push(GameObject* newObject)
{
	objectBuffer.push_back(newObject);
	return newObject;
}


void Engine::Pop(GameObject* obj)
{
	removeObjectBuffer.push_back(obj);
}
