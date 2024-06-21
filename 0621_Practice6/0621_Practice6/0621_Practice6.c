/*
두 정수를 입력받아 두 수 사이에 존재하는 정수들의 합을 구하는 프로그램을 작성하라.
ex) 3 5 -> 3+4+5 = 12
*/

#define _CRT_SECURE_NO_WARNINGS // 위에 써야 함
#include <stdio.h>

void main()
{
	int num1, num2, start, end;
	scanf("%d %d", &num1, &num2);

	start = num1 < num2 ? num1 : num2;
	end = num1 < num2 ? num2 : num1;

	int answer = 0;
	for (int i = start; i <= end; i++)
		answer += i;

	printf("%d\n", answer);
}
