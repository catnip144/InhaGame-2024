#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int med3(int a, int b, int c);

void main()
{
	int a, b, c;
	printf("숫자 3개 입력 : ");
	scanf("%d %d %d", &a, &b, &c);
	printf("중앙값 : %d", med3(a, b, c));
}

int med3(int a, int b, int c)
{
	if (a > b)
	{
		if (b > c)
			return b;
		else
		{
			if (a < c)
				return a;
			else
				return c;
		}
	}
	else
	{
		if (b < c)
			return b;
		else
		{
			if (a < c)
				return c;
			else
				return a;
		}
	}
}