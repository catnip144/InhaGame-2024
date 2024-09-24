#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student
{
	int num = -1;
	string name;
};

template<typename T>
class Node
{
public:
	T data;
	Node<T>* left;
	Node<T>* right;
};

class StudentTable
{
private:
	int size;
	int registered;
	void PrintStudentTree(Node<Student>* root);

public:
	StudentTable(int size);
	vector<Node<Student>*> table;

	int GetHash(int key);
	int StudentCount() { return registered; }
	bool RegisterStudent(string name, int num);
	bool DeleteStudent(Node<Student>*& curRoot, int num);
	void PrintStudents();
	Student SearchStudent(int num);
};

