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
	T* data = nullptr;
	Node<T>* left = nullptr;
	Node<T>* right = nullptr;
};

class StudentTree
{
private:
	Node<Student>* root = nullptr;

public:
	Node<Student>*& GetRoot() { return root; }
	bool RegisterStudent(string name, int num);
	bool DeleteStudent(Node<Student>*& curRoot, int num);
	void PrintStudents(Node<Student>* currentNode);
	Student* SearchStudent(int targetNum);
};

