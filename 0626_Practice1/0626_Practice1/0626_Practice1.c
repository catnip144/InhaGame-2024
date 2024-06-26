/*
Q. 길이가 5인 int형 배열을 선언하고,
사용자로부터 5개의 정수를 입력받아 다음의 내용을 출력하는 프로그램을 작성하라.

1. 입력된 정수 중 최대값
2. 입력된 정수 중 최소값
3. 입력된 정수들의 총 합

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 5

void main()
{
	int numbers[SIZE] = { 0, };
	int maxNum, minNum, sum = 0;

	for (int i = 0; i < SIZE; i++)
	{
		printf("%d 번째 정수 입력 : ", i + 1);
		scanf("%d", &numbers[i]);
		sum += numbers[i];

		if (i == 0)
		{
			maxNum = minNum = numbers[0];
			continue;
		}
		if (maxNum < numbers[i])
			maxNum = numbers[i];
		
		if (minNum > numbers[i])
			minNum = numbers[i];
	}
	printf("\n최대값 : %d\n", maxNum);
	printf("최소값 : %d\n", minNum);
	printf("총 합 : %d\n", sum);
}