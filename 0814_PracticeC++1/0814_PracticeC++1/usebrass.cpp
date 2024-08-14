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

	//cout << "Hogg ¾¾ÀÇ °èÁÂ¿¡ $1000 ÀÔ±Ý:\n";
	//Hoggy.Deposit(1000.00);
	//cout << "Hogg ¾¾ÀÇ ÇöÀç ÀÜ¾×: $" << Hoggy.Balance() << endl;

	//cout << "Pigg ¾¾ÀÇ °èÁÂ¿¡ $4200 ÀÎÃâ:\n";
	//Piggy.WithDraw(4200.00);
	//cout << "Pigg ¾¾ÀÇ ÇöÀç ÀÜ¾×: $" << Piggy.Balance() << endl;

	//cout << "Hogg ¾¾ÀÇ °èÁÂ¿¡¼­ $4200 ÀÎÃâ:\n";
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
		cout << "°í°´ÀÇ ÀÌ¸§À» ÀÔ·ÂÇÏ½Ê½Ã¿À: ";
		getline(cin, temp);

		cout << "°í°´ÀÇ °èÁÂ ¹øÈ£¸¦ ÀÔ·ÂÇÏ½Ê½Ã¿À: ";
		cin >> tempnum;

		cout << "°èÁÂ °³¼³ ÀÜ¾×À» ÀÔ·ÂÇÏ½Ê½Ã¿À: $";
		cin >> tempbal;

		cout << "Brass °èÁÂ´Â 1, "
			 << "BrassPlus °èÁÂ´Â 2¸¦ ÀÔ·ÂÇÏ½Ê½Ã¿À: ";


	}

	return 0;
}