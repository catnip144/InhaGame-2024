/*
Q2.
혼공C 582쪽 도전 실전 예제

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

void main()
{
	FILE* afp, * bfp, * cfp;
	char aWord[100], bWord[100];
	int count = 0;

	afp = fopen("../data/a.txt", "r");
	bfp = fopen("../data/b.txt", "r");
	cfp = fopen("../data/c.txt", "w");

	while (1)
	{
		if (fscanf(bfp, "%s", bWord) == EOF)
			break;
		
		int animalExsists = 0;
		while (1)
		{
			if (fscanf(afp, "%s", aWord) == EOF)
				break;
			
			if (!strcmp(aWord, bWord))
			{
				animalExsists = 1;
				break;
			}
		}
		if (!animalExsists)
		{
			fprintf(cfp, "%s\n", bWord);
			count++;
		}
		rewind(afp);
	}
	fclose(afp);
	fclose(bfp);
	fclose(cfp);
	printf("총 %d마리가 새롭게 추가되었습니다.\n", count);
}