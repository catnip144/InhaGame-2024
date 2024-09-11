/*
	Q1. 커서를 이용한 링크드 리스트를 구현하라.
	학생 번호, 이름으로 입력/삭제/출력/검색 기능을 가진 학생부를 구현하시오.
	(이전에 구현했던 싱글 링크드 리스트를 배열과 커서를 이용한 개념으로 수정하라.)
*/
#include "classroom.h"

using namespace std;

int main()
{
	RollBook roll;
	int menuNum;

	while (1)
	{
		cout << "\n====== 출석부 프로그램 ======\n";
		cout << "1. 학생 등록\n2. 학생 삭제\n3. 학생 출력\n4. 학생 검색\nq. 종료\n";
		cout << ">> ";
		cin >> menuNum;

		switch (menuNum)
		{
		case 1:
			roll.RegisterStudent();
			break;

		case 2:
			roll.DeleteStudent();
			break;

		case 3:
			roll.PrintStudentRoll();
			break;

		case 4:
			roll.SearchStudent();
			break;

		default:
			return 0;
		}
	}
	return 0;
}

