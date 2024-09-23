#include "classroom.h"

Student::Student(string name, int num)
{
	this->name = name;
	this->num = num;
}

Node<Student>* StudentTree::GetLargestChild(Node<Student>* currentNode)
{
	if (currentNode == nullptr)
		return nullptr;

	Node<Student>* leftChild = GetLargestChild(currentNode->left);
	Node<Student>* rightChild = GetLargestChild(currentNode->right);

	if (leftChild == nullptr)
		return rightChild;
	else if (rightChild == nullptr)
		return leftChild;
	else
		return (leftChild->data->num < rightChild->data->num) ? rightChild : leftChild;
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
	Node<Student>* parent = current;

	while (current)
	{
		if (targetNum == current->data->num)
			break;

		parent = current;

		if (targetNum < current->data->num)
			current = current->left;
		else
			current = current->right;
	}
	if (current->left != nullptr && current->right == nullptr)
	{
		current->left 
	}

	current->left = current->right = nullptr;
	delete current->data;
	delete current;
	return true;
}

void StudentTree::PrintStudents(Node<Student>* currentNode)
{
	if (currentNode == nullptr)
		return;

	if (currentNode->left)
		PrintStudents(currentNode->left);

	cout << "이름: " << currentNode->data->name << "\t번호: " << currentNode->data->num << endl;

	if (currentNode->right)
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