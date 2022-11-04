#pragma once
#include "Common.h"
#include "Scene.h"

class Render {
public:
	Render();
	void Init();
	void Update(HDC* hdc, Scene* currentScene);
	void Clear();
	void Flip();
private:
	
};