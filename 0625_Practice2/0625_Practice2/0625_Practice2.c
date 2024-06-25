/*
	이전 문제 AZ ZA, 소수 구하기, 사칙 연산 프로그램을 함수를 사용하는 형태로 수정하라.
	사칙 연산 프로그램은 입력부분, 계산 부분, 출력 부분을 각각 함수로 구현하라.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void PrintPossibleOperands();
void PrintPrimeNumbers();
int IsPrime(int n);
int Calculator();
int Calculate(int x, int y, char op);
void PrintCalculationResult(int result, int x, int y, char op);

void main()
{
    int option;
    while (1)
    {
        printf("1. AZ ZA 구하기\n");
        printf("2. n이하 소수 구하기\n");
        printf("3. 사칙 연산 프로그램\n\n");

        printf("원하는 모드를 입력하세요 : ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                PrintPossibleOperands();
                break;

            case 2:
                PrintPrimeNumbers();
                break;

            case 3:
                Calculator();
                break;

            default:
                return;
        }
        printf("\n");
    }
}
void PrintPossibleOperands()
{
    int n;
    printf("숫자를 입력하세요 : ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
    {
        printf("A = %d\tZ = %d\n", i, n - i);
    }
}
void PrintPrimeNumbers()
{
    int n, column = 0;
    int maxColumn = 5;

    printf("2 이상의 정수를 입력하세요 : ");
    scanf("%d", &n);

    for (int i = 2; i <= n; i++)
    {
        if (IsPrime(i))
        {
            printf("%10d ", i);
            if (++column % maxColumn == 0)
                printf("\n");
        }
    }
    printf("\n");
}
int IsPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int Calculator()
{
    int x, y, result;
    char op;

    printf("사칙연산 입력(정수) : ");
    scanf("%d %c %d", &x, &op, &y);

    result = Calculate(x, y, op);
    PrintCalculationResult(result, x, y, op);
}
int Calculate(int x, int y, char op)
{
    switch (op)
    {
        case '+':
            return x + y;
            break;

        case '-':
            return x - y;
            break;

        case '*':
            return x * y;
            break;

        case '/':
            return x / y;
            break;

        default:
            return 0;
    }
}
void PrintCalculationResult(int result, int x, int y, char op)
{
    printf("%d %c %d = %d\n", x, op, y, result);
}