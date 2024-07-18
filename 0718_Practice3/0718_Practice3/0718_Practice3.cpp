#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/* 305p 7, 8번
구조체, 동적메모리할당, Vector / Array
*/

struct car {
	string company;
	int year;
};

void GetCarInfo()
{
	int totalCars;
	cout << "몇 대의 차를 목록으로 관리하시겠습니까? ";
	cin >> totalCars;

	vector<car> cars(totalCars);

	for (int i = 0; i < totalCars; i++)
	{
		cout << "자동차 #" << (i + 1) << ':' << endl;
		cout << "제작업체: ";
		cin >> cars[i].company;
		cin.get();

		cout << "제작년도: ";
		cin >> cars[i].year;
		cout << endl;
	}
	cout << "현재 귀하가 보유하고 있는 자동차 목록은 다음과 같습니다." << endl;
	for (int i = 0; i < totalCars; i++)
	{
		cout << cars[i].year << "년형 " << cars[i].company << endl;
	}
	cout << endl;
}

void GetWordsUntilDone()
{
	int totalWords = 0;
	string word;
	cout << "영어 단어들을 입력하십시오 (끝내려면 done을 입력):" << endl;

	while (1)
	{
		cin >> word;
		if (word == "done") break;
		totalWords++;
	}
	cout << "총 " << totalWords << " 단어가 입력되었습니다.";
}

int main()
{
	GetCarInfo();
	GetWordsUntilDone();
}
