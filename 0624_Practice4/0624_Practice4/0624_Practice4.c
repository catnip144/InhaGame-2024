/*
혼공C 205쪽 도전실전예제
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void MySolution()
{
	int n;
	printf("2 이상의 정수를 입력하세요 : ");
	scanf("%d", &n);

	int column = 0;
	int maxColumn = 5;

	for (int i = 2; i <= n; i++)
	{
		int isPrime = 1;
		for (int j = i - 1; j >= 2; j--)
		{
			if (i % j == 0)
			{
				isPrime = 0;
				break;
			}
		}
		if (isPrime == 1)
		{
			printf("%10d", i);
			if (++column % maxColumn == 0)
				printf("\n");
		}
	}
}

void main()
{
	int n;
	printf("2 이상의 정수를 입력하세요 : ");
	scanf("%d", &n);

	int column = 0;
	int maxColumn = 5;

	for (int i = 2; i <= n; i++)
	{
		int isPrime = 1;
		for (int j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				isPrime = 0;
				break;
			}
		}
		if (isPrime == 1)
		{
			printf("%10d", i);
			if (++column % maxColumn == 0)
				printf("\n");
		}
	}
}