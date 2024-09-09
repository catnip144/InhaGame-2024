#include "classroom.h"

void RollBook::RegisterStudent()
{
	Student* newStudent = new Student();

	cout << "�л� �̸�: ";
	cin >> newStudent->name;
	
	cout << "�л� ��ȣ: ";
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
	cout << "�л��� ��ϵǾ����ϴ�." << endl;
}

void RollBook::DeleteStudent()
{
	if (head == nullptr)
	{
		cout << "��ϵ� �л��� �����ϴ�." << endl;
		return;
	}
	int targetNum;
	bool deletionSuccess = false;

	cout << "�����Ϸ��� �л��� ��ȣ: ";
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
		cout << "���� �Ϸ��߽��ϴ�." << endl;
	else
		cout << "�ش� ��ȣ�� �л��� �������� �ʽ��ϴ�." << endl;
}

void RollBook::PrintStudentRoll()
{
	if (head == nullptr)
	{
		cout << "��ϵ� �л��� �����ϴ�." << endl;
		return;
	}
	Student* current = head;
	cout << endl;

	while (current)
	{
		cout << "�̸�: " << current->name << "\t��ȣ: " << current->num << endl;
		current = current->next;
	}
}

Student* RollBook::SearchStudent()
{
	if (head == nullptr)
	{
		cout << "��ϵ� �л��� �����ϴ�." << endl;
		return nullptr;
	}
	int targetNum;
	cout << "�˻��Ϸ��� �л��� ��ȣ: ";
	cin >> targetNum;

	Student* current = head;

	while (current)
	{
		if (current->num == targetNum)
		{
			cout << "�̸�: " << current->name << "\t��ȣ: " << current->num << endl;
			return current;
		}
		current = current->next;
	}
	cout << "�ش� ��ȣ�� �л��� �������� �ʽ��ϴ�." << endl;
	return nullptr;
}
