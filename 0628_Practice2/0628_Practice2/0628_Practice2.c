/*
혼공C 381쪽 도전예제
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//char* my_strcat(char* pd, char* ps);
//char* my_strlen(char* ps);
int my_strcmp(char* pa, char* pb);

void main()
{
	char a[30], b[30], c[30];
	char* p1 = a, * p2 = b, * p3 = c;
	char* temp;

	printf("세 단어 입력 : ");
	scanf("%s %s %s", a, b, c);

	if (my_strcmp(p1, p2) > 0)
	{
		temp = p1;
		p1 = p2;
		p2 = temp;
	}
	if (my_strcmp(p2, p3) > 0)
	{
		temp = p2;
		p2 = p3;
		p3 = temp;
	}
	if (my_strcmp(p1, p2) > 0)
	{
		temp = p1;
		p1 = p2;
		p2 = temp;
	}
	printf("%s, %s, %s", p1, p2, p3);
}
//char* my_strcat(char* pd, char* ps)
//{
//	char* po = pd;
//
//	while (*pd != '\0')
//	{
//		pd++;
//	}
//	while (*ps != '\0')
//	{
//		*pd = *ps;
//		pd++;
//		ps++;
//	}
//	*pd = '\0';
//	return po;
//}
//char* my_strlen(char* ps)
//{
//	int cnt = 0;
//	while (*ps != '\0')
//	{
//		cnt++;
//		ps++;
//	}
//	return cnt;
//}
int my_strcmp(char* pa, char* pb)
{
	while ((*pa == *pb) && (*pa != '\0'))
	{
		pa++;
		pb++;
	}
	if (*pa > *pb) return 1;
	else if (*pa < *pb) return -1;
	else return 0;
}

// double buffering