#pragma once
#include "Common.h"
#include "Renderer.h"
#include "Timer.h"
class Animation
{
public:
	Animation(Renderer* renderer);
	void Play(float duration,bool loop);
	void Cancel();
	void PushImage(int bmp);
	Renderer* renderer;
	vector<HBITMAP> imageList;
	TimerHandler *animationHandler;
};