#pragma once
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class cVector3
{
private:
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;

public:
	cVector3() {}
	cVector3(double _x, double _y, const double& _z);

	double Dot(cVector3& v);
	cVector3 Cross(cVector3& v);
	double Angle(cVector3& v);
	double Length();
	cVector3 Normalize();

	bool operator==(const cVector3& v) const;
	bool operator!=(const cVector3& v) const;
	cVector3 operator+(const cVector3& v) const;
	cVector3 operator-(const cVector3& v) const;
	cVector3 operator*(double s) const;
	cVector3 operator/(double s) const;

	friend cVector3 operator*(double s, const cVector3& v);
	friend std::ostream& operator<<(std::ostream& os, const cVector3& v);
	friend std::istream& operator>>(std::istream& is, cVector3& v);
};