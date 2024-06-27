/*
Q2.길이가 6인 int형 배열을 선언하고, 1, 2, 3, 4, 5, 6으로 초기화 한 다음
배열에 저장된 값의 순서가 반대로 6, 5, 4, 3, 2, 1이 되도록 변경하는 프로그램을 작성하라.

조건1. 포인터를 활용하라

Q3. 임의의 문자열을 입력받아 뒤지어 출력하는 프로그램을 작성하라.
ex) Input > Hello World
	Output > dlroW olleH

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void Inverse(int* arr, int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temp;
	}
}
void InverseString(char* s, int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		int temp = s[i];
		s[i] = s[size - 1 - i];
		s[size - 1 - i] = temp;
	}
}
void Solution()
{
	int numbers[6] = { 1, 2, 3, 4, 5, 6 };
	int size = sizeof(numbers) / sizeof(numbers[0]);
	Inverse(numbers, size);

	for (int i = 0; i < size; i++)
	{
		printf("%d ", numbers[i]);
	}
	printf("\n");

	char sentence[100];
	gets(sentence);

	InverseString(sentence, strlen(sentence));
	puts(sentence);
}


void main()
{
	char sentence[80];
	gets(sentence);

	char *ptrS, *ptrE;
	ptrS = sentence;
	ptrE = sentence + strlen(sentence) - 1;

	printf("%u\n", ptrS);
	printf("%u\n", ptrE);
}