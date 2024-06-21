/*
Factorial 계산
어떤 양의 정수 n을 입력받아서 n!을 구하는 프로그램을 작성하라.
ex) 3! -> 3 * 2 * 1
*/

#define _CRT_SECURE_NO_WARNINGS // 위에 써야 함
#include <stdio.h>

void main()
{
	int n;
	scanf("%d", &n);

	int answer = 1;
	for (int i = n; i >= 1; i--)
	{
		answer *= i;
	}
	printf("Answer : %d\n", answer);
}