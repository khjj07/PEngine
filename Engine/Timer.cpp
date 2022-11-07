#include "Timer.h"

vector<TimerHandler*> Timer::timerList;

Timer::Timer()
{

}

TimerHandler* Timer::Delay(double delay, bool loop, function<void()> callback)
{
	TimerHandler* newHandler = new TimerHandler(delay,loop,callback);
	Timer::timerList.push_back(newHandler);
	return newHandler;
}

void Timer::Cancel(TimerHandler* handle)
{
	handle->exit = true;
}

void Timer::Update(double dt)
{
	vector<TimerHandler*>::iterator timerIter = timerList.begin();
	for (;timerIter < timerList.end(); timerIter++)
	{
		(*timerIter)->Update(dt);
	}
	timerList.erase(std::remove_if(timerList.begin(), timerList.end(), [](TimerHandler* x) { return x->exit == true ; }), timerList.end());
}