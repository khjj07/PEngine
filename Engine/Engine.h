#pragma once
#include "Common.h"
#include "Scene.h"
#include "Screen.h"
#include "Render.h"
#include "Protocols.h"
#include "Win32api.h"
#include "Timer.h"

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

public :
	int FRAMES_PER_SECOND = 25;
	EngineState state;
	Scene* currentScene;
	Render* render;
	Timer* timer;
private:
	

};