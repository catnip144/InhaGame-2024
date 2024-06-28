#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void UpdateLongestName(char* fruit, char* longestFruitName)
{
	for (int i = 0; i < strlen(fruit); i++)
	{
		longestFruitName[i] = fruit[i];
	}
	longestFruitName[strlen(fruit)] = 0;
}
void main()
{
	char fruit[30];
	char longestFruitName[30];
	int longestLength = -1;
	int currentLength, result;

	while (1)
	{
		result = scanf("%s", fruit);
		if (result == -1) break;

		currentLength = strlen(fruit);
		if (longestLength < currentLength)
		{
			longestLength = currentLength;
			UpdateLongestName(fruit, longestFruitName);
		}
	}
	printf("가장 긴 단어의 길이 : %d\n", longestLength);
	printf("가장 긴 단어 : %s\n", longestFruitName);
}