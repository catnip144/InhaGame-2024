#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
Q1.
입력받은 값의 절대값을 구하는 함수 abs_1()를 구현하라
반복되는 프로그램

ex) 
종료하려면 0을 입력하시오.
정수 입력 : -34
절대값은 : 34
*/

int abs_1(int number)
{
	return number > 0 ? number : -number;
}

void main()
{
	int n;

	while (1)
	{
		printf("종료하려면 0을 입력하시오.\n");
		printf("정수 입력 : ");
		scanf("%d", &n);

		if (n == 0)
			break;

		printf("절대값은 : %d\n\n", abs_1(n));
	}
}