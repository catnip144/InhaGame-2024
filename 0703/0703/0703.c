/*

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap_ptr(char** ppa, char** ppb);
void func(int (*fp)(int, int));
int sum(int, int);
int sub(int a, int b);
int mul(int a, int b);
int max(int a, int b);

void main()
{
	//int a = 10;
	//int* pi;
	//int** ppi;

	//pi = &a;
	//ppi = &pi;

	//printf("-------------------------------------------------------------\n");
	//printf("변수\t  변숫값      &연산       *연산       **연산\n");
	//printf("-------------------------------------------------------------\n");

	//printf("  a%12d%12u\n", a, &a);
	//printf(" pi%12u%12u%12d\n", pi, &pi, *pi);
	//printf("ppi%12u%12u%12u%12d\n", ppi, &ppi, *ppi, **ppi);
	//printf("-------------------------------------------------------------\n");

	//==============================================================================================

	//char* pa = "success";
	//char* pb = "failure";

	//printf("pa -> %s, pb -> %s\n", pa, pb);
	//swap_ptr2(pa, pb);
	//printf("pa -> %s, pb -> %s\n", pa, pb);

	//==============================================================================================

	//int ary[5];
	//printf("  ary의 값 : %u\t", ary);
	//printf("ary의 주소 : %u\n", &ary);
	//printf("  ary + 1  : %u\t", ary + 1);
	//printf("  &ary + 1 : %u\n", &ary + 1);

	//==============================================================================================

	//int (*listener)(int, int);
	//int res;

	//listener = sum;
	//res = listener(10, 20);
	//printf("result : %d\n", res);

	//listener = sub;
	//res = listener(10, 20);
	//printf("result : %d\n", res);

	//==============================================================================================

	//int sel;
	//printf("01 두 정수의 합\n");
	//printf("02 두 정수의 곱\n");
	//printf("03 두 정수 중 최댓값\n");
	//printf("원하는 연산을 선택하세요 : ");
	//scanf("%d", &sel);

	//switch (sel)
	//{
	//case 1: func(sum); break;
	//case 2: func(mul); break;
	//case 3: func(max); break;
	//}

	//==============================================================================================

	int a = 10;
	double b = 3.5;
	void* vp;

	vp = &a;
	printf("a : %d\n", *(int*)vp);

	vp = &b;
	printf("b : %.1lf\n", *(double*)vp);
}
void swap_ptr(char** ppa, char** ppb)
{
	char* temp;
	temp = *ppa;
	*ppa = *ppb;
	*ppb = temp;
}
int sum(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
void func(int (*fp)(int, int))
{
	int a, b;
	int res;

	printf("두 정수의 값을 입력하세요 : ");
	scanf("%d%d", &a, &b);
	res = fp(a, b);
	printf("결괏값은 : %d\n", res);
}