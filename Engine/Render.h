#pragma once
#include "Common.h"
#include "Screen.h"
#include "Win32api.h"
class Render : public Singleton<Render>
{
public:
	Render();
	~Render();
	void Init();
	void Update();
	void Clear();
	void Flip();

	Screen* screen;
	HDC hdc;
	HBITMAP hBit;
	HDC MemDC;
private:
	
};