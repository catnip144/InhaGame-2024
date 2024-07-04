/*
사용자로부터 문자열을 입력 받아서
단어 단위로 역순으로 출력하는 프로그램을 작성하라.
"Quit"가 입력될 때까지 반복한다.

입력 > I am happy
출력 > happy am I

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	char** str = (char**)calloc(5, sizeof(char*));

	while (1)
	{
		char userInput[80] = "", temp[80] = "";
		int size = 5, count = 0, tempIdx = 0;

		printf("문장 입력 : ");
		gets(userInput);

		if (!strcmp(userInput, "Quit"))
			break;

		for (int i = 0; i < strlen(userInput); i++)
		{
			if (userInput[i] == ' ')
			{
				if (count >= size)
				{
					size += 5;
					str = (char**)realloc(str, sizeof(char*) * (size + 1));
				}
				str[count] = (char*)calloc(80, sizeof(char));
				strcpy(str[count], temp);
				strcpy(temp, "");
				tempIdx = 0;
				count++;
			}
			else
				temp[tempIdx++] = userInput[i];
		}
		str[count] = (char*)calloc(80, sizeof(char));
		strcpy(str[count], temp);

		for (int i = count; i >= 0; i--)
			printf("%s\n", str[i]);

		for (int i = 0; i <= count; i++)
			free(str[i]), str[i] = NULL;
	}
	free(str);
}