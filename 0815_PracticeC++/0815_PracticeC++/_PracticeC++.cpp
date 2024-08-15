#include "workermi.h"
#include "queuetp.h"

void Show()
{
	cout << "\n사원 현황은 다음과 같습니다:\n";

	int start = lolas.FrontIndex();
	int end = lolas.RearIndex();

	while (start != end)
	{
		cout << endl;
		lolas.GetItems()[start]->Show();
		start = (start + 1) % lolas.MaxSize();
	}
}

int main()
{
	QueueTp<Worker *> lolas;

	for (int ct = 0; ct < lolas.MaxSize(); ct++)
	{
		char choice;
		cout << "\n직종을 입력하십시오:\n"
			 << "w: 웨이터\ts: 가수\t\tt: 가수 겸 웨이터\tq: 종료\n";

		cin >> choice;

		while (strchr("wstq", choice) == NULL)
		{
			cout << "w, s, t, q 중에서 하나를 선택하십시오: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;

		switch (choice)
		{
		case 'w':
			lolas.Enqueue(new Waiter);
			break;

		case 's':
			lolas.Enqueue(new Singer);
			break;

		case 't':
			lolas.Enqueue(new SingingWaiter);
			break;
		}
		cin.get();
		lolas.Rear()->Set();
	}


	cout << "프로그램을 종료합니다.\n";
	return 0;
}