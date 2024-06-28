/*
혼공C 343쪽 도전 실전 예제
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void UpdateLongestName(char* fruit, char* longestFruit, int length)
{
	for (int i = 0; i < length; i++)
	{
		longestFruit[i] = fruit[i];
	}
	longestFruit[length] = 0;
}

void main()
{
	char ch;
	char fruit[30], longestFruit[30];
	int charCount = 0, longestLength = -1, result;

	while (1)
	{
		ch = getchar();

		if (ch == EOF)
			break;

		if (ch == '\n')
		{
			if (longestLength < charCount)
			{
				longestLength = charCount;
				UpdateLongestName(fruit, longestFruit, longestLength);	
			}
			charCount = 0;
			continue;
		}
		fruit[charCount] = ch;
		charCount++;
	}
	printf("가장 긴 단어의 길이 : %d\n", longestLength);
	printf("가장 긴 단어 : %s", longestFruit);
}