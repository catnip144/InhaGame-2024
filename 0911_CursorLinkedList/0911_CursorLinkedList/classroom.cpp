#include "classroom.h"

RollBook::RollBook()
{
	students = vector<Student*>(MAX_STUDENTS);
}

void RollBook::RegisterStudent()
{
	Student* newStudent = new Student();

	cout << "�л� �̸�: ";
	cin >> newStudent->name;

	cout << "�л� ��ȣ: ";
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
		cout << "�л��� ��ϵǾ����ϴ�." << endl;
	else
	{
		cout << "��Ͽ� �����߽��ϴ�. ��� ������ �ִ� �л� ���� " << MAX_STUDENTS << "�Դϴ�." << endl;
		delete newStudent;
	}
}

void RollBook::DeleteStudent()
{
	int targetNum;
	cout << "�����Ϸ��� �л��� ��ȣ: ";
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
		cout << "���� �Ϸ��߽��ϴ�." << endl;
	else if (head == -1)
		cout << "��ϵ� �л��� �����ϴ�." << endl;
	else
		cout << "�ش� ��ȣ�� �л��� �������� �ʽ��ϴ�." << endl;
}

void RollBook::PrintStudentRoll()
{
	if (head == -1)
		cout << "��ϵ� �л��� �����ϴ�." << endl;

	int curIdx = head;
	while (curIdx != -1)
	{
		cout << "�̸�: " << students[curIdx]->name << "\t��ȣ: " << students[curIdx]->num << endl;
		curIdx = students[curIdx]->next;
	}
}

Student* RollBook::SearchStudent()
{
	int targetNum;
	cout << "�˻��Ϸ��� �л��� ��ȣ: ";
	cin >> targetNum;

	int curIdx = head;
	while (curIdx != -1)
	{
		if (students[curIdx]->num == targetNum)
		{
			cout << "�̸�: " << students[curIdx]->name << "\t��ȣ: " << students[curIdx]->num << endl;
			return students[curIdx];
		}
		curIdx = students[curIdx]->next;
	}
	cout << "�ش� ��ȣ�� �л��� �������� �ʽ��ϴ�." << endl;
	return nullptr;
}

Student::Student()
{

}
