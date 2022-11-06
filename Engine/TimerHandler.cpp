#include "TimerHandler.h"

TimerHandler::TimerHandler(double d, bool l, function<void()> c)
{
	delay=d;
	loop=l;
	callback=c;
}

void TimerHandler::Update(double dt)
{
	accum += dt;
	if (accum >= delay)
	{
		accum = 0;
		callback();
		if (!loop)
			exit = true;
	}
}