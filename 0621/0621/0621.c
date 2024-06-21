#define _CRT_SECURE_NO_WARNINGS // 위에 써야 함
#include <stdio.h>

void main()
{
	int a = 10, b = 3;
	double d = 1.00001;
	// a = (int)d;
	// d = (double)a;

	d = a / b;
	printf("%.1lf\n", d);

	d = (double)a / (double)b;
	printf("%.1lf\n", d);

	// 큰 데이터 값에 맞춰서 형 변환을 해준다.
	d = (double)a / b;
	printf("%.1lf\n", d);

	// (int)을 사용해 정수 부분만 추출
	printf("%d\n", (int)d);

	// sizeof 연산자
	printf("\n");

	int a1 = 10;
	double b1 = 3.4;

	printf("int형 변수의 크기: %d\n", sizeof(a1));
	printf("double형 변수의 크기: %d\n", sizeof(b1));
	printf("정수형 상수의 크기: %d\n", sizeof(10));
	printf("수식의 결괏값의 크기: %d\n", sizeof(1.5 + 3.4));
	printf("char 자료형의 크기: %d\n", sizeof(char));

	// 괄호가 중요
	printf("수식의 결괏값의 크기: %d\n", sizeof 1.5 + 3.4);

	// 조건 연산자
	// 변수 = ( 조건식 ) ? True : False;
	printf("\n");
	int a0 = 10, b0 = 20;
	int res = (a0 > b0) ? a0 : b0;
	printf("큰 값: %d\n", res);

	// 비트 연산자
	printf("\n");
	int a2 = 3;			// 0000 0011
	int b2 = 7;			// 0000 0111

	int c2 = a2 & b2;	// 0000 0011 // 3
	int c3 = a2 | b2;	// 0000 0111 // 7
	int c4 = a2 ^ b2;	// 0000 0100 // 4
	int c5 = ~a2;		// 1111 1100
	int c6 = a2 << 2;	// 0000 1100 // 12 // 2의 제곱으로 증가

	// 음수에 대해서는 잘 사용하지 않는다.
	int c7 = -1 << 2;
	int c8 = -2 >> 5;

	printf("%d\n", c2);
	printf("%d\n", c3);
	printf("%d\n", c4);
	printf("%d\n", c5);
	printf("%d\n", c6);
	printf("%d\n", c7);
	printf("%d\n", c8);

	// 연산자 우선순위
	// 괄호를 많이 사용하자

	printf("\n");
	int a3 = 10, b3 = 5;
	int res3;

	res3 = a3 / b3 * 2;
	printf("res = %d\n", res3);

	res3 = ++a3 * 3;
	printf("res = %d\n", res3);

	printf("a3 = %d\n", a3);

	res3 = a3 > b3 && a3 != 5;
	printf("res = %d\n", res3);

	res3 = a % 3 == 0;
	printf("res = %d\n", res3);

	//res3 = ++(a3 * 3);
	//printf("res = %d\n", res3);


	// Chapter 5 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*
		if (조건식)
		{
			실행할 코드
		}
	*/
	printf("\n=== Chapter 5 === \n\n");

	a = 0, b = 20;
	if (a > 0)
	{
		printf("%d는 양수이다\n", a);
	}
	else if (a < 0)
	{
		printf("%d는 음수이다\n", a);
	}
	else
	{
		printf("%d는 0이다\n", a);
	}
	printf("\n");

	int age = 0;
	// scanf("%d", &age);

	if (age < 10)
	{
		printf("소인입니다.\n");
	}
	else if (age >= 10 && age < 20)
	{
		printf("10대 청소년입니다.\n");
	}
	else if (age >= 20 && age < 40)
	{
		printf("청년입니다.\n");
	}
	else if (age >= 40 && age < 60)
	{
		printf("장년입니다.\n");
	}
	else
	{
		printf("노년입니다.\n");
	}

	// 중첩된 if문
	printf("\n");

	a = 20, b = 9;
	if (a > 10)
	{
		if (b >= 10)
		{
			b = 1;
		}
		else
		{
			b = -1;
		}
	}
	printf("a : %d, b : %d\n", a, b);

	// switch문
	printf("\n");
	int rank = 2, m = 0;

	switch (rank)
	{
		case 1:
			m = 300;
			break;

		case 2:
			m = 200;
			break; // 주석 처리 시 case 3으로 합쳐짐

		case 3:
			m = 100;
			break;

		default:
			m = -1;
			break;
	}
	printf("m : %d\n", m);


	// Chapter 6 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	printf("\n");
	a = 1;

	while (a < 10)
	{
		a = a * 2;
		printf("a : %d\n", a);
	}
	printf("Final a : %d\n", a);

	/*
	for (초기식1, 초기식2 ; 조건식 ; 증감식1, 증감식2)
	{
	}
	*/
	printf("\n");
	a = 1;

	for (int i = 0; i < 3; i++)
	{
		// i 는 지역변수, 이 블록 내에서만 존재
		a = a * 2;
		printf("a : %d\n", a);
	}
	printf("Final a : %d\n", a);

	// do ~ while문

}
