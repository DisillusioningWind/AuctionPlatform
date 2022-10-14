#pragma once
#include "../Global.h"

template <class T>
class Timer
{
	typedef void(T::* EventHandler)();
private:
	uint64_t interval;
	bool isRun;
	std::thread TimerThread;
	T* t;
	EventHandler handler;

	void Runner();
public:
	Timer();
	Timer(uint64_t interval, T* t, EventHandler handler);
	void Start();
	void Stop();
};

template<class T>
Timer<T>::Timer()
{

}
template <class T>
Timer<T>::Timer(uint64_t interval, T* t, EventHandler handler)
{
	this->interval = interval;
	this->isRun = true;
	this->t = t;
	this->handler = handler;
}
template <class T>
void Timer<T>::Start()
{
	this->isRun = true;
	this->Runner();
}
template <class T>
void Timer<T>::Stop()
{
	this->isRun = false;
}
template <class T>
void Timer<T>::Runner()
{
	while (this->isRun)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(this->interval));
		(t->*(this->handler))();
	}
}