#pragma once
#include <iostream>
#include <string>
#include <vector>

#define MAX_STUDENTS 10

using namespace std;

class Student
{
public:
	Student();
	int num;
	string name;
	int next = -1;
};

class RollBook
{
private:
	int cursor = -1;
	int head = -1;
	vector<Student*> students;

public:
	RollBook();
	void RegisterStudent();
	void DeleteStudent();
	void PrintStudentRoll();
	Student* SearchStudent();
};