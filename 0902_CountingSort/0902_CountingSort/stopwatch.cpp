#include "stopwatch.h"

StopWatch::StopWatch()
{
	startTime = clock();
}

void StopWatch::Start()
{
	startTime = clock();
}

void StopWatch::Stop()
{
	endTime = clock();
}

clock_t StopWatch::GetElapsedTime()
{
	return endTime - startTime;
}
