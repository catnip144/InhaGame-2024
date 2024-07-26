/*
Q. 선형 검색을 하기 위한 기본 순서도와 이를 바탕을 선형 검색 프로그램을 작성하라.
ex) >
데이터 입력 : 6 5 2 1 8 9 7 4
검색 데이터 > 9
> 자료 중에 9가 있습니다.

검색 데이터 > 3
> 자료중에 3은 없습니다.

1. 선형 검색으로만
2. p120 Q2 와 같은 형태로 검색 과정 표시
3. 보초법을 이용하여 선형 검색 수정, 성능 비교
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintSearchProgress(int currentIndex, int n, int* arr)
{
	if (currentIndex == 0)
	{
		printf("  |  ");
		for (int i = 0; i < n; i++)
			printf("%2d  ", i);
		printf("\n-------------------------------------------\n");
	}
	printf("  |   ");
	for (int i = 0; i < currentIndex; i++) printf("    ");
	printf("*\n");

	printf("%2d|   ", currentIndex);
	for (int i = 0; i < n; i++) printf("%-2d  ", arr[i]);
	printf("\n  |   \n");
}

int LinearSearch(int searchNum, int n, int* arr)
{
	for (int i = 0; i < n; i++)
	{
		//PrintSearchProgress(i, n, arr);
		if (arr[i] == searchNum)
			return i;
	}
	return -1;
}

int SentinelLinearSearch(int searchNum, int n, int* arr)
{
	arr[n] = searchNum;

	for (int i = 0; ; i++)
	{
		//PrintSearchProgress(i, n, arr);
		if (arr[i] == searchNum)
		{
			if (i == n)
				return -1;
			else
				return i;
		}
	}
}

void main()
{
	int n;
	printf("배열 크기 입력: ");
	scanf("%d", &n);

	int* arr = (int*)calloc(n + 1, sizeof(int));
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
		arr[i] = i;

	int searchNum, index;
	printf("검색 데이터: ");
	scanf("%d", &searchNum);

	clock_t startTime;
	clock_t endTime;

	startTime = clock();
	index = LinearSearch(searchNum, n, arr);
	endTime = clock();

	if (index >= 0)
		printf("> %d은 x[%d]에 존재합니다.\n", searchNum, index);
	else
		printf("> 자료중에 %d가 없습니다.\n", searchNum);

	printf("순차 검색 실행시간: %f\n\n", ((double)(endTime - startTime)) / CLOCKS_PER_SEC);

	startTime = clock();
	index = SentinelLinearSearch(searchNum, n, arr);
	endTime = clock();

	if (index >= 0)
		printf("> %d은 x[%d]에 존재합니다.\n", searchNum, index);
	else
		printf("> 자료중에 %d가 없습니다.\n", searchNum);

	printf("보초법 실행시간: %f\n", ((double)(endTime - startTime)) / CLOCKS_PER_SEC);
}