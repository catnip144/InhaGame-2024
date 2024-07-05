/*
혼공C 540쪽 도전예제
학번, 이름, 학점(국/영/수)를 입력받을 수 있는 구조체를 만들고,
임의 수의 학생에 대한 데이터를 입력받아 출력하는 프로그램을 작성하라.

다음 4개의 메뉴를 구성하고, 각 메뉴의 선택 시 작동은 다음과 같다.
1. 입력 - 학번, 이름, 성적 순으로 같다. (학생 수 모름 .... 0번 입력 될때까지)
2. 출력 - 성적(평균)에 따라 (정렬된 형태로 출력)
3. 검색 - 이름으로 해당 학생의 학점, 성적을 출력
4. 종료
조건>
	1. 번호 중복 불가, 이름 중복 가능
	2. 검색 -> 이름 검색으로 하고 먼저 찾은 것을 우선 출력
	3. 메모리 할당 활용, 자기 참조 구조체 활용
	4. 입력/출력/검색은 각각 개별 함수로 구현한다.

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct student
{
	char name[30];
	int num;
	double avgGrade;
	struct student* nextStudent;
};
typedef struct student Student;

void Push(Student** head, double data)
{
	Student* newStudent = (Student*)malloc(sizeof(Student));
	newStudent->avgGrade = data;
	newStudent->nextStudent = *head;
	*head = newStudent;
}
void SortStudents(Student** head)
{
	Student* current = *head;
	while (current != NULL)
	{
		Student* temp = current;
		while (temp->nextStudent != NULL && temp->nextStudent->avgGrade < current->avgGrade)
			temp = temp->nextStudent;
		
		Student* next = current->nextStudent;

		current->nextStudent = temp->nextStudent;
		temp->nextStudent = current;

		current = next;
	}
}

void main()
{
	Student* head = NULL;

	while (1)
	{
		double temp;
		double grades[3];

		printf("점수 : ");
		scanf("%lf", &temp);

		if (temp == 0)
			break;
		
		Push(&head, temp);

		//printf("학번 : ");
		//scanf("%d", &student.num);

		//printf("이름 : ");
		//scanf("%s", &student.name);

		//printf("국어, 영어, 수학 점수 : ");
		//scanf("%lf %lf %lf", grades[0], grades[1], grades[2]);
		//student.avgGrade = (grades[0] + grades[1] + grades[2]) / 3.0;
	}
	SortStudents(&head);
	printf("[%lf]\n", head->avgGrade);

	//Student* current = head;
	//while (current != NULL)
	//{
	//	printf("%lf ", current->avgGrade);
	//	current = current->nextStudent;
	//}
}