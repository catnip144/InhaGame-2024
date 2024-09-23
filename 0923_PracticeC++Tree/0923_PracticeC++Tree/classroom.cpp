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

bool StudentTree::DeleteStudent(int targetNum)
{
	Node<Student>* current = root;
	Node<Student>* parent = nullptr;

	while (current)
	{
		if (targetNum == current->data->num) break;
		parent = current;

		if (targetNum < current->data->num)
			current = current->left;
		else
			current = current->right;
	}
	if (current == nullptr)
		return false;

	int childCount = (current->left != nullptr) + (current->right != nullptr);

	switch (childCount)
	{
	case 0:
	{
		if (current == root)
			root = nullptr;
		else if (parent->left == current)
			parent->left = nullptr;
		else
			parent->right = nullptr;

		delete current->data;
		delete current;
	}
		break;
	case 1:
	{
		bool isRoot = current == root;
		Node<Student>* cached = current;
		Node<Student>*& temp = current;

		if (temp->left)
			temp = temp->left;
		else
			temp = temp->right;

		delete cached;
		if (isRoot) root = temp;
	}
		break;
	case 2:
	{
		parent = current;
		Node<Student>* largestChild = current->left;

		while (largestChild->right)
		{
			parent = largestChild;
			largestChild = largestChild->right;
		}
		current->data = largestChild->data;

		Node<Student>*& temp = largestChild;
		if (temp->left)
			temp = temp->left;
		else
			parent->left = nullptr;

		delete largestChild;
	}
		break;
	}
	return true;
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