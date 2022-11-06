#pragma once
#include "Common.h"

class TimerHandler
{
public:
	TimerHandler(double delay, bool loop, function<void()> callback);
	~TimerHandler();
	void Update(double dt);
public:
	function<void()> callback;
	double delay;
	bool loop;
	double accum = 0;
	bool exit = false;
private:

};
