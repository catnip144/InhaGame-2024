#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "stock.h"

using namespace std;

const int STKS = 4;

int main()
{
	//Stock fluffy;
	//fluffy.acquire("Nanosmart", 20, 12.50);
	//fluffy.show();

	//fluffy.buy(15, 18.125);
	//fluffy.show();

	//fluffy.sell(400, 20);
	//fluffy.show();

	//fluffy.buy(300000, 40.125);
	//fluffy.show();

	//fluffy.sell(300000, 0.125);
	//fluffy.show();

	//////////////////////////////////////////////////////////

	Stock stocks[STKS] = {
		Stock("Nanosmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5),
	};

	cout << "보유 주식 리스트: \n";
	for (int st = 0; st < STKS; st++)
		stocks[st].show();

	// 첫 번째 원소에 포인터 지정
	const Stock* top = &stocks[0];
	for (int st = 1; st < STKS; st++)
		top = &top->topval(stocks[st]);

	// 가장 가치 있는 주식의 최고치
	cout << "\n최고 가치의 주식:\n";
	top->show();

	return 0;
}

