/*
혼공C 도전 실전 예제
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 참고
//printf("%d", NULL == '\0'); // 1
//printf("%d", NULL == 0);    // 1

void main()
{
	char sentence[80] = { 0, };
	int caseDiff = 'a' - 'A';
	int changedLetters = 0;

	printf("문장 입력 : ");
	gets(sentence);

	for (int i = 0; sentence[i]; i++)
	{
		if (sentence[i] >= 'A' && sentence[i] <= 'Z')
		{
			sentence[i] += caseDiff;
			changedLetters++;
		}
	}
	printf("바뀐 문장 : ");
	puts(sentence);
	printf("바뀐 문자 수 : %d", changedLetters);
}