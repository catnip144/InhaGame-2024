#pragma once

#include <string>

namespace pers
{
	struct Person
	{
		std::string fname;
		std::string lname;
	};
	void GetPerson(Person &);
	void ShowPerson(Person &);
}

namespace debts
{
	using namespace pers;
	struct Debt
	{
		Person name;
		double amount = 0;
	};
	void GetDebt(Debt&);
	void ShowDebt(const Debt&);
	double SumDebts(const Debt ar[], int n);
}