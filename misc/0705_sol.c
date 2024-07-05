#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[30];
    int num;
    double avgGrade;
    struct student* nextStudent;
};
typedef struct student Student;

void Push(Student** head, double data) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->avgGrade = data;
    newStudent->nextStudent = *head;
    *head = newStudent;
}

void SortedInsert(Student** sorted, Student* newNode) {
    if (*sorted == NULL || (*sorted)->avgGrade >= newNode->avgGrade) {
        newNode->nextStudent = *sorted;
        *sorted = newNode;
    } else {
        Student* current = *sorted;
        while (current->nextStudent != NULL && current->nextStudent->avgGrade < newNode->avgGrade) {
            current = current->nextStudent;
        }
        newNode->nextStudent = current->nextStudent;
        current->nextStudent = newNode;
    }
}

void SortStudents(Student** head) {
    Student* sorted = NULL; // Create a new sorted list
    Student* current = *head;
    while (current != NULL) {
        Student* next = current->nextStudent;
        SortedInsert(&sorted, current); // Insert into sorted list
        current = next;
    }
    *head = sorted; // Update head to point to the new sorted list
}

void PrintStudents(Student* head) {
    Student* current = head;
    while (current != NULL) {
        printf("%lf\n", current->avgGrade);
        current = current->nextStudent;
    }
}

int main() {
    Student* head = NULL;

    while (1) {
        double temp;
        printf("Enter a grade (0 to stop): ");
        scanf("%lf", &temp);

        if (temp == 0)
            break;

        Push(&head, temp);
    }

    SortStudents(&head);
    printf("Sorted Grades:\n");
    PrintStudents(head);

    // Free the allocated memory
    Student* current = head;
    while (current != NULL) {
        Student* next = current->nextStudent;
        free(current);
        current = next;
    }

    return 0;
}
