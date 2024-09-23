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
	Node<T>* left;
	Node<T>* right;
};

class StudentTree
{
private:
	Node<Student>* root = nullptr;
	Node<Student>* GetLargestChild(Node<Student>* currentNode);

public:
	Node<Student>* GetRoot() { return root; }
	bool RegisterStudent(string name, int num);
	bool DeleteStudent(int num);
	void PrintStudents(Node<Student>* currentNode);
	Student* SearchStudent(int targetNum);
};

