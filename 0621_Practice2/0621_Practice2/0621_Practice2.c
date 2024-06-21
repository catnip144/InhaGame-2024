#define _CRT_SECURE_NO_WARNINGS // 위에 써야 함
#include <stdio.h>

/*
Q.	두 개의 정수를 입력받아 두 수의 차를 출력하는 프로그램을 작성
	단, 무조건 큰 수에서 작은 수를 빼야 한다.
	ex) 12 5 -> 7
		4 16 -> 12

	case 1. if문 이용
	case 2. 조건연산자 이용
*/

void Solution1()
{
	int a, b;
	scanf("%d %d", &a, &b);

	if (a > b)
	{
		printf("%d\n", a - b);
	}
	else
	{
		printf("%d\n", b - a);
	}
}

void main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	int answer = a > b ? a - b : b - a;
	printf("%d\n", answer);
}
