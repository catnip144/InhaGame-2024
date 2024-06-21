// 혼공C 180쪽 도전 실전 예제

#define _CRT_SECURE_NO_WARNINGS // 위에 써야 함
#include <stdio.h>

void main()
{
	int a, b, res;
	char op;

	printf("사칙연산 입력(정수) : ");
	scanf("%d%c%d", &a, &op, &b);

	switch (op)
	{
		case '+':
			res = a + b;
			break;

		case '-':
			res = a - b;
			break;

		case '*':
			res = a * b;
			break;

		case '/':
			res = a / b;
			break;

		default:
			break;
	}
	printf("%d%c%d=%d", a, op, b, res);
}
