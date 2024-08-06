#include "account.h"

BankAccount::BankAccount(string& clientName, double clientBalance)
{
	name = clientName;
	balance = clientBalance;
}

void BankAccount::Show() const
{
	cout << "현재 잔액: $" << balance << endl;
}

void BankAccount::Deposit(double cash)
{
	balance += cash;
	Show();
}

void BankAccount::WithDraw(double cash)
{
	if (balance < cash)
	{
		cout << "출금 실패: 잔액이 부족합니다." << endl;
		return;
	}
	balance -= cash;
	Show();
}