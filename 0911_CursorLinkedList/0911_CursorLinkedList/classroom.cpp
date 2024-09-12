// classroom.cpp
#include "classroom.h"

RollBook::RollBook()
{
	nodes = new Node<Student>[MAX_STUDENTS];
}

bool RollBook::RegisterStudent(string name, int num)
{
	Student* newStudent = new Student(name, num);

	if (cursor == -1)
	{
		nodes[0].data = newStudent;
		cursor = 0;
		head = 0;
		return true;
	}
	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		if (cursor == i)
			continue;

		if (nodes[i].next == -1)
		{
			nodes[cursor].next = i;
			nodes[i].data = newStudent;
			cursor = i;
			return true;
		}
	}
	delete newStudent;
	return false;
}

bool RollBook::DeleteStudent(int targetNum)
{
	int curIdx = head;
	int prevIdx = -1;

	while (curIdx != -1)
	{
		Student* currentStudent = nodes[curIdx].data;

		if (currentStudent->num == targetNum)
		{
			if (prevIdx != -1)
				nodes[prevIdx].next = nodes[curIdx].next;

			if (curIdx == head)
				head = nodes[curIdx].next;

			if (curIdx == cursor)
				cursor = prevIdx;

			nodes[curIdx].next = -1;
			return true;
		}
		prevIdx = curIdx;
		curIdx = nodes[curIdx].next;
	}
	return false;
}

void RollBook::PrintStudentRoll()
{
	if (head == -1)
		cout << "등록된 학생이 없습니다." << endl;

	int curIdx = head;
	while (curIdx != -1)
	{
		Student* currentStudent = nodes[curIdx].data;

		cout << "이름: " << currentStudent->name << "\t번호: " << currentStudent->num << endl;
		curIdx = nodes[curIdx].next;
	}
}

Student* RollBook::SearchStudent(int targetNum)
{
	int curIdx = head;
	while (curIdx != -1)
	{
		Student* currentStudent = nodes[curIdx].data;
		if (currentStudent->num == targetNum)
		{
			cout << "이름: " << currentStudent->name << "\t번호: " << currentStudent->num << endl;
			return currentStudent;
		}
		curIdx = nodes[curIdx].next;
	}
	cout << "해당 번호의 학생이 존재하지 않습니다." << endl;
	return NULL;
}

Student::Student(string name, int num)
{
	this->name = name;
	this->num = num;
}