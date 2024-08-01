#include <iostream>
#include "namesp.h"

using std::cout;
using std::cin;
using std::endl;

namespace pers
{
	void GetPerson(Person& rp)
	{
		cout << "이름을 입력하십시오: ";
		cin >> rp.fname;

		cout << "성씨를 입력하십시오: ";
		cin >> rp.lname;
	}
	void ShowPerson(Person& rp)
	{
		cout << rp.lname << ", " << rp.fname;
	}
}

namespace debts
{
	using namespace pers;

	void GetDebt(Debt& rd)
	{
		GetPerson(rd.name);
		cout << "부채를 입력하십시오: ";
		cin >> rd.amount;
	}
	void ShowDebt(Debt& rd)
	{
		ShowPerson(rd.name);
		cout << ": $" << rd.amount << endl;
	}
	double SumDebts(const Debt ar[], int n)
	{
		double total = 0;
		for (int i = 0; i < n; i++)
			total += ar[i].amount;
		return total;
	}
}