#include "workermi.h"
#include "queuetp.h"

void Show(QueueTp<Worker*>& workers)
{
	cout << "\n사원 현황은 다음과 같습니다:\n";

	int start = workers.FrontIndex();
	int end = workers.RearIndex();

	while (start != end)
	{
		cout << endl;
		workers.GetItems()[start]->Show();
		start = (start + 1) % workers.MaxSize();
	}
}

int main()
{
	QueueTp<Worker *> lolas;

	for (int ct = 0; ct < lolas.MaxSize(); ct++)
	{
		char choice;
		cout << "\n직종을 입력하십시오:\n"
			 << "w: 웨이터    s: 가수    t: 가수 겸 웨이터    d: 큐에서 제거    q: 종료\n";

		cin >> choice;

		while (strchr("wstdq", choice) == NULL)
		{
			cout << "w, s, t, d, q 중에서 하나를 선택하십시오: ";
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

		case 'd':
			cin.get();
			lolas.Dequeue();
			Show(lolas);
			continue;
		}
		cin.get();
		lolas.Rear()->Set();
	}
	Show(lolas);
	cout << "프로그램을 종료합니다.\n";
	return 0;
}