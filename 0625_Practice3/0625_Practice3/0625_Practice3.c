/*
혼공C 234쪽 도전 실전 예제
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int rec_func(int n)
{
	if (n == 1)
		return 1;
	return n + rec_func(n - 1);
}

void main()
{
	int n;
	printf("숫자를 입력하세요: ");
	scanf("%d", &n);

	printf("1 ~ %d까지의 합은 %d 입니다.\n", n, rec_func(n));
}