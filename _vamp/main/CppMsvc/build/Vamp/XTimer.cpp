#include "XTimer.h"
//#include "Time.h"

XTimer::XTimer(double delay) : time(0), time_locked(delay), _started(false), DONE(false), startTime(0), endTime(0) {}

void XTimer::SetDelay(double delay) 
{
    this->time_locked = delay;
}

void XTimer::SetSDelay(float delay) 
{
    this->time_locked = delay * 1000;
}

void XTimer::Start() 
{
    startTime = GetCurrentTime();
    time = time_locked;
    _started = true;
    DONE = false;
}

void XTimer::Stop() 
{
    _started = false;
    DONE = false;
}

void XTimer::Pause() 
{
    _started = false;
}

void XTimer::Resume() 
{
    _started = true;
}

bool XTimer::Update() 
{
    double _elapsed;

    endTime = GetCurrentTime();
    _elapsed = endTime - startTime;

    if (_started) {
        if (time > 0) {
            time -= _elapsed;
            startTime = GetCurrentTime();
        }
        else {
            _started = false;
            DONE = true;
        }
    }

    return DONE;
}

bool XTimer::HasFinished() 
{
    return DONE;
}

void XTimer::SetAsFinished() 
{
    DONE = true;
}

int XTimer::GetTotalSeconds() 
{
    return static_cast<int>(time);
}

long long XTimer::GetRemainingTime() 
{
    return time;
}

long long XTimer::GetElapsedTime() 
{
    return time_locked - time;
}

long long XTimer::GetEndTime() 
{
    return time_locked;
}

long long XTimer::GetCurrentTime() 
{
	auto now = high_resolution_clock::now();
    long long time = duration_cast<nanoseconds>(now.time_since_epoch()).count() / 1000000;
    return time;//(double)Time::GetMillis();
}

// static
long long XTimer::GetMillis()
{
    auto now = high_resolution_clock::now();
    long long time = duration_cast<nanoseconds>(now.time_since_epoch()).count() / 1000000;
    return time;
}


