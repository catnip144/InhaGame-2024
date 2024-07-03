/*
Q2. 다음과 같이 두 개의 int형 포인터 변수와 길이가 5인 int형 배열을 선언한다.
int *maxPtr;
int *minPtr;
int arr[5];

MaxAndMin 이란 함수를 정의, 호출해서 위 배열과 두 포인터를 변수로 전달한다.
함수의 호출이 완료되면
포인터 변수 maxPtr 에는 가장 큰 배열 요소의 주소값이
포인터 변수 minPtr 에는 가장 작은 배열 요소의 주소값이 저장되어야 한다.

arr 주소값, 최대/최소 주소값과
maxPtr, minPtr이 가진 주소에 저장된 값을 출력하라.

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void MaxAndMin(int* arr, int arrSize, int **maxPtr, int **minPtr)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (**maxPtr < arr[i])
			*maxPtr = &arr[i];
		if (**minPtr > arr[i])
			*minPtr = &arr[i];
	}
}

void main()
{
	int arr[5];
	int* maxPtr = &arr[0];
	int* minPtr = &arr[0];

	printf("5개의 숫자 입력 : ");
	scanf("%d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
	int arrSize = sizeof(arr) / sizeof(arr[0]);

	MaxAndMin(arr, arrSize, &maxPtr, &minPtr);
	printf("\narr 주소 값 : %12u\n", arr);
	printf("최대 요소의 주소 값 : %12u\n", maxPtr);
	printf("최소 요소의 주소 값 : %12u\n", minPtr);
	printf("최대값 : %d\n", *maxPtr);
	printf("최소값 : %d\n", *minPtr);
}