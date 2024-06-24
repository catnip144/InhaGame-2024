/*

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 반환형 

void Test_1(int a, float b);
int sum(int x, int y);

void main()
{
	// 함수
	int a = 20;
	Test_1(a, 178.4f);

	int b = sum(5, 6);
	printf("sum is %d\n", b);
}
void Test_1(int age, float height)
{
	printf("Age is %d and Height is %.2f\n", age, height);
}
int sum(int x, int y)
{
	return x + y;
}