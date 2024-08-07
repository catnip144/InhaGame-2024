#include "cVector3.h"
#define PI 3.14159265

cVector3::cVector3(double _x, double _y, const double& _z)
{
	x = _x;
	y = _y;
	z = _z;
}

double cVector3::Dot(cVector3& v)
{
	return x * v.x + y * v.y + z * v.z;
}

cVector3 cVector3::Cross(cVector3& v)
{
	return cVector3(
		y * v.z - z * v.y,
		z * v.x - x * v.z,
		x * v.y - y * v.x
	);
}

double cVector3::Angle(cVector3& v)
{
	cVector3 normalizedA = this->Normalize();
	cVector3 normalizedB = v.Normalize();

	return acos(normalizedA.Dot(normalizedB)) * 180.0 / PI;
}

double cVector3::Length()
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

cVector3 cVector3::Normalize()
{
	return (*this / this->Length());
}

bool cVector3::operator==(const cVector3& v) const
{
	return (((x == v.x) && (y == v.y)) && (z == v.z));
}

bool cVector3::operator!=(const cVector3& v) const
{
	return (((x != v.x) || (y != v.y)) || (z != v.z));
}

cVector3 cVector3::operator+(const cVector3& v) const
{
	return cVector3(x + v.x, y + v.y, z + v.z);
}

cVector3 cVector3::operator-(const cVector3& v) const
{
	return cVector3(x - v.x, y - v.y, z - v.z);
}

cVector3 cVector3::operator*(double s) const
{
	return cVector3(x * s, y * s, z * s);
}

cVector3 cVector3::operator/(double s) const
{
	return cVector3(x / s, y / s, z / s);
}

cVector3 operator*(double s, const cVector3& v)
{
	return v * s;
}

std::ostream& operator<<(std::ostream& os, const cVector3& v)
{
	os << "(x, y, z) = (" << v.x << ", " << v.y << ", " << v.z << ")";
	return os;
}

std::istream& operator>>(std::istream& is, cVector3& v)
{
	is >> v.x >> v.y >> v.z;
	return is;
}