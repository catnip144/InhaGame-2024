#pragma once
#ifndef STONEWT_H_
#define STONEWT_H_

#include <iostream>
#include <string>

using namespace std;

class Stonewt
{
private:
	enum {Lbs_per_stn = 14};
	int stone;
	double pds_left;
	double pounds;

public:
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt();
	void show_stn() const;
	void show_lbs() const;

	operator int() const;
	operator double() const;
};

#endif