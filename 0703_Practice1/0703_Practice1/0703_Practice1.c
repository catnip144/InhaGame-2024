/*
Q1. 야구 게임
세 개의 숫자를 입력받아서 다음과 같이
숫자가 있지만 그 위치가 틀렸을 때는 "ball"을 출력하고
숫자와 위치가 맞으면 "strike"를 출력한다.
숫자와 위치가 다 틀리면 "out"을 출력한다.

세 개의 숫자와 위치가 다 맞으면 "homerun"을 표시하고 게임을 끝낸다.

ex> 정답 : 2 1 6 (보여지면 안됨 + 중복 불가)
	2 1 6
1 > 8 3 5 -> out
2 > 6 5 9 -> 0s 1b (6이 있으나 위치가 달라서 ball)
3 > 2 6 5 -> 1s 1b (2의 위치 맞으나 6은 위치 다름)
4 > 2 1 6 -> HR

rand() 활용
rand() % 100 ... 100 미만의 난수가 발생
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void CreateAnswers(int* answers, int* existingNums);
void PrintAnswers(int* answers);

void main()
{
	int answers[3] = { 0, };
	int existingNums[10] = { 0, };
	CreateAnswers(answers, existingNums);

	while (1)
	{
		int pitches[3] = { 0, };
		int throws = 0, strikes = 0, balls = 0;

		printf("\n던질 숫자를 입력하세요 : ");
		scanf("%d %d %d", &pitches[0], &pitches[1], &pitches[2]);

		for (int i = 0; i < 3; i++)
		{
			if (answers[i] == pitches[i])
			{
				printf("strike\n");
				strikes++;
			}
			else if (existingNums[pitches[i]])
			{
				printf("ball\n");
				balls++;
			}
			else
				printf("-\n");
		}
		if (strikes == 3)
		{
			printf("homerun\n");
			break;
		}
		else if (!strikes && !balls)
			printf("out\n");
		else
			printf("Final Score : %ds %db\n", strikes, balls);
	}
}
void PrintAnswers(int* answers)
{
	printf("Answers : ");
	for (int i = 0; i < 3; i++)
		printf("%d ", answers[i]);
	printf("\n");
}
void CreateAnswers(int* answers, int* existingNums)
{
	int index = 0;
	srand(time(NULL));

	while (index < 3)
	{
		int randomNum = rand() % 9 + 1;
		if (!existingNums[randomNum])
		{
			answers[index] = randomNum;
			existingNums[randomNum] = 1;
			index++;
		}
	}
	PrintAnswers(answers);
}