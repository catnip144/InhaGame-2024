#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <Windows.h>
#include <process.h>

using namespace std;

int Value = 0;
int ValuePlusOne = 0;

int Cnt = 0;
bool isChecked = false;

CRITICAL_SECTION cs;

DWORD WINAPI ThFunc1(LPVOID lpParam)
{
	while (1)
	{
		Value = rand() % 1000;
		ValuePlusOne = Value + 1;
	}
	return 0;
}

DWORD WINAPI ThFunc2(LPVOID lpParam)
{
	while (1)
	{
		if (ValuePlusOne != (Value + 1))
		{
			// 발생하지 말아야할 케이스
			printf("%d : %d %d \n", Cnt++, ValuePlusOne, Value + 1);
		}
	}
	return 0;
}

DWORD WINAPI ThFunc3(LPVOID lpParam)
{
	while (1)
	{
		isChecked = false;
		Value = rand() % 1000;
		ValuePlusOne = Value + 1;
		isChecked = true;
	}
	return 0;
}

DWORD WINAPI ThFunc4(LPVOID lpParam)
{
	while (1)
	{
		if (isChecked)
		{
			if (ValuePlusOne != (Value + 1))
			{
				// 발생하지 말아야할 케이스
				printf("%d : %d %d \n", Cnt++, ValuePlusOne, Value + 1);
			}
		}
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////
DWORD WINAPI ThFunc5(LPVOID lpParam)
{
	while (1)
	{
		EnterCriticalSection(&cs);
		Value = rand() % 1000;
		ValuePlusOne = Value + 1;
		LeaveCriticalSection(&cs);

		// 이 스레드에 오래 머무르지 말라는 뜻
		Sleep(0);
	}
	return 0;
}


DWORD WINAPI ThFunc6(LPVOID lpParam)
{
	while (1)
	{
		EnterCriticalSection(&cs);
		printf("%d : %d %d \n", Cnt, ValuePlusOne, Value + 1);

		if (ValuePlusOne != (Value + 1))
		{
			// 발생하지 말아야할 케이스
			printf("%d : %d %d \n", Cnt++, ValuePlusOne, Value + 1);
		}
		LeaveCriticalSection(&cs);
		Sleep(0);
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////

unsigned __stdcall ThFunc7(LPVOID lpParam)
{
	while (1)
	{
		EnterCriticalSection(&cs);

		Value = rand() % 1000;
		ValuePlusOne = Value + 1;

		LeaveCriticalSection(&cs);
		Sleep(0);
	}
	return 0;
}

unsigned __stdcall ThFunc8(LPVOID lpParam)
{
	while (1)
	{
		EnterCriticalSection(&cs);
		printf("%d : %d %d \n", Cnt, ValuePlusOne, Value + 1);

		if (ValuePlusOne != (Value + 1))
		{
			printf("%d : %d %d \n", Cnt++, ValuePlusOne, Value + 1);
		}
		LeaveCriticalSection(&cs);
		Sleep(0);
	}
	return 0;
}


///////////////////////////////////////////////////////////////////////////////////

int main()
{
	InitializeCriticalSection(&cs);

	DWORD dwThID1, dwThID2;
	HANDLE hThreads[2];

	unsigned long ulStackSize = 0;

	dwThID1 = 0;
	dwThID2 = 0;
	hThreads[0] = NULL;
	hThreads[1] = NULL;

	{
		// CREATE_SUSPENDED : 만들자마자 바로 실행 x, 대기
		//hThreads[0] = CreateThread(NULL, ulStackSize, ThFunc1, NULL, CREATE_SUSPENDED, &dwThID1);
		//hThreads[1] = CreateThread(NULL, ulStackSize, ThFunc2, NULL, CREATE_SUSPENDED, &dwThID2);

		//hThreads[0] = CreateThread(NULL, ulStackSize, ThFunc5, NULL, CREATE_SUSPENDED, &dwThID1);
		//hThreads[1] = CreateThread(NULL, ulStackSize, ThFunc6, NULL, CREATE_SUSPENDED, &dwThID2);

		hThreads[0] = (HANDLE)_beginthreadex(NULL, ulStackSize, (unsigned(__stdcall*)(void*)) ThFunc7, NULL, 0, (unsigned*) &dwThID1);
		hThreads[1] = (HANDLE)_beginthreadex(NULL, ulStackSize, (unsigned(__stdcall*)(void*)) ThFunc8, NULL, 0, (unsigned*) &dwThID2);

		if (hThreads[0]) ResumeThread(hThreads[0]);
		if (hThreads[1]) ResumeThread(hThreads[1]);
	}

	/*//////   스레드 내부에서 종료시킬 때 사용   ////////////
	_endthreadex(dwThID1);
	_endthreadex(dwThID2);

	OR
	ExitThread(dwThID1);
	ExitThread(dwThID2);
	//////////////////////////////////////////////////////*/

	// 스레드가 완벽하게 완료되었을 때까지 메인을 종료하지 않음
	WaitForMultipleObjects(2, hThreads, TRUE, INFINITE);

	if (hThreads[0]) CloseHandle(hThreads[0]);
	if (hThreads[1]) CloseHandle(hThreads[1]);

	DeleteCriticalSection(&cs);

	return 0;
}

