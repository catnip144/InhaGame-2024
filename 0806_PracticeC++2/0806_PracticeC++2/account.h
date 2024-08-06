#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BankAccount
{
private:
	string name;
	double balance;

public:
	BankAccount(string& clientName, double clientBalance = 0.0);
	void Show() const;
	void Deposit(double cash);
	void WithDraw(double cash);
	const string& GetName() { return name; }
	const double& GetBalance() { return balance; }
};