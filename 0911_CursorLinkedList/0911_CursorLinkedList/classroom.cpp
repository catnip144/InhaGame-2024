#include "classroom.h"

RollBook::RollBook()
{
	students = vector<Student*>(MAX_STUDENTS);
}

void RollBook::RegisterStudent()
{
	Student* newStudent = new Student();

	cout << "학생 이름: ";
	cin >> newStudent->name;

	cout << "학생 번호: ";
	cin >> newStudent->num;

	if (cursor == -1)
	{
		students[0] = newStudent;
		cursor = 0;
		head = 0;
		return;
	}
	bool isRegistered = true;

	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		if (cursor == i)
			continue;

		if (students[i]->next == -1)
		{
			students[cursor]->next = i;
			students[i] = newStudent;
			cursor = i;

			isRegistered = true;
			break;
		}
	}
	if (isRegistered)
		cout << "학생이 등록되었습니다." << endl;
	else
	{
		cout << "등록에 실패했습니다. 등록 가능한 최대 학생 수는 " << MAX_STUDENTS << "입니다." << endl;
		delete newStudent;
	}
}

void RollBook::DeleteStudent()
{
	int targetNum;
	cout << "삭제하려는 학생의 번호: ";
	cin >> targetNum;

	int curIdx = head;
	int prevIdx = -1;
	bool deletionSuccess = false;

	while (curIdx != -1)
	{
		if (students[curIdx]->num == targetNum)
		{
			if (prevIdx != -1)
				students[prevIdx]->next = students[curIdx]->next;

			if (curIdx == head)
				head = students[curIdx]->next;

			if (curIdx == cursor)
				cursor = prevIdx;

			students[curIdx]->next = -1;

			deletionSuccess = true;
			break;
		}
		prevIdx = curIdx;
		curIdx = students[curIdx]->next;
	}
	if (deletionSuccess)
		cout << "삭제 완료했습니다." << endl;
	else if (head == -1)
		cout << "등록된 학생이 없습니다." << endl;
	else
		cout << "해당 번호의 학생이 존재하지 않습니다." << endl;
}

void RollBook::PrintStudentRoll()
{
	if (head == -1)
		cout << "등록된 학생이 없습니다." << endl;

	int curIdx = head;
	while (curIdx != -1)
	{
		cout << "이름: " << students[curIdx]->name << "\t번호: " << students[curIdx]->num << endl;
		curIdx = students[curIdx]->next;
	}
}

Student* RollBook::SearchStudent()
{
	int targetNum;
	cout << "검색하려는 학생의 번호: ";
	cin >> targetNum;

	int curIdx = head;
	while (curIdx != -1)
	{
		if (students[curIdx]->num == targetNum)
		{
			cout << "이름: " << students[curIdx]->name << "\t번호: " << students[curIdx]->num << endl;
			return students[curIdx];
		}
		curIdx = students[curIdx]->next;
	}
	cout << "해당 번호의 학생이 존재하지 않습니다." << endl;
	return nullptr;
}

Student::Student()
{

}
