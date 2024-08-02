/*
Q1.	학교에 100개의 사물함과 100명의 학생이 있다.
	모든 사물함이 첫 날에는 닫혀 있다.
	학생이 교실로 들어가면서
		s1 이라는 첫 번째 학생은 모든 사물함을 연다.
		s2 라는 두 번째 학생은 L2 시작하여 1개씩 건너 뛰면서 사물함을 닫는다.
		s3 라는 세 번째 학생은 L3 부터 시작하여 2개씩 건너뛰면서 사물함의 상태를 변경한다.
		s4 라는 세 번째 학생은 L4 부터 시작하여 3개씩 건너뛰면서 사물함의 상태를 변경한다.

		...
		학생 s100이 L100 사물함을 변경할 때 까지 계속 된다.
	모든 학생이 교실을 통과하고 난 다음, 어떤 사물함이 열려있는지
	열려 있는 모든 사물함의 번호를 출력하는 프로그램을 작성하라.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void CloseLocker(vector<bool>& locker, int studentNum)
{
	for (int i = studentNum - 1; i < locker.size(); i += studentNum)
	{
		locker[i] = !locker[i];
	}
}

int main()
{
	int n;
	cin >> n;

	vector<bool> locker(100, true);
	
	for (int studentNum = 2; studentNum <= n; studentNum++)
	{
		CloseLocker(locker, studentNum);
		cout << studentNum << ": ";
		for (int i = 0; i < 100; i++)
			cout << locker[i] << " ";
		cout << endl;
	}
	//for (int i = 0; i < 100; i++)
	//{
	//	if (locker[i])
	//		cout << i + 1 << "번째 사물함은 열려있습니다." << endl;
	//}
	return 0;
}

