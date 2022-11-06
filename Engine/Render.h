#pragma once
#include "Common.h"
#include "Win32api.h"
class Render : public Singleton<Render>
{
public:
	Render();
	void Init();
	void Update();
	void Clear();
	void Flip();
	HDC hdc;
	HDC m_hdcBuffer;
	HDC hdcBuffer;
	BITMAP m_btSize;
private:
	
};