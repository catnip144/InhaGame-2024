// classroom.h
#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
public:
	int num;
	string name;
	Student(string name, int num);
};

template<typename T>
class Node
{
public:
	T* data;
	Node<T>* previous;
	Node<T>* next;
};

class RollBook
{
private:
	Node<Student>* head = nullptr;
	int studentCount = 0;

public:
	bool RegisterStudent(string name, int num);
	bool DeleteStudent(int num);
	void PrintStudentRoll();
	Student* SearchStudent(int targetNum);
	Node<Student>* GetHead() { return head; }
};