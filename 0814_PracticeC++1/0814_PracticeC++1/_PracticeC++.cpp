/*

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Fruit
{
public:
	Fruit() { cout << "> Fruit Constructor" << endl; }
	virtual void name() { cout << "Fruit" << endl; }

};

class Apple : public Fruit
{
public:
	Apple() { cout << ">> Apple Constructor" << endl; }
	virtual void name() { cout << "Apple" << endl; }
};

class Banana : public Fruit
{
public:
	Banana() { cout << ">> Banana Constructor" << endl; }
	~Banana() {}
	virtual void name() { cout << "Banana" << endl; }
};

//int main()
//{
//	Fruit* pf1 = new Apple;
//	Fruit* pf2 = new Banana;
//
//	pf1->name();
//	pf2->name();
//
//	return 0;
//}
//
