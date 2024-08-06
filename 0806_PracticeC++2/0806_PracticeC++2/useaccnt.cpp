#include "account.h"
/*
	Q2. p.705 1번
		예금주 설정, 예금 입,출금 함수, 잔액 표시 함수

		1. 예금 새로 만들기
			예금주 이름, 초기 임금액
		2. 예금 입력
			2.1 잔액 표시
		3. 예금 출력
			3.1 잔액 표시

		4. 총 예금주 명단 출력
		5. 총 예금액 출력
*/

void CreateNewAccount(vector<BankAccount>& accounts);
void Deposit(vector<BankAccount>& accounts);
void Withdraw(vector<BankAccount>& accounts);
void ShowAccountBalance(vector<BankAccount>& accounts);
void PrintAllAccounts(vector<BankAccount>& accounts);
void GetTotalBalance(vector<BankAccount>& accounts);
BankAccount* FindAccount(vector<BankAccount>& accounts, string& name);

int main()
{
	vector<BankAccount> accounts;
	int menu = 0;

	while (menu != -1)
	{
		cout << "\n==== 예금 메뉴 ====\n";
		cout << "1. 예금 새로 만들기\n";
		cout << "2. 예금\n";
		cout << "3. 출금\n";
		cout << "4. 총 예금주 명단\n";
		cout << "5. 총 예금액 출력\n";
		cout << "0. 종료\n";
		cout << ">> ";
		
		cin >> menu;
		cout << endl;

		switch (menu)
		{
		case 1:
			CreateNewAccount(accounts);
			break;

		case 2:
			Deposit(accounts);
			break;

		case 3:
			Withdraw(accounts);
			break;

		case 4:
			PrintAllAccounts(accounts);
			break;

		case 5:
			GetTotalBalance(accounts);
			break;

		default:
			menu = -1;
			break;
		}
	}
	return 0;
}

void CreateNewAccount(vector<BankAccount>& accounts)
{
	string name;
	double balance;

	cout << "예금주 이름: ";
	cin >> name;

	BankAccount* duplicateAccount = FindAccount(accounts, name);
	if (duplicateAccount)
	{
		cout << "동일한 이름의 계정이 존재합니다." << endl;
		return;
	}
	cout << "초기 입금액: ";
	cin >> balance;

	BankAccount newAccount(name, balance);
	accounts.push_back(newAccount);
}

void Deposit(vector<BankAccount>& accounts)
{
	string name;
	double balance;

	cout << "예금주 이름: ";
	cin >> name;

	BankAccount* targetAccount = FindAccount(accounts, name);

	if (!targetAccount)
	{
		cout << "대상을 찾지 못했습니다." << endl;
		return;
	}

	cout << "입금액: ";
	cin >> balance;
	targetAccount->Deposit(balance);
}

void Withdraw(vector<BankAccount>& accounts)
{
	string name;
	double balance;

	cout << "예금주 이름: ";
	cin >> name;

	BankAccount* targetAccount = FindAccount(accounts, name);

	if (!targetAccount)
	{
		cout << "대상을 찾지 못했습니다." << endl;
		return;
	}
	cout << "출금액: ";
	cin >> balance;
	targetAccount->WithDraw(balance);
}

void ShowAccountBalance(vector<BankAccount>& accounts)
{
	string name;
	double balance;

	cout << "예금주 이름: ";
	cin >> name;

	BankAccount* targetAccount = FindAccount(accounts, name);

	if (!targetAccount)
	{
		cout << "대상을 찾지 못했습니다." << endl;
		return;
	}
	targetAccount->Show();
}

BankAccount* FindAccount(vector<BankAccount>& accounts, string& name)
{
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts[i].GetName() == name)
			return &accounts[i];
	}
	return NULL;
}

void PrintAllAccounts(vector<BankAccount>& accounts)
{
	cout << "\n==== 예금주 명단 ====\n";
	for (int i = 0; i < accounts.size(); i++)
		cout << accounts[i].GetName() << endl;
}

void GetTotalBalance(vector<BankAccount>& accounts)
{
	int totalBalance = 0;
	for (int i = 0; i < accounts.size(); i++)
		totalBalance += accounts[i].GetBalance();

	cout << "총 예금액: $" << totalBalance << endl;
}