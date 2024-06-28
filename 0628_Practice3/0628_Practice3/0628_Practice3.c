/*
문자열에서 특정 단어를 찾아서 다른 단어로 바꾸는 프로그램을 작성하라.

ex) "I am a boy. I am happy!"
-> 찾을 단어 : boy
-> 바꿀 단어 : girl
-> 변경된 문자열 > I am a girl. I am happy!

1. strstr 쓰지 않고 my_strstr를 만들기

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define max(x, y) x > y ? x : y;

char* my_strstr(char* sentence, char* word)
{
	int targetPos;
	int j = 0;

	for (int i = 0; i < strlen(sentence); i++) {
		if (sentence[i] == word[j])
		{
			if (j == 0) targetPos = i;
			j++;

			if (j == strlen(word))
				return targetPos;
		}
		else
			j = 0;
	}
	return -1;
}

void main()
{
	char sentence[50];
	char changedSentence[50];
	char word[50];
	char changingWord[50];

	printf("문장을 입력하세요: ");
	gets(sentence);

	printf("찾을 단어 : ");
	gets(word);

	printf("바꿀 단어 : ");
	gets(changingWord);

	char* pos = my_strstr(sentence, word);
	char* wordEnd = pos + strlen(word);

	char* ps = sentence;
	char* pcs = changedSentence;

	while (*ps != '\0')
	{
		*ps = 
	}

	//strncpy(pos, changingWord, length);
	

}