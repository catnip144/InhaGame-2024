/*
Q2. p.42 17번, 18번

Q.17
* * * * *
  * * *
    *
  * * *
* * * * *

Q.18

1 1 1 1 1
  2 2 2
    3
  2 2 2
1 1 1 1 1

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

void PrintPyramid(int n, bool printStars)
{
    bool isMiddle = false;
    int amount = -2;
    int count = n;
    int num;

    for (int i = 0; i < n; i++)
    {
        if (!isMiddle && count <= 0)
        {
            isMiddle = true;
            amount *= -1;

            count += amount;
            if (n % 2) count += amount;
        }
        num = isMiddle ? n - i : i + 1;

        for (int j = 0; j < (n - count) / 2; j++)
            printf("  ");

        for (int j = 0; j < count; j++)
        {
            if (printStars) printf("* ");
            else printf("%-2d", num);
        }
        printf("\n");
        count += amount;
    }
    printf("\n");
}

void main()
{
    int n;
    scanf("%d", &n);

    PrintPyramid(n, false);
    PrintPyramid(n, true);
}