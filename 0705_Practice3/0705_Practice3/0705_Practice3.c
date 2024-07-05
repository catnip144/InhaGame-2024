/*
Q3. 구구단 출력.. 99.txt
원하는 구구단을 찾아 출력하는 프로그램을 작성하라.

99.txt
2 x 1 = 2 ......................
출력을 원하는 구구단은 ? 3
3 x 1 = 3

fseek() 이용
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int GetFileLines(FILE* fp)
{
	char line[300];
	int lineCount = 0;
	while (1)
	{
		if (fgets(line, sizeof(line), fp) == NULL)
			break;

		lineCount++;
	}
	rewind(fp);
	return lineCount;
}

void main()
{
	FILE* fp;
	fp = fopen("../data/99.txt", "r");
	int number;

	while (1)
	{
		printf("출력을 원하는 구구단은 ? : ");
		scanf("%d", &number);

		if (number * 9 > GetFileLines(fp))
		{
			int startLine = (number - 1) * 9;
		}
	}
	fclose(fp);
}