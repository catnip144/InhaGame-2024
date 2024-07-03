/*

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(char* type, void* a, void* b);
void swapInt(int* a, int* b);
void swapDouble(double* a, double* b);

void main()
{
	int ageA, ageB;
	double heightA, heightB;

	printf("첫 번째 사람의 나이와 키 입력 : ");
	scanf("%d %lf", &ageA, &heightA);

	printf("두 번째 사람의 나이와 키 입력 : ");
	scanf("%d %lf", &ageB, &heightB);

	swap("int", &ageA, &ageB);
	swap("double", &heightA, &heightB);

	printf("첫 번째 사람의 나이와 키 : %d, %.1lf\n", ageA, heightA);
	printf("두 번째 사람의 나이와 키 : %d, %.1lf\n", ageB, heightB);
}
void swap(char* type, void* a, void* b)
{
	if (type == "int")
		swapInt((int*)a, (int*)b);

	if (type == "double")
		swapDouble((double*)a, (double*)b);
}
void swapInt(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void swapDouble(double* a, double* b)
{
	double temp;
	temp = *a;
	*a = *b;
	*b = temp;
}