#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct PizzaType {
	string brandName;
	float diameter;
	float weight;
};

void GetPizzaInfo1()
{
	PizzaType pizza;

	cout << "피자 회사의 이름을 입력 : ";
	getline(cin, pizza.brandName);

	cout << "피자의 지름을 입력 : ";
	cin >> pizza.diameter;

	cout << "피자의 중량을 입력 : ";
	cin >> pizza.weight;

	cout << endl;
	cout << "피자 회사 이름 : " << pizza.brandName << endl;
	cout << "피자 지름: " << pizza.diameter << endl;
	cout << "피자 중량 : " << pizza.weight << endl << endl;
}
void GetPizzaInfo2()
{
	PizzaType* pizza = new PizzaType;

	cin.get();
	cout << "피자 회사의 이름을 입력 : ";
	getline(cin, pizza[0].brandName);

	cout << "피자의 지름을 입력 : ";
	cin >> pizza[0].diameter;

	cout << "피자의 중량을 입력 : ";
	cin >> pizza[0].weight;

	cout << endl;
	cout << "피자 지름: " << pizza[0].diameter << endl;
	cout << "피자 회사 이름 : " << pizza[0].brandName << endl;
	cout << "피자 중량 : " << pizza[0].weight << endl << endl;
}

int main()
{
	GetPizzaInfo1();
	GetPizzaInfo2();
}
