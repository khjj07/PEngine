#pragma once
#include "Common.h"
#include "BitmapRenderer.h"
#include "Timer.h"
class Animation
{
public:
	Animation(BitmapRenderer* renderer);
	void Play(float duration,bool loop);
	void Cancel();
	void PushImage(int bmp);
	BitmapRenderer* renderer;
	vector<HBITMAP> imageList;
	TimerHandler *animationHandler;
};