#pragma once
#include "Common.h"
#include "Scene.h"
#include "Screen.h"
#include "Render.h"
#include "Protocols.h"

class Engine : public Singleton<Engine>
{
public:
	Engine();
	Engine(HWND, MSG, HACCEL);
	void Run(Scene* scene);
	EngineState Start();
	EngineState OnInput(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
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
	Screen* screen;
	MSG msg;
	HACCEL hAccelTable;
	HWND hWnd;
private:
	

};