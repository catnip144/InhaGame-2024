/*
임의의 N을 입력받아서 다음과 같은 형태로 출력하도록 하라.
ex) N = 5
Practice 2
*
**
***
****
*****

    * 4 1
   ** 3 2
  *** 2 3
 **** 1 4
***** 0 5

Practice 3
*
**
***
****
*****
****
***
**
*

Practice 4
N = 3
* *
 *
* *

N = 4
*  *   0 2   0
 **    1 0   1
 **    1 0   2
*  *   0 2   3

*   *  0 3      0   n - 2 - k * 2
 * *   1 1      1
  *    2 0      2
 * *   1 1      3
*   *  0 3      4

*    * 0 4      0
 *  *  1 2      1
  **   2 0      2
  **   2 0      3
 *  *  1 2      4
*    * 0 4      5

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Practice2()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            printf("*");
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
            printf(" ");

        for (int j = 0; j <= i; j++)
            printf("*");

        printf("\n");
    }
}
void Practice3()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n * 2 - 1; i++)
    {
        if (i < n)
        {
            for (int j = 0; j <= i; j++)
                printf("*");
        }
        else
        {
            for (int j = i % n; j < n - 1; j++)
                printf("*");
        }
        printf("\n");
    }
}
void Practice4_Solution()
{
    // 혼공C 204p
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j == n - 1 || i == j)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        
    }
}