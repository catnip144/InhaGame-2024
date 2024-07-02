/*
다음과 같이 A행렬의 전치 행렬 B를 구현하라.
ex>
A 행렬
	1 2 3 4          
	4 5 6 7

	4 1 =	1,0 0,0
	5 2		1,1 0,1
	6 3		1,2	0,2
	7 4		1,3 0,3

A 행렬
	1 2 3
	4 5 6
	7 8 9

	7 4 1	2,0	1,0	0,0
	8 5 2	2,1	1,1	0,1
	9 6 3	2,2 1,2 0,2

Q2.
	1 2 3
	4 5 6
	7 8 9

	1 4 7
	2 5 8
	3 6 9

	1 2 3 4
	4 5 6 7
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int rows, columns;
	int arrA[][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
	};
	int arrB[4][2];
	int arrC[4][2];

	rows = sizeof(arrA[0]) / sizeof(arrA[0][0]);
	columns = sizeof(arrA) / sizeof(arrA[0]);

	printf("A 행렬 : \n");
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
			printf("%5d", arrA[i][j]);
		printf("\n");
	}
	printf("\n바꾼 후 : \n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			arrB[i][j] = arrA[columns - j - 1][i];
			printf("%5d", arrB[i][j]);
		}
		printf("\n");
	}
	printf("\nA의 전치 행렬 : \n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			arrC[i][j] = arrA[j][i];
			printf("%5d", arrC[i][j]);
		}
		printf("\n");
	}

}
