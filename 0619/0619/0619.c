// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <string.h>

void main()
{
	// 변수의 초기화
	int a, b, c;
	int nNumber;
	double da;
	float fa;
	char ch;

	a = 10;
	b = a;
	da = 3.5f;
	ch = 'A';

	printf("변수 a의 값 : %d\n", a);
	printf("변수 b의 값 : %d\n", b);
	printf("변수 c의 값 : %d\n", ch);
	printf("변수 da의 값 : %.1lf\n", da);
	printf("변수 ch의 값 : %c\n", ch);

	// 선언과 동시에 초기화
	printf("\n");
	char ch1 = 'A';
	char ch2 = 65;

	printf("문자 %c의 아스키 코드 값 : %d\n", ch1, ch1);
	printf("아스키 코드 값이 %d인 문자 : %c\n", ch2, ch2);

	// 정수형 자료형의 최대값
	printf("\n");
	short sh = 32767;
	int in = 2147483647;
	long ln = 2147483647;
	long long lln = 123451234512345;

	printf("short형 변수 출력 : %d\n", sh);
	printf("int형 변수 출력 : %d\n", in);
	printf("long형 변수 출력 : %ld\n", ln);
	printf("long long형 변수 출력 : %lld\n", lln);

	// 실수 자료형
	printf("\n");
	float ft = 1.234567890123456789;
	double db = 1.234567890123456789;
	printf("float형 변수에 저장된 값 : %.20f\n", ft);
	printf("double형 변수에 저장된 값 : %.20lf\n", db);

	// Warning 발생 : 'double'에서 'float'으로 잘립니다.
	float ft2 = 1.234567890123456789;
	
	// float 명시
	float ft3 = 1.234567890123456789f;

	// 문자열 저장
	printf("\n");
	char fruit[6] = "Apple"; // 5글자 + NULL 문자
	printf("%s\n", fruit);

	// 이렇게 초기화하면 오류, strcpy() 사용해야 함
	// fruit = "banana"; 

	char fruitS[20] = "strawberry";
	printf("딸기 : %s\n", fruitS);
	printf("딸기쨈 : %s %s\n", fruitS, "jam");

	// char 배열에 문자열 복사
	printf("\n");
	printf("%s\n", fruitS);
	strcpy(fruitS, "banana");
	printf("changed to -> %s\n", fruitS);

	// const 상수
	printf("\n");
	int income = 0;
	double tax;
	const double tax_rate = 0.12;

	// 입력
	/*
	int a1;
	scanf("%d", &a1);
	printf("입력받은 내용 : %d\n", a1);
	*/

	// 한 줄에 여러 개 입력받기
	/*
	int age;
	double height;

	printf("\n");
	printf("나이와 키를 입력하세요 : ");
	scanf("%d%lf", &age, &height);
	printf("나이는 %d살, 키는 %.1fcm입니다.\n", age, height);
	*/
	/*
	char grade;
	char name[20];

	printf("학점 입력: ");
	scanf("%c", &grade);

	printf("이름 입력: ");
	scanf("%s", name);

	printf("%s의 학점은 %c입니다.\n", name, grade);
	*/
	// Chapter 4 //////////////////////////////////////////////////////////
	
	// 연산자
	int a2, b2;
	int sum, sub, mul, inv;

	a2 = 10;
	b2 = 20;
	sum = a2 + b2;
	sub = a2 - b2;
	mul = a2 * b2;
	inv = -a2;

	printf("a2의 값 : %d b2의 값 : %d\n", a2, b2);
	printf("덧셈 : %d\n", sum);
	printf("뺄셈 : %d\n", sub);
	printf("곱셈 : %d\n", mul);
	printf("a2의 음수 연산 : %d\n", inv);

	// 몫과 나머지
	double Apple;
	int Banana;
	int Orange;

	Apple = 5.0 / 2.0;
	Banana = 5 / 2;
	Orange = 5 % 2;

	printf("\n");
	printf("Apple : %.1lf\n", Apple);
	printf("Banana : %d\n", Banana);
	printf("Orange : %d\n", Orange);

	// 
	printf("\n");
	double d1 = 5.0 / 2; // : %lf %d
	double d2 = 5 / 2.0;
	printf("%d\n", d1);
	printf("%lf\n", d1);
	printf("%d\n", d2);
	printf("%lf\n", d2);
	printf("\n");

	int n1 = 5.0 / 2;
	int n2 = 5 / 2.0;
	printf("%d\n", n1);
	printf("%lf\n", n1);
	printf("%d\n", n2);
	printf("%lf\n", n2);

	// 전위, 후위 표기
	printf("\n");
	int d = 10;
	int e = 10;
	++d;
	--e;

	printf("d : %d\n", d);
	printf("b : %d\n", e);

	printf("\n");
	int f = 5, g = 5;
	int pre, post;

	printf("초기값 f = %d, g = %d\n", f, g);
	
	pre = (++f) * 3; // 전위형 증감 연산자
	post = (g++) * 3;// 후위형 증감 연산자

	printf("전위형: (++f) * 3 = %d, 후위형: (g++) * 3 = %d\n", pre, post);

	// 관계 연산자
	int a3 = 10, b3 = 20, c3 = 10;
	printf("\na3 = 10, b3 = 20, c3 = 10\n");

	int res3 = (a3 > b3);
	printf("a3 > b3 : %d\n", res3);

	printf("a3 >= b3 : %d\n", a3 >= b3);
	printf("a3 < b3 : %d\n", a3 < b3);
	printf("a3 <= b3 : %d\n", a3 <= b3);
	printf("a3 <= c3 : %d\n", a3 <= c3);
	printf("a3 == b3 : %d\n", a3 == b3);
	printf("a3 != c3 : %d\n", a3 != c3);

	// 논리연산자
	printf("\n");
	int a4 = 30;
	int res4;

	res4 = (a4 > 10) && (a4 < 20);
	printf("(a > 10) && (a < 20) : %d\n", res4);

	res4 = (a4 < 10) || (a4 > 20);
	printf("(a < 10) || (a > 20) : %d\n", res4);

	res4 = !(a4 >= 30);
	printf("! (a >= 30) : %d\n", res4);


}
