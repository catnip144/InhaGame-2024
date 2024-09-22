// classroom.cpp
#include "classroom.h"

bool RollBook::RegisterStudent(string name, int num)
{
	Student* newStudent = new Student(name, num);
	Node<Student>* newNode = new Node<Student>();
	newNode->data = newStudent;
	Node<Student>* current = head;

	if (current == nullptr)
	{
		Node<Student>* newNode = new Node<Student>();
		newNode->data = newStudent;
		head = newNode;
		return true;
	}
	while (current)
	{
		Student* currentStudent = current->data;

		if (newStudent->num < currentStudent->num)
		{
			newNode->next = current;
			newNode->previous = current->previous;

			if (current->previous != nullptr)
				current->previous->next = newNode;
			else
				head = newNode;

			current->previous = newNode;
			return true;
		}
		else if (current->next == nullptr)
		{
			current->next = newNode;
			newNode->previous = current;
			return true;
		}
		current = current->next;
	}
	delete newStudent;
	delete newNode;
	return false;
}

bool RollBook::DeleteStudent(int targetNum)
{
	Node<Student>* current = head;

	while (current)
	{
		Student* currentStudent = current->data;
		if (currentStudent->num == targetNum)
		{
			if (current->next != nullptr)
				current->next->previous = current->previous;

			if (current->previous != nullptr)
				current->previous->next = current->next;
			else
				head = current->next;

			current->previous = nullptr;
			current->next = nullptr;
			delete current->data;
			delete current;
			return true;
		}
		current = current->next;
	}
	return false;
}

void RollBook::PrintStudentRoll()
{
	if (head == nullptr)
		cout << "등록된 학생이 없습니다." << endl;

	Node<Student>* current = head;

	while (current)
	{
		Student* currentStudent = current->data;
		cout << "이름: " << currentStudent->name << "\t번호: " << currentStudent->num << endl;
		current = current->next;
	}
}

Student* RollBook::SearchStudent(int targetNum)
{
	Node<Student>* current = head;

	while (current)
	{
		Student* currentStudent = current->data;
		if (currentStudent->num == targetNum)
		{
			cout << "이름: " << currentStudent->name << "\t번호: " << currentStudent->num << endl;
			return currentStudent;
		}
		current = current->next;
	}
	return NULL;
}

Student::Student(string name, int num)
{
	this->name = name;
	this->num = num;
}