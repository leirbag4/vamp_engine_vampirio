#ifndef XTIMER_H
#define XTIMER_H

#include <chrono>

using namespace std::chrono;

class XTimer 
{
    public:
        XTimer(double delay = 1);
        void SetDelay(double delay);
        void SetSDelay(float delay);
        void Start();
        void Stop();
        void Pause();
        void Resume();
        bool Update();
        bool HasFinished();
        void SetAsFinished();
        int GetTotalSeconds();
        long long GetRemainingTime();
        long long  GetElapsedTime();
        long long  GetEndTime();
        static long long GetMillis();

    private:
        long long  time;
        long long  time_locked;
        long long  startTime;
        long long  endTime;
        bool _started;
        bool DONE;

        long long GetCurrentTime();
};

#endif