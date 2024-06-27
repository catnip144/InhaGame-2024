/*
Q. 문자열을 입력받아서 광고판에 광고 문자가 출력되는 프로그램을 출력하라.
문자열 흘러가듯이 출력되는 형태로 구현하라.
ex) -> Hello
Hello_
012345
123450

ABCD EF_
BCDE F_A
CDEF _AB
DEF_ ABC
EF_A BCD
F_AB CDE
_ABC DEF
ABCD EF_

조건 1. 최대 127까지 입력 가능하다.
조건 2. 광고판의 크기는 최대 20자 까지 출력 가능하다.

조건 3. 중간에 광고 문자열을 변경할 수 있다.
char temp[10] = "hello";
strcpy(string, temp);

> hi     hi defghi
> hi d
> i de
>  def
> defg

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>

#define LENGTH 27
#define REPEAT 3
#define DELAY 500

void OriginalSolution()
{
	while (1)
	{
		char sentence[128] = { 0, };
		printf("띄울 문장을 입력하세요 : ");
		gets(sentence);

		int sentenceLength = strlen(sentence) + 1;
		int outputLength = sentenceLength > LENGTH ? LENGTH : sentenceLength;
		sentence[sentenceLength - 1] = ' ';

		for (int i = 0; i < sentenceLength * REPEAT; i++)
		{
			system("cls");
			for (int k = 0; k < outputLength; k++)
			{
				printf("%c", sentence[(i + k) % sentenceLength]);
			}
			Sleep(DELAY);
		}
		system("cls");
	}
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>

#define LENGTH 20
#define REPEAT 2
#define DELAY 500

void main()
{
	while (1)
	{
		char sentence[128] = { 0, };
		char* ps = sentence;

		printf("띄울 문장을 입력하세요 : ");
		gets(sentence);

		int sentenceLength = strlen(sentence) + 1;
		int outputLength = sentenceLength > LENGTH ? LENGTH : sentenceLength;
		ps[sentenceLength - 1] = ' ';

		for (int i = 0; i < sentenceLength * REPEAT; i++)
		{
			system("cls");
			for (int k = 0; k < outputLength; k++)
			{
				printf("%c", ps[(i + k) % sentenceLength]);
			}
			Sleep(DELAY);
		}
		system("cls");
	}
}