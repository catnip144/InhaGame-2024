#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void main()
{
	//int score[4] = { 10, }; // 나머지는 0
	// int score[4] = { 10, 20, 30, 40};
	//              = { 10, };
	// int score[] = { 0 };

	//score[0] = 10;
	//score[1] = 20;
	//score[2] = 30;

	//scanf("%d", &score[2]);

	//printf("score %d : %d \n", 0, score[0]);
	//printf("score %d : %d \n", 1, score[1]);
	//printf("score %d : %d \n", 2, score[2]);
	//printf("score %d : %d \n", 2, score[3]);

	//int score[5];
	//int total = 0;
	//double avg;

	//for (int i = 0; i < 5; i++)
	//{
	//	scanf("%d", &score[i]);
	//}
	//for (int i = 0; i < 5; i++)
	//{
	//	total += score[i];
	//}
	//avg = total / 5.0;

	//for (int i = 0; i < 5; i++)
	//{
	//	printf("%5d", score[i]);
	//}
	//printf("\n");

	//printf("평균 : %.1lf\n", avg);

	//char str[80] = "applejam";
	//printf("%s\n", str);

	//scanf("%s", str);
	//printf("%s\n", str);

	//char str1[80] = "cat";
	//char str2[80];

	//strcpy(str2, str1);
	//strcpy(str1, "tiger");
	//
	//printf("string 1 : %s\n", str1);
	//printf("string 2 : %s\n", str2);

	// scanf는 %s로만 할 경우 공백을 구분하지 못한다
	// apple jam -> apple
	//char char1[80];
	//scanf("%s", char1);
	//printf("string 1 : %s\n", char1);

	//char char2[80];
	//gets(char2);
	//printf("string 2: ");
	//puts(char2);

	
	// Chapter 7 : 포인터
	// (자료형)* (변수명)

	//int a = 10;
	//printf("%d\n", a);

	//int* pa;
	//pa = &a;
	//*pa = 1000;

	//printf("%d\n", a);

	//scanf("%d", pa);
	//printf("%d\n", a);


	int a = 10, b = 15, total;
	double avg;

	int* pa, * pb, * pt;
	double* pg;

	pa = &a, pb = &b, pt = &total;
	pg = &avg;

	*pt = *pa + *pb;
	*pg = *pt / 2.0;

	printf("두 정수의 값: %d, %d\n", *pa, *pb);
	printf("두 정수의 합: %d\n", *pt);
	printf("두 정수의 평균: %.1f\n", *pg);
}