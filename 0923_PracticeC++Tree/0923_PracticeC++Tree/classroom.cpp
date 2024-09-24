#include "classroom.h"

Student::Student(string name, int num)
{
	this->name = name;
	this->num = num;
}

bool StudentTree::RegisterStudent(string name, int num)
{
	Student* newStudent = new Student(name, num);
	Node<Student>* newNode = new Node<Student>();
	newNode->data = newStudent;
	Node<Student>* current = root;

	if (root == nullptr)
	{
		root = newNode;
		return true;
	}
	while (1)
	{
		if (num < current->data->num)
		{
			if (current->left == nullptr)
			{
				current->left = newNode;
				return true;
			}
			current = current->left;
		}
		else
		{
			if (current->right == nullptr)
			{
				current->right = newNode;
				return true;
			}
			current = current->right;
		}
	}
	delete newStudent;
	delete newNode;
	return false;
}

bool StudentTree::DeleteStudent(Node<Student>*& curRoot, int num)
{
	if (curRoot == nullptr)
		return false;

	if (curRoot->data->num < num)
		return DeleteStudent(curRoot->right, num);
	else if (curRoot->data->num > num)
		return DeleteStudent(curRoot->left, num);
	else
	{
		if (curRoot->left == nullptr && curRoot->right == nullptr)
		{
			Node<Student>* temp = curRoot;
			curRoot = nullptr;
			delete temp;
		}
		else if (curRoot->left && curRoot->right)
		{
			Node<Student>* largestChild = curRoot->left;
			while (largestChild->right)
				largestChild = largestChild->right;

			curRoot->data = largestChild->data;
			DeleteStudent(curRoot->left, largestChild->data->num);
		}
		else if (curRoot->left)
		{
			Node<Student>* temp = curRoot;
			curRoot = curRoot->left;

			if (root == temp)
				root = curRoot;
			
			delete temp;
		}
		else if (curRoot->right)
		{
			Node<Student>* temp = curRoot;
			curRoot = curRoot->right;

			if (root == temp)
				root = curRoot;

			delete temp;
		}
		return true;
	}
	return false;
}

void StudentTree::PrintStudents(Node<Student>* currentNode)
{
	if (currentNode == nullptr)
		return;

	PrintStudents(currentNode->left);
	cout << "이름: " << currentNode->data->name << "\t번호: " << currentNode->data->num << endl;
	PrintStudents(currentNode->right);
}

Student* StudentTree::SearchStudent(int targetNum)
{
	Node<Student>* current = root;

	while (current)
	{
		if (targetNum == current->data->num)
			return current->data;
		else if (targetNum < current->data->num)
			current = current->left;
		else
			current = current->right;
	}
	return nullptr;
}