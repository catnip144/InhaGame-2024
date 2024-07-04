#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//void main(int argc, char **argv)
//{
//	printf(" >>> arguments <<<\n");
//	printf(" > arguments count : %d \n", argc);
//
//	for (int i = 0; i < argc; i++)
//	{
//		printf("> %s\n", argv[i]);
//	}
//}
//struct profile
//{
//	char name[20];
//	int age;
//	double height;
//	char* intro;
//};

//struct profile
//{
//	int age;
//	double height;
//};
//
//struct student
//{
//	struct profile pf;
//	int id;
//	double grade;
//};

//struct student
//{
//	int id;
//	char name[20];
//	double grade;
//};

//struct score
//{
//	int kor;
//	int eng;
//	int math;
//};

struct list
{
	int num;
	struct list* next;
};

void main()
{
	//struct profile yuni;

	//strcpy(yuni.name, "서하윤");
	//yuni.age = 17;
	//yuni.height = 164.5;

	//yuni.intro = (char*)malloc(80);
	//printf("자기소개 : ");
	//gets(yuni.intro);

	//printf("이름 : %s\n", yuni.name);
	//printf("나이 : %d\n", yuni.age);
	//printf("키 : %.1lf\n", yuni.height);
	//printf("자기소개 : %s\n", yuni.intro);
	//free(yuni.intro);

	////////////////////////////////////////

	//struct student yuni;

	//yuni.pf.age = 17;
	//yuni.pf.height = 164.5;
	//yuni.id = 315;
	//yuni.grade = 4.3;

	//printf("나이 %d\n", yuni.pf.age);
	//printf("키 : %.1lf\n", yuni.pf.height);
	//printf("학번 : %d\n", yuni.id);
	//printf("학점 : %.1lf\n", yuni.grade);

	////////////////////////////////////////

	//struct student
	//	s1 = { 315, "홍길동", 2.4 },
	//	s2 = { 316, "이순신", 3.7 },
	//	s3 = { 317, "세종대왕", 4.4 };

	////////////////////////////////////////

	//struct score yuni = { 90, 80, 70 };
	//struct score* ps = &yuni;

	//printf("%국어 : %d\n", (*ps).kor);
	//printf("%영어 : %d\n", ps->eng);
	//printf("%수학 : %d\n", ps->math);

	////////////////////////////////////////

	struct list a = { 10, NULL }, b = { 20, NULL }, c = { 30, NULL }, d = { 40, NULL };
	struct list* head = &a;
	struct list* current;

	a.next = &b;
	b.next = &c;
	c.next = &d;

	printf("current head's num : %d\n", head->num);
	printf("all nums : ");
	current = head;

	while (current != NULL)
	{
		printf("%d ", current->num);
		current = current->next;
	}
}