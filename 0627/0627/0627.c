
/*

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input_ary(double* pa, int size);
double find_max(double* pa, int size);
void Test(int* a)
{
	*a = 50;
}
void Swap(int* pa, int* pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}
void main()
{
	//int a = 10, b = 20;
	//int* pa = &a;
	//int* pb = &b;

	//printf("변수 a의 값 : %d\n", *pa);
	//
	//pa = pb;
	//printf("변수 b의 값 : %d\n", *pb);

	//Test(&a);
	//printf("변수 a의 값 : %d\n", a);
	//printf("포인터 pa가 가리키는 값 : % d\n", *pa);

	////////////////////////////////////////////////////////////////////////////////////

	//char ch;
	//int in;
	//double db;

	//char* pc = &ch;
	//int* pi = &in;
	//double* pd = &db;

	//printf("\n");
	//printf("char형 변수의 주소 크기 : %d\n", sizeof(&ch));
	//printf("int형 변수의 주소 크기 : %d\n", sizeof(&in));
	//printf("double형 변수의 주소 크기 : %d\n", sizeof(&db));
	//printf("\n");

	//printf("char* 포인터의 크기 : %d\n", sizeof(pc));
	//printf("int* 포인터의 크기 : %d\n", sizeof(pi));
	//printf("double* 포인터의 크기 : %d\n", sizeof(pd));
	//printf("\n");

	//printf("char* 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pc));
	//printf("int* 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pi));
	//printf("double* 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pd));


	////////////////////////////////////////////////////////////////////////////////////

	//int a = 10;
	//int* p = &a;
	//double* pd;

	//pd = p;
	//printf("%lf\n", *pd);
	//printf("%d\n", *pd);

	////////////////////////////////////////////////////////////////////////////////////

	//int a = 10, b = 20;

	//Swap(&a, &b);
	//printf("a : %d, b : %d\n", a, b);

	////////////////////////////////////////////////////////////////////////////////////

	// int arr[5];

	// arr + (0 * 4byte) => arr[0]
	// arr + (1 * 4byte) = > arr[1]

	//int ary[4];
	//int i;

	//*(ary + 0) = 10;
	//*(ary + 1) = *(ary + 0) + 10;

	//printf("세 번째 배열 요소에 키보드 입력 : ");

	//scanf("%d", ary + 2);
	////scanf("%d", &ary[2])

	//for (int i = 0; i < 3; i++)
	//{
	//	printf("%5d", *(ary + i));
	//}
	//printf("\n");
	//*(ary + 3) = 30;
	//printf("%d\n", ary[3]);

	////////////////////////////////////////////////////////////////////////////////////

	//int ary[3];
	//int* pa = ary;

	//*pa = 10;
	//*(pa + 1) = 50;

	//pa[2] = pa[0] + pa[1];

	//for (int i = 0; i < 3; i++)
	//{
	//	printf("%5d", ary[i]);
	//}

	////////////////////////////////////////////////////////////////////////////////////

	//int ary[3] = { 10, 20, 30 };
	//printf("%d\n", sizeof(ary));

	//int* pa = ary;

	//printf("pa[0] = %d\n", pa[0]);	// arr[0]
	//pa = pa + 1;
	//printf("pa[0] = %d\n", pa[0]);	// arr[1]

	////////////////////////////////////////////////////////////////////////////////////

	//int ary[5] = { 10, 20, 30, 40, 50 };
	//int* pa = ary;
	//int* pb = pa + 3;

	//printf("pa : %u\n", pa);
	//printf("pb : %u\n", pb);

	//pa++;
	//printf("pb - pa : %u\n", pb - pa);

	//printf("앞에 있는 배열 요소의 값 출력 : ");

	//if (pa < pb)
	//	printf("%d\n", *pa);
	//else
	//	printf("%d\n", *pb);

	////////////////////////////////////////////////////////////////////////////////////
	
	//int ary[5] = { 10, 20, 30, 40, 50 };
	//int* pa = ary + 2;

	//printf("%d\n", pa[0]);
	//printf("%d\n", pa[1]);

	////////////////////////////////////////////////////////////////////////////////////

	double ary[5];
	double max;
	int size = sizeof(ary) / sizeof(ary[0]);

	input_ary(ary, size);
	max = find_max(ary, size);
	printf("배열의 최댓값 : %.1lf\n", max);
}
void input_ary(double* pa, int size)
{
	printf("%d개의 실수값 입력 : ", size);
	for (int i = 0; i < size; i++)
	{
		scanf("%lf", pa + i);
	}
}
double find_max(double* pa, int size)
{
	double max = pa[0];
	for (int i = 0; i < size; i++)
	{
		if (pa[i] > max)
			max = pa[i];
	}
	return max;
}