/*
	key: 학번
	value: 이름 
	이전에 구현했던 학생부 관리 프로그램을 이진트리를 이용한 구조로 변경하라.
	입력(이진트리구성) / 삭제 / 출력 / 검색 (번호로)
*/
#include "classroom.h"

int main()
{
	StudentTree tree;

	int menuNum = 0;

	string studentName;
	int studentNum, targetNum;

	while (menuNum != -1)
	{
		cout << "\n====== 출석부 프로그램 ======\n";
		cout << "1. 학생 등록\n2. 학생 삭제\n3. 학생 출력\n4. 학생 검색\nq. 종료\n";
		cout << ">> ";
		cin >> menuNum;

		switch (menuNum)
		{
		case 1:
			cout << "학생 이름: ";
			cin >> studentName;

			cout << "학생 번호: ";
			cin >> studentNum;

			if (tree.RegisterStudent(studentName, studentNum))
				cout << "학생이 등록되었습니다." << endl;
			else
				cout << "등록에 실패했습니다." << endl;
			break;

		case 2:
			cout << "삭제하려는 학생의 번호: ";
			cin >> targetNum;

			if (tree.DeleteStudent(tree.GetRoot(), targetNum))
				cout << "삭제 완료했습니다." << endl;
			else if (tree.GetRoot() == nullptr)
				cout << "등록된 학생이 없습니다." << endl;
			else
				cout << "해당 번호의 학생이 존재하지 않습니다." << endl;
			break;

		case 3:
			tree.PrintStudents(tree.GetRoot());
			break;

		case 4:
		{
			cout << "검색하려는 학생의 번호: ";
			cin >> targetNum;

			Student* targetStudent = tree.SearchStudent(targetNum);

			if (!targetStudent)
				cout << "해당 번호의 학생이 존재하지 않습니다." << endl;
			else
				cout << "이름: " << targetStudent->name << "\t번호: " << targetStudent->num << endl;
		}
			break;

		default:
			menuNum = -1;
			break;
		}
	}
	return 0;
}

