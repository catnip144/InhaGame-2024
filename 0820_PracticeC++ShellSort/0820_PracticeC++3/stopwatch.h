#pragma once
#include <time.h>

class StopWatch
{
private:
	clock_t startTime;
	clock_t endTime;

public:
	StopWatch();
	void Start();
	void Stop();
	clock_t GetStartTime() { return startTime; }
	clock_t GetEndTime() { return endTime; }
	clock_t GetElapsedTime();
};