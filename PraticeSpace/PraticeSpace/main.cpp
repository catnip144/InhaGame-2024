#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Test
{
public:
	int a;
	Test* parent;
};

int main()
{
	Test* A = new Test();
	Test* B = new Test();
	A->a = 10;
	B->a = 20;

	vector<Test*> listA;
	listA.push_back(A);

	for (int i = 0; i < 1; i++)
	{
		Test* temp = listA.back();
		B->parent = temp;
	}
	cout << B->parent->a;
	return 0;
}