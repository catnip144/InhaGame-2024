﻿/*

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int ary1[4] = { 1, 2, 3, 4 };
	int ary2[4] = { 11, 12, 13, 14 };
	int ary3[4] = { 21, 22, 23, 24 };
	int* pary[3] = { ary1, ary2, ary3 };

	int rows = sizeof(pary) / sizeof(pary[0]);
	int columns = sizeof(ary1) / sizeof(ary1[0]);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			printf("%5d", pary[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			printf("%u\t", &pary[i][j]);
		}
		printf("\n");
	}
}