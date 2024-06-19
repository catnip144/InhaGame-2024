#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void MySolution()
{
	int M, N;
	int totalLife = (100 - 20) * 365 * 24 * 60;
	int decrease = 3 * 60 + 40;

	scanf("%d %d", &M, &N);
	int decreaseAmount = decrease * N * M * 365;
	int totalDecrease = decreaseAmount;

	int decreasedMinute = totalDecrease % 60;
	totalDecrease = totalDecrease / 60;

	int decreasedHour = totalDecrease % 24;
	totalDecrease = totalDecrease / 24;

	int decreasedDay = totalDecrease % 365;
	int decreasedYear = totalDecrease / 365;

	totalLife = totalLife - decreaseAmount;

	int estimatedMinute = totalLife % 60;
	totalLife = totalLife / 60;

	int estimatedHour = totalLife % 24;
	totalLife = totalLife / 24;

	int estimatedDay = totalLife % 365;
	int estimatedYear = totalLife / 365;

	printf("줄어든 수명 : %d년 %d일 %d시 %d분\n", decreasedYear, decreasedDay, decreasedHour, decreasedMinute);
	printf("기대 수명 : %d살 %d일 %d시 %d분\n", estimatedYear + 20, estimatedDay, estimatedHour, estimatedMinute);
}

void main()
{
	int M, N;
	scanf("%d %d", &M, &N);

	int decreasePerCig = 3 * 60 + 40;
	int totalCigs = 365 * N * M;
	int totalDecreasedMinutes = totalCigs * decreasePerCig;
	int totalLifeMinutes = (100 - 20) * 365 * 24 * 60 - totalDecreasedMinutes;

	int decreasedYear = totalDecreasedMinutes / 60 / 24 / 365;
	int decreasedDay  = totalDecreasedMinutes / 60 / 24 % 365;
	int decreasedHour = totalDecreasedMinutes / 60 % 24;
	int decreasedMin  = totalDecreasedMinutes % 60;

	int estimatedYear = totalLifeMinutes / 60 / 24 / 365;
	int estimatedDay  = totalLifeMinutes / 60 / 24 % 365;
	int estimatedHour = totalLifeMinutes / 60 % 24;
	int estimatedMin  = totalLifeMinutes % 60;

	printf("줄어든 수명 : %d년 %d일 %d시 %d분\n", decreasedYear, decreasedDay, decreasedHour, decreasedMin);
	printf("기대 수명 : %d살 %d일 %d시 %d분\n", estimatedYear + 20, estimatedDay, estimatedHour, estimatedMin);
}

/*
인간 수명이 100년이라 가정
담배 한 개비를 피우면 수명이 3시간 40분이 단축된다고 한다.

어떤 사람이 성인(20살 가정)이 된 이후에
N년간 하루에 M개비씩 담배를 피웠다면

수명은 얼마나 단축되었고 몇 살 까지 살 수 있는지를 계산하는 프로그램을 작성하시오.
M, N은 입력받도록 한다.

기준> N = 20, M = 3

결과>
줄어든 수명 : ?? 년 ?? 일 ?? 시 ?? 분
기대 수명 : ?? 살 ?? 일 ?? 시 ?? 분

//	1800min
//	30hour = 1day (24) + 6hour
*/