#include <iostream>
#include "brass.h"

const int CLIENTS = 4;

int main()
{
	//Brass Piggy("Porcelot Pigg", 381299, 4000.00);
	//BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);

	//Piggy.ViewAcct();
	//cout << endl;

	//Hoggy.ViewAcct();
	//cout << endl;

	//cout << "Hogg ���� ���¿� $1000 �Ա�:\n";
	//Hoggy.Deposit(1000.00);
	//cout << "Hogg ���� ���� �ܾ�: $" << Hoggy.Balance() << endl;

	//cout << "Pigg ���� ���¿� $4200 ����:\n";
	//Piggy.WithDraw(4200.00);
	//cout << "Pigg ���� ���� �ܾ�: $" << Piggy.Balance() << endl;

	//cout << "Hogg ���� ���¿��� $4200 ����:\n";
	//Hoggy.WithDraw(4200.00);
	//Hoggy.ViewAcct();

	///////////////////////////////////////////////////////////////////////////

	Brass* p_clients[CLIENTS];
	string temp;
	long tempnum;
	double tempbal;
	char kind;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "���� �̸��� �Է��Ͻʽÿ�: ";
		getline(cin, temp);

		cout << "���� ���� ��ȣ�� �Է��Ͻʽÿ�: ";
		cin >> tempnum;

		cout << "���� ���� �ܾ��� �Է��Ͻʽÿ�: $";
		cin >> tempbal;

		cout << "Brass ���´� 1, "
			 << "BrassPlus ���´� 2�� �Է��Ͻʽÿ�: ";


	}

	return 0;
}