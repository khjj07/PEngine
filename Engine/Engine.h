#pragma once
#include "Common.h"
#include "Scene.h"
#include "Screen.h"
#include "Render.h"
#include "Protocols.h"
#include "Win32api.h"
#include "Timer.h"
#include "Input.h"

class Engine : public Singleton<Engine>
{
public:
	Engine();
	void Run(Scene* scene);
	EngineState Start();
	EngineState OnInput();
	EngineState Update(double dt);
	EngineState LoadScene();
	EngineState UnloadScene();
	EngineState Collide();
	EngineState MessageHandling();
	GameObject* Push(GameObject* newObject);
	void Pop(GameObject* obj);

public :
	int FRAMES_PER_SECOND = 25;
	EngineState state;
	Scene* currentScene;
	Render* render;
	Timer* timer;
	vector<GameObject*> objectBuffer;
	vector<GameObject*>  removeObjectBuffer;
	Scene* nextScene;
private:
	

};

static GameObject* Instantiate(GameObject* obj)
{
	return Engine::Instance()->Push(obj);
}

static void Destroy(GameObject* obj)
{
	Engine::Instance()->Pop(obj);
}


