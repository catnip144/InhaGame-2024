/*
10진수를 각 진수로 변환하는 프로그램을 작성하라
확장 ... 각 진수끼리 변환 프로그램을 작성하라
(2~36 진수사이 서로 변환)

16진수  3B -> 10진수 -> 2진수 : ?
2진수 1001 -> 10진수 -> 6진수 : ?

4 =  100
8 = 1000

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char alphaTable[36];
int numTable[101];

char* ConvertFromBase10(int n, int b)
{
	int count = 0;
	char* nums = (char*)malloc(sizeof(char) * 2);

	while (n)
	{
		nums[count] = alphaTable[n % b];
		count++;
		n /= b;

		nums = (char*)realloc(nums, (count + 2) * sizeof(char));
	}
	for (int i = count - 1; i >= 0; i--)
		printf("%c", nums[i]);
}

void ConvertBase()
{
	int start, to;
	char num[500];

	printf("시작 진수: ");
	scanf("%d", &start);

	printf("변환할 진수: ");
	scanf("%d", &to);

	printf("숫자 입력: ");
	scanf("%s", num);

	int lastIndex = strlen(num) - 1;
	int sum = 0;

	for (int i = lastIndex; i >= 0; i--)
		sum += start * pow(numTable[num[i]], lastIndex - i);
	
	

}

void main()
{
	int n, b;

	for (int i = 0; i <= 9; i++)
	{
		alphaTable[i] = '0' + i;
		numTable[alphaTable[i]] = i;
	}
	for (int i = 10; i < 36; i++)
	{
		alphaTable[i] = 'A' + i - 10;
		numTable[alphaTable[i]] = i;
	}
	printf("10진수 숫자 입력: ");
	scanf("%d", &n);

	printf("변환할 진수: ");
	scanf("%d", &b);

	ConvertFromBase10(n, b);
}