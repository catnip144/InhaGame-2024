/*

1. 1씩 증가하면서 소수 판단
2. 2 ~ (n - 1) 사이의 홀수로 계산
3. 홀수 + 이전 계산된 소수로 나누어지지 않는 수
4. 제곱근 n 이하의 모든 소수로 나누었을 때 나누어 떨어지지 않는 수 + 이전 계산된 소수로 나누어 지지 않는 수

순서도 그리기
실행한 회수 카운트 출력 - 
각각의 알고리즘에 성능 체크 .. 시간 측정

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#define BIG_NUM 100000

int count = 0;

void Prime_1(int n)
{
	//printf("2 ");
	count = 0;

	for (int k = 3; k <= n; k++)
	{
		bool isPrime = true;
		for (int i = 2; i < k; i++)
		{
			count++;
			if (k % i == 0)
			{
				isPrime = false;
				break;
			}
		}
		//if (isPrime) printf("%d ", k);
	}
}

void Prime_2(int n)
{
	//printf("2 ");
	count = 0;

	for (int k = 3; k <= n; k += 2)
	{
		bool isPrime = true;
		for (int i = 3; i < k; i += 2)
		{
			count++;
			if (k % i == 0)
			{
				isPrime = false;
				break;
			}
		}
		//if (isPrime) printf("%d ", k);
	}
}

void Prime_3(int n)
{
	int arr[BIG_NUM] = { 0, };

	count = 0;
	int index = 0;
	arr[index] = 2;
	index++;

	for (int k = 3; k <= n; k += 2)
	{
		bool isPrime = true;
		for (int i = 0; i < index; i++)
		{
			count++;
			if (k % arr[i] == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
		{
			arr[index] = k;
			index++;
		}
	}
	//for (int i = 0; i < index; i++)
	//	printf("%d ", arr[i]);
}

void Prime_4(int n)
{
	int arr[BIG_NUM] = { 0, };

	count = 0;
	int index = 0;
	arr[index] = 2;
	index++;

	int limit = (int)sqrt(n);

	for (int k = 3; k <= n; k ++)
	{
		bool isPrime = true;
		//int limit = (int)sqrt(k);

		for (int i = 0; (i < index) && (arr[i] <= limit); i++)
		{
			count++;
			if (k % arr[i] == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
		{
			arr[index] = k;
			index++;
		}
	}
	//for (int i = 0; i < index; i++)
		//printf("%d ", arr[i]);
}

void Prime_5(int n)
{
	int arr[BIG_NUM] = { 0, };

	count = 0;
	int index = 0;
	arr[index] = 2;
	index++;

	//int limit = (int)sqrt(n);

	for (int k = 3; k <= n; k++)
	{
		bool isPrime = true;
		int limit = (int)sqrt(k);

		for (int i = 0; (i < index) && (arr[i] <= limit); i++)
		{
			count++;
			if (k % arr[i] == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
		{
			arr[index] = k;
			index++;
		}
	}
	//for (int i = 0; i < index; i++)
		//printf("%d ", arr[i]);
}

void main()
{
	int n;
	printf("확인할 소수 범위: ");
	scanf("%d", &n);

	clock_t start = clock();
	Prime_1(n);
	printf("\nPrime 1 총 실행 회수: %d\n", count);
	clock_t end = clock();
	printf("\n%lf\n", (float)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	Prime_2(n);
	printf("\nPrime 2 총 실행 회수: %d\n", count);
	end = clock();
	printf("\n%lf\n", (float)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	Prime_3(n);
	printf("\nPrime 3 총 실행 회수: %d\n", count);
	end = clock();
	printf("\n%lf\n", (float)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	Prime_4(n);
	printf("\nPrime 4 총 실행 회수: %d\n", count);
	end = clock();
	printf("\n%lf\n", (float)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	Prime_5(n);
	printf("\nPrime 5 총 실행 회수: %d\n", count);
	end = clock();
	printf("\n%lf\n", (double)(end - start) / CLOCKS_PER_SEC);
}