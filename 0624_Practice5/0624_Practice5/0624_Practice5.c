/*
다음과 같이 형태가 되도록 구구단을 출력하라. (19단)
원하는 단 n을 입력받아 n 단까지 출력한다.

ex) 2~19단 사이 입력 : 6 (n == 6)

-------------------------------
2단		     3단		4단
-------------------------------
2 x 1 = 2  3 x 1 = 3    4 x 1 = 4
...
2 x 19 = 38

-------------------------------
5단		     6단		
-------------------------------
2 x 1 = 5  6 x 1 = 6
...
           6 x 19 = 114
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void MySolution()
{
    int n;
    scanf("%d", &n);

    int range = (n - 1) / 3;

    if ((n - 1) % 3 == 0)
        range--;

    for (int i = 0; i <= range; i++)
    {
        printf("----------------------------------------------------------------------\n");
        for (int j = 0; j < 3 && i * 3 + (j + 2) <= n; j++)
        {
            printf("%6d단\t\t", i * 3 + (j + 2));
        }
        printf("\n----------------------------------------------------------------------\n");

        for (int k = 1; k <= 19; k++)
        {
            for (int j = 0; j < 3 && i * 3 + (j + 2) <= n; j++)
            {
                int number = i * 3 + (j + 2);
                printf("%d x %3d = %3d\t\t", number, k, number * k);
            }
            printf("\n");
        }
    }
}

void main()
{
    int N, C;
    printf("2이상 19이하의 숫자를 입력해주세요: ");
    scanf("%d", &N);

    printf("출력할 열의 개수를 입력해주세요: ");
    scanf("%d", &C);

    for (int i = 2; i <= N; i += C)
    {
        for (int c = 0; c < C && c < N - 1; c++)
            printf("----------------");
        printf("\n");

        for (int j = i; j < i + C && j <= N; j++)
        {
            printf("%4d단          ", j);
        }
        printf("\n");

        for (int c = 0; c < C && c < N - 1; c++)
            printf("----------------");
        printf("\n");

        for (int k = 1; k <= 19; k++)
        {
            for (int j = i; j < i + C && j <= N; j++)
            {
                printf("%4d x %3d = %3d", j, k, j * k);
            }
            printf("\n");
        }
    }
}