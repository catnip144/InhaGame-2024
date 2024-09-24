/*
	Q. 학생부 관리 프로그램을 해시법을 이용하여 작성하라.
	입력 / 삭제 / 출력 / 검색
*/
#include "classroom.h"

int main()
{
	StudentTable hashtable(13);

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

			if (hashtable.RegisterStudent(studentName, studentNum))
				cout << "학생이 등록되었습니다." << endl;
			else
				cout << "등록에 실패했습니다." << endl;
			break;

		case 2:
		{
			cout << "삭제하려는 학생의 번호: ";
			cin >> targetNum;

			Node<Student>*& root = hashtable.table[hashtable.GetHash(targetNum)];

			if (hashtable.StudentCount() == 0)
				cout << "등록된 학생이 없습니다." << endl;
			else if (hashtable.DeleteStudent(root, targetNum))
				cout << "삭제 완료했습니다." << endl;
			else
				cout << "해당 번호의 학생이 존재하지 않습니다." << endl;
			break;
		}
		case 3:
			hashtable.PrintStudents();
			break;

		case 4:
		{
			cout << "검색하려는 학생의 번호: ";
			cin >> targetNum;

			Student targetStudent = hashtable.SearchStudent(targetNum);

			if (targetStudent.num == -1)
				cout << "해당 번호의 학생이 존재하지 않습니다." << endl;
			else
				cout << "이름: " << targetStudent.name << "\t번호: " << targetStudent.num << endl;
		}
		break;

		default:
			menuNum = -1;
			break;
		}
	}
	return 0;
}

