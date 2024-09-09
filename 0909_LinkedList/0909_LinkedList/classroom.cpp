#include "classroom.h"

void RollBook::RegisterStudent()
{
	Student* newStudent = new Student();

	cout << "학생 이름: ";
	cin >> newStudent->name;
	
	cout << "학생 번호: ";
	cin >> newStudent->num;

	if (head == nullptr)
	{
		head = newStudent;
		return;
	}
	Student* current = head;

	while (current->next)
		current = current->next;
	
	current->next = newStudent;
	cout << "학생이 등록되었습니다." << endl;
}

void RollBook::DeleteStudent()
{
	if (head == nullptr)
	{
		cout << "등록된 학생이 없습니다." << endl;
		return;
	}
	int targetNum;
	bool deletionSuccess = false;

	cout << "삭제하려는 학생의 번호: ";
	cin >> targetNum;

	Student* current = head;
	Student* previous = nullptr;

	while (current)
	{
		if (current->num == targetNum)
		{
			if (previous)
				previous->next = current->next;
			else
				head = current->next;

			current->next = nullptr;
			delete current;

			deletionSuccess = true;
			break;
		}
		previous = current;
		current = current->next;
	}
	if (deletionSuccess)
		cout << "삭제 완료했습니다." << endl;
	else
		cout << "해당 번호의 학생이 존재하지 않습니다." << endl;
}

void RollBook::PrintStudentRoll()
{
	if (head == nullptr)
	{
		cout << "등록된 학생이 없습니다." << endl;
		return;
	}
	Student* current = head;
	cout << endl;

	while (current)
	{
		cout << "이름: " << current->name << "\t번호: " << current->num << endl;
		current = current->next;
	}
}

Student* RollBook::SearchStudent()
{
	if (head == nullptr)
	{
		cout << "등록된 학생이 없습니다." << endl;
		return nullptr;
	}
	int targetNum;
	cout << "검색하려는 학생의 번호: ";
	cin >> targetNum;

	Student* current = head;

	while (current)
	{
		if (current->num == targetNum)
		{
			cout << "이름: " << current->name << "\t번호: " << current->num << endl;
			return current;
		}
		current = current->next;
	}
	cout << "해당 번호의 학생이 존재하지 않습니다." << endl;
	return nullptr;
}
