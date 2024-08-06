/*
	DoIt 알고리즘 자료구조 164p 기반 코드 구현
	clear, search 메뉴도 추가
*/
#include "IntQueue.h"

int main()
{
	IntQueue que;

	if (Initialize(&que, 64) == -1)
	{
		cout << "큐의 생성에 실패하였습니다." << endl;
		return 1;
	}
	while (1)
	{
		int m, x, index;
		cout << "\n현재 데이터 수: " << Size(&que) << " / " << Capacity(&que) << endl;
		cout << "(1)인큐  (2)디큐  (3)피크  (4)출력  (5)비우기   (6)검색   (0)종료\n>> ";

		cin >> m;
		cout << endl;
		if (m == 0) break;

		switch (m)
		{
		case 1:
			cout << "데이터: ";
			cin >> x;

			if (Enque(&que, x) == -1)
				cout << "오류: 인큐에 실패하였습니다.\a\n";
			break;
		case 2:
			if (Deque(&que, &x) == -1)
				cout << "오류: 디큐에 실패하였습니다.\a\n";
			else
				cout << "디큐한 데이터는 " << x << "입니다.\n";
			break;
		case 3:
			if (Peek(&que, &x) == -1)
				cout << "오류: 피크에 실패하였습니다.\a\n";
			else
				cout << "피크한 데이터는 " << x << "입니다.\n";
			break;
		case 4:
			Print(&que);
			break;
		case 5:
			Clear(&que);
			break;
		case 6:
			cout << "데이터: ";
			cin >> x;

			index = Search(&que, x);
			if (index == -1)
				cout << "오류: 검색에 실패하였습니다.\a\n";
			else
				cout << x << "는 인덱스 " << index << "에 위치하고 있습니다.\n";
			break;
		default:
			break;
		}
	}
	Terminate(&que);
	return 0;
}

