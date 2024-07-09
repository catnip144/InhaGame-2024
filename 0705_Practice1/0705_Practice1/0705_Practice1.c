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

struct student {
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

    // 헤드가 가리키는 곳을 newStudent도 가리킨다.
    newStudent->nextStudent = *head;

    // 헤드가 가리키는 곳을 newStudent으로 바꾼다.
    *head = newStudent;
}

void SortedInsert(Student** sorted, Student* newStudent)
{
    // 연결 리스트의 첫 초기화 or 리스트의 맨 처음(최솟값) 보다 작은 값일 때
    if (*sorted == NULL || (*sorted)->avgGrade >= newStudent->avgGrade)
    {
        // sorted 가 가리키는 곳을 newStudent도 가리킨다.
        newStudent->nextStudent = *sorted;

        // sorted 가 가리키는 곳을 newStudent으로 바꾼다.
        *sorted = newStudent;
    }
    else
    {
        Student* current = *sorted;
        while (current != NULL && current->nextStudent->avgGrade <= newStudent->avgGrade)
            current = current->nextStudent;

        // 현재 멈춘자리(current)가 가리키는 곳을 newStudent 도 가리킨다.
        newStudent->nextStudent = current->nextStudent;

        // current가 가리키는 곳을 newStudent으로 바꾼다 (newStudent가 current보다 큰 것이 마지막으로 확인되었기 때문).
        current->nextStudent = newStudent;
    }
}

void SortStudents(Student** head)
{
    Student* sorted = NULL;
    Student* current = *head;

    while (current != NULL)
    {
        Student* next = current->nextStudent;
        SortedInsert(&sorted, current);
        current = next;
    }
    *head = sorted;
}

void PrintStudents(Student** head)
{
    Student* current = *head;
    while (current != NULL)
    {
        printf("%lf\n", current->avgGrade);
        current = current->nextStudent;
    }
}

int main() {
    Student* head = NULL;

    while (1) {
        double temp;
        char name[100];


        printf("Enter student name: ");


        if (temp == 0)
            break;

        Push(&head, temp);
    }
    SortStudents(&head);
    printf("Sorted Grades:\n");
    PrintStudents(&head);

    //// Free the allocated memory
    //Student* current = head;
    //while (current != NULL) {
    //    Student* next = current->nextStudent;
    //    free(current);
    //    current = next;
    //}

    return 0;
}