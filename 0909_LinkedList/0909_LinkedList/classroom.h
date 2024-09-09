#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	int num;
	string name;
	Student* next;
};

class RollBook
{
private:
	Student* head = NULL;

public:
	void RegisterStudent();
	void DeleteStudent();
	void PrintStudentRoll();
	Student* SearchStudent();
};