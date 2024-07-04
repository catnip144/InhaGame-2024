/*

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void InitIsPrime(int* pi, int num, int n)
{
	for (int i = 2; num * i <= n; i++)
		pi[num * i] = -1;
}

void main()
{
	int n;
	printf("양수 입력 : ");
	scanf("%d", &n);

	int* pi = (int*)calloc(n, sizeof(int) * n);
	int count = 0;

	for (int i = 2; i <= n; i++)
		InitIsPrime(pi, i, n);
	
	for (int i = 2; i <= n; i++)
	{
		if (pi[i] == -1)
			printf("    X");
		else
			printf("%5d", i);

		count++;
		if (!(count % 5))
			printf("\n");
	}
	free(pi);
}