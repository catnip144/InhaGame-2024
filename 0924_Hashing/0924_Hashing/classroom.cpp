#include "classroom.h"

StudentTable::StudentTable(int size)
{
	this->size = size;
	table = vector<Node<Student>*>(size, nullptr);
	registered = 0;
}

int StudentTable::GetHash(int key)
{
	return key % size;
}

bool StudentTable::RegisterStudent(string name, int num)
{
	Node<Student>* newNode = new Node<Student>;
	Student newStudent;

	newStudent.name = name;
	newStudent.num = num;
	newNode->data = newStudent;

	Student search = SearchStudent(num);
	if (search.num != -1)
		return false;

	int hash = GetHash(num);

	if (registered == 0 || table[hash] == nullptr)
	{
		table[hash] = newNode;
		++registered;
		return true;
	}
	Node<Student>* current = table[hash];
	while (1)
	{
		if (num < current->data.num)
		{
			if (current->left == nullptr)
			{
				current->left = newNode;
				++registered;
				return true;
			}
			current = current->left;
		}
		else
		{
			if (current->right == nullptr)
			{
				current->right = newNode;
				++registered;
				return true;
			}
			current = current->right;
		}
	}
	delete newNode;
	return false;
}

bool StudentTable::DeleteStudent(Node<Student>*& curRoot, int num)
{
	if (curRoot == nullptr)
		return false;

	if (curRoot->data.num < num)
		return DeleteStudent(curRoot->right, num);
	else if (curRoot->data.num > num)
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
			DeleteStudent(curRoot->left, largestChild->data.num);
		}
		else if (curRoot->left)
		{
			Node<Student>* temp = curRoot;
			curRoot = curRoot->left;

			int hash = GetHash(num);
			if (table[hash] == temp)
				table[hash] = curRoot;

			delete temp;
		}
		else if (curRoot->right)
		{
			Node<Student>* temp = curRoot;
			curRoot = curRoot->right;

			int hash = GetHash(num);
			if (table[hash] == temp)
				table[hash] = curRoot;

			delete temp;
		}
		--registered;
		return true;
	}
	return false;
}

void StudentTable::PrintStudents()
{
	for (const auto& node : table)
	{
		PrintStudentTree(node);
	}
}

void StudentTable::PrintStudentTree(Node<Student>* root)
{
	if (root == nullptr)
		return;

	PrintStudentTree(root->left);
	cout << "이름: " << root->data.name << "\t번호: " << root->data.num << endl;
	PrintStudentTree(root->right);
}

Student StudentTable::SearchStudent(int num)
{
	int hash = GetHash(num);
	Node<Student>* current = table[hash];

	while (current)
	{
		if (num == current->data.num)
			return current->data;
		else if (num < current->data.num)
			current = current->left;
		else
			current = current->right;
	}
	return Student{};
}