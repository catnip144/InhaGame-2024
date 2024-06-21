/*
학생의 전체 평균 점수에 대한 학점을 출력하는 프로그램을 작성하라.
성적이 90이상 A,	성적이 80이상 B,
성적이 70이상 C,	성적이 60이상 D,
그 미만은 F로 처리한다.

프로그램 실행 시 국어, 영어, 수학의 점수를 입력받는다.
그 평균을 구하고, 위 평가기준을 참고하여 적절한 학점을 출력하라.
*/

#define _CRT_SECURE_NO_WARNINGS // 위에 써야 함
#include <stdio.h>

void main()
{
	int kor, eng, math;
	printf("국어 점수: ");
	scanf("%d", &kor);

	printf("영어 점수: ");
	scanf("%d", &eng);

	printf("수학 점수: ");
	scanf("%d", &math);

	int avg = (kor + eng + math) / 3;

	if (avg >= 90)
		printf("성적: A");
	else if (avg >= 80)
		printf("성적: B");
	else if (avg >= 70)
		printf("성적: C");
	else if (avg >= 60)
		printf("성적: D");
	else
		printf("성적: F");
}
