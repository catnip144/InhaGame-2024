/*

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

enum season {SPRING, SUMMER, FALL, WINTER};

void main()
{
	enum season ss;
	char* pc = NULL;

	ss = WINTER;
	switch (ss)
	{
	case SPRING:
		pc = "inline"; break;
	case SUMMER:
		pc = "swimming"; break;
	case FALL:
		pc = "trip"; break;
	case WINTER:
		pc = "skiing"; break;
	}
	printf("나의 레저 활동 => %s\n", pc);
}
