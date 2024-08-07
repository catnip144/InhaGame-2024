#pragma once
#include <iostream>
#include <string>

using namespace std;

class Time
{
private:
	int hours;
	int minutes;

public:
	Time();
	Time(int h, int);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	void Show() const;

	Time operator+(const Time& t) const;
	Time operator-(const Time& t) const;
	Time operator*(double n) const;

	friend Time operator*(double m, const Time& t) { return t * m; }
	friend std::ostream& operator<<(std::ostream& os, const Time& t);
};