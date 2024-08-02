/*
Q2.	점 p0(x0, y0)로부터 점 p1(x1, y1) 까지의 직선이 주어졌을 때
	점 p2(x2, y2)가 선의 왼쪽 또는 오른쪽에 있는지 판단할 수 있다.

	점 p0, p1, p2 를 입력받아 p2가 어디에 위치하는지 판단하는 프로그램을 작성하라.

	ex> p0, p1, p2 : 4.4 2 6.5 9.5 -5 4
	    >> p2 는 선의 왼쪽에 있다.

		p0, p1, p2 : 1 1 5 5 2 2
		>> p2 는 선상에 있다.

		p0, p1, p2 : 3.4 2 6.5 9.5 5 2.5
		>> p2 는 선의 오른쪽에 있다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

struct Pos {
	double x;
	double y;
};

int LinearEquation(Pos pos0, Pos pos1, Pos pos2);
int VectorCross(Pos pos0, Pos pos1, Pos pos2);

int main()
{
	Pos pos0, pos1, pos2;
	cout << "점 p0 x, y : ";
	cin >> pos0.x >> pos0.y;

	cout << "점 p1 x, y : ";
	cin >> pos1.x >> pos1.y;

	cout << "점 p2 x, y : ";
	cin >> pos2.x >> pos2.y;

	int dir = LinearEquation(pos0, pos1, pos2);
	//int dir = VectorCross(pos0, pos1, pos2);

	if (dir == -1)
		cout << "점 p2는 직선의 왼쪽에 있습니다.";
	else if (dir == 1)
		cout << "점 p2는 직선의 오른쪽에 있습니다.";
	else
		cout << "점 p2는 p0, p1 직선 위에 있습니다.";

	return 0;
}

int VectorCross(Pos pos0, Pos pos1, Pos pos2)
{
	/*
		오른손 법칙 기준

		Vector3 vector_cross(Vector3 a, Vector3 b)
		{
			return new Vector3(
				a.y * b.z - a.z * b.y,
				a.z * b.x - a.x * b.z,
				a.x * b.y - a.y * b.x
			);
		}
		2차원에서 벡터의 z값은 0이므로
		a.x * b.y - a.y * b.x 만 계산해준다.
	*/
	int result = (pos1.x - pos0.x)* (pos2.y - pos0.y) - (pos1.y - pos0.y) * (pos2.x - pos0.x);

	if (result > 0)
		return -1;

	else if (result < 0)
		return 1;

	return 0;
}

int LinearEquation(Pos pos0, Pos pos1, Pos pos2)
{
	if (pos0.x == pos1.x)
	{
		if (pos2.x < pos0.x)
			return -1;

		else if (pos2.x > pos0.x)
			return 1;

		return 0;
	}
	/*
		직선의 방정식
		y - y1 = (y2 - y1) / (x2 - x1) * (x - x1) 
	*/
	//두 점을 지나는 직선의 방정식에 pos2 x 좌표를 대입
	double lineY = (double)(pos1.y - pos0.y) / (pos1.x - pos0.x) * (pos2.x - pos0.x) + pos0.y;

	if (lineY < pos2.y)
		return -1;

	else if (lineY > pos2.y)
		return 1;

	return 0;
}