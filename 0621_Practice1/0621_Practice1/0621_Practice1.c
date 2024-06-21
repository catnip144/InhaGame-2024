#define _CRT_SECURE_NO_WARNINGS // 위에 써야 함
#include <stdio.h>

/*
한줄로 작성
Q1. 사용자로부터 정수 3개를 입력 받아서 저장을 하고
    조건 연산자를 이용하여 이 변수들 중에 가장 큰 값을 구해 출력하는 프로그램을 작성하라.
*/

void MySolution()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int answer = a > (b > c ? b : c) ? a : (b > c ? b : c);
    printf("%d\n", answer);
}

void main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int answer = a > b ? (a > c ? a : c) : (b > c ? b : c);
    printf("%d\n", answer);
}
