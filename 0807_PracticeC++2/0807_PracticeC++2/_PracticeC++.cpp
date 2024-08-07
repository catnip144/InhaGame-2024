/*
	Vector3 클래스 정의

	Vector3 operator/(double n) const
	static float Dot(Vector3& v1, Vector3& v2);
	static Vector3 Cross(Vector3& v1, Vector3& v2);
	float Length();
	Vector3 Normalize();
	static float Angle(Vector3& v1, Vector3& v2);

	Vector3 operator/(double n) const;
	
	////////////////////////

	Vector3 v1, v2;
	cout << " v1 x,y,z : ";
	cin >> v1;

	cout << " v2, x,y,z : ";
	cin >> v2;

	cout << "v1 length : " << v1.length() << endl;
	cout << "v2 length : " << v2.length() << endl;

	cout << "v1 * 3 " << v1 * 3 << endl;
	cout << "v2 / 2 " << v2 / 2 << endl;

	cout << "v1.dot(v2)" << v1.Dot(v2) << endl;
	cout << "v1.cross(v2)" << v1.Cross(v2) << endl;
	cout << "angle(v1~v2) : " << v1.angle(v2) << endl;

	// static 이므로
	Vector3::Dot(v1, v2);
	Vector3::Cross(v1, v2);
	Vector3::Angle(v1, v2);

	////////////////////////
	
	ex >
	v1 x,y,z : 1 2 3
	v2 x,y,z : -4 -5 6
	v1 length : 3.7xxxx
	v2 length : 8.7xxxx

	v1 * 3 = 3 6 9
	3 * v1 = 3 6 9

	v2 / 2 = -2 -2.5 3
	v1.dot(v2) = 4
	v1.cross(v2) = 27 -18 3
	Angle(v1~v2) : 83.xxxxx

	ex>
	v1 -1 3 2
	v2 3 -4 1
	v1 + v2 = 2 -1 3
	v1 - v2 = -4 7 1
	v1.normalize = -0.267xxx, 0.801xxx, 0.534xxx
*/
#include "cVector3.h"

int main()
{
	cVector3 v1, v2;
	cout << "v1 x,y,z : ";
	cin >> v1;

	cout << "v2, x,y,z : ";
	cin >> v2;

	cout << endl;
	cout << "v1 length : " << v1.Length() << endl;
	cout << "v2 length : " << v2.Length() << endl;

	cout << endl;
	cout << "v1 * 3 " << v1 * 3 << endl;
	cout << "3 * v1 " << 3 * v1 << endl;

	cout << endl;
	cout << "v2 / 2 " << v2 / 2 << endl;
	cout << "v1.dot(v2) = " << v1.Dot(v2) << endl;
	cout << "v1.cross(v2) : " << v1.Cross(v2) << endl;
	cout << "angle(v1~v2) : " << v1.Angle(v2) << endl;

	cout << endl;
	cout << "v1 x,y,z : ";
	cin >> v1;

	cout << "v2, x,y,z : ";
	cin >> v2;

	cout << "v1 + v2 " << v1 + v2 << endl;
	cout << "v1 - v2 " << v1 - v2 << endl;
	cout << "v1.normalized = " << v1.Normalize();

	return 0;
}

