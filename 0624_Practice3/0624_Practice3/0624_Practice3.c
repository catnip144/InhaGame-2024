/*
다음 식을 만족하는 모든 A와 Z를 구하는 프로그램을 작성하라.
단, N은 10미만의 정수이다.

    A Z
 +  Z A
 -------
    N N

    N = 9
    A Z     6 3
    Z A     3 6
-----------------
    9 9     9 9

=> A = 0    Z = 9
=> A = 1    Z = 8
=>

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
    {
        printf("A = %d\tZ = %d\n", i, n - i);
    }
}