/*
1 이상 100 미만 정수중 M, N 배수를 출력하라.
단, M의 배수이면서 N의 배수인 정수는 한번만 출력한다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    for (int i = 1; i < 100; i++)
    {
        if ((i % n == 0) || (i % m == 0))
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}