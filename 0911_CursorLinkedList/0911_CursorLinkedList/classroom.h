// classroom.h
#pragma once
#include <iostream>
#include <string>
#include <vector>

#define MAX_STUDENTS 10

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
	int next = -1;
};

class RollBook
{
private:
	int cursor = -1;
	int head = -1;
	Node<Student>* nodes;

public:
	RollBook();
	int GetHead() { return head; }
	bool RegisterStudent(string name, int num);
	bool DeleteStudent(int num);
	void PrintStudentRoll();
	Student* SearchStudent(int targetNum);
};