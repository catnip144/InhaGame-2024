#include "account.h"

BankAccount::BankAccount(string& clientName, double clientBalance)
{
	name = clientName;
	balance = clientBalance;
}

void BankAccount::Show() const
{
	cout << "���� �ܾ�: $" << balance << endl;
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
		cout << "��� ����: �ܾ��� �����մϴ�." << endl;
		return;
	}
	balance -= cash;
	Show();
}