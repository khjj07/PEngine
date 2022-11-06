#pragma once
#include "Common.h"
#include "TimerHandler.h"
class Timer
{
public:
	Timer();
	static TimerHandler* Delay(double delay,bool loop, function<void()> callback);
	static void Cancel(TimerHandler *handle);
	static vector<TimerHandler*> timerList;
	void Update(double dt);

private:
	
};

