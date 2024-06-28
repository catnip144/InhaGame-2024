/*

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void my_gets2(char* str, int size);
void my_gets(char* ps);
char* my_strcpy(char* pd, char* ps);
char* my_strcat(char* pd, char* ps);

void main()
{
	//char ch;

	//// tiger, cookie
	//for (int i = 0; i < 7; i++)
	//{
	//	scanf("%c", &ch);
	//	printf("%c", ch);
	//}

	//while (1)
	//{
	//	scanf("%c", &ch);
	//	if (ch == '\n') break;
	//	printf("%c", ch);
	//}

	/////////////////////////////////////////////////////////////////////

	//char str[7];
	//my_gets(str, sizeof(str));
	//printf("입력한 문자열 : %s\n", str);

	/////////////////////////////////////////////////////////////////////

	//printf("apple이 저장된 시작 주소 값: %p\n", "apple");
	//printf("두 번째 문자의 주소 값: %p\n", "apple" + 1);
	//printf("\n");

	//printf("첫 번째 문자 : %c\n", *"apple");
	//printf("두 번째 문자 : %c\n", *("apple" + 1));
	//printf("배열로 표현한 세 번째 문자 : %c\n", "apple"[2]);

	/////////////////////////////////////////////////////////////////////

	//char str[80];
	//printf("문자열 입력 : ");
	//scanf("%s", str);

	//for (int i = 0; i < 80; i++)
	//	printf("%c", str[i]);
	//printf("\n");

	//printf("첫 번째 단어 : %s\n", str);
	//scanf("%s", str);

	//for (int i = 0; i < 80; i++)
	//	printf("%c", str[i]);
	//printf("\n");

	//printf("버퍼에 남아 있는 두 번째 단어 : %s\n", str);

	/////////////////////////////////////////////////////////////////////

	//char str[80];
	//printf("공백이 포함된 문자열 입력 : ");
	//fgets(str, sizeof(str), stdin);

	//str[strlen(str) - 1] = '\0';
	//printf("입력된 문자열은 %s입니다.\n", str);

	/////////////////////////////////////////////////////////////////////

	//int age;
	//char name[20];

	//printf("나이 입력 : ");
	//scanf("%d", &age);

	//printf("이름 입력 : ");
	////scanf("%s", name); // 공백 등을 parsing 기호로 받아들임
	//gets(name);

	//printf("나이 : %d, 이름 : %s\n", age, name);

	/////////////////////////////////////////////////////////////////////

	//char str[80] = "apple juice";
	//char* ps = "banana";

	//puts(str);			// 줄 바꿈
	//fputs(ps, stdout);	// 줄 바꾸지 않음
	//puts("milk");

	/////////////////////////////////////////////////////////////////////

	//int i = 0;
	//char str[1];
	//char ch;

	//while (1)
	//{
	//	my_gets(str);
	//	printf("%s\n", str);
	//}

	//char str[1];
	//gets(str);

	//printf("%s\n", str);

	/////////////////////////////////////////////////////////////////////

	//char str1[80] = "strawberry";
	//char str2[80] = "apple";
	//char *ps1 = "banana";
	//char *ps2 = str2;

	//printf("최초 문자열 : %s\n", str1);
	//strcpy(str1, str2);
	//printf("바뀐 문자열 : %s\n", str1);		// 다른 char 배열의 문자열 복사

	//strcpy(str1, ps1);
	//printf("바뀐 문자열 : %s\n", str1);		// 문자열 상수를 연결한 포인터 사용

	//strcpy(str1, ps2);
	//printf("바뀐 문자열 : %s\n", str1);		// 배열을 연결한 포인터 사용

	//strcpy(str1, "banana");					// 문자열 상수 이용
	//printf("바뀐 문자열 : %s\n", str1);

	/////////////////////////////////////////////////////////////////////

	//char str[20] = "mango tree";
	//strncpy(str, "apple-pie", 5);
	//printf("%s\n", str);

	//strncpy(str, "apple-pie" + 6, 3);
	//printf("%s\n", str);

	/////////////////////////////////////////////////////////////////////

	//char str[80] = "straw"; // 반드시 초기화를 해줘야 한다.

	//strcat(str, "berry");
	//printf("%s\n", str);

	//strncat(str, "piece", 3); // 메모리 크기 주의
	//printf("%s\n", str);

	/////////////////////////////////////////////////////////////////////

	//char str1[80];
	//char str2[80];
	//char* resp;

	//printf("2개의 과일 이름 입력: ");
	//scanf("%s%s", str1, str2);

	//if (strlen(str1) > strlen(str2))
	//	resp = str1;
	//else
	//	resp = str2;
	//printf("이름이 긴 과일은 : %s\n", resp);

	/////////////////////////////////////////////////////////////////////

	//char str1[80] = "Pear";
	//char str2[80] = "peach";

	//printf("%s v.s %s\n사전에 나중에 나오는 과일 이름 : ", str1, str2);
	//if (strcmp(str1, str2) > 0)
	//	printf("%s\n", str1);
	//else
	//	printf("%s\n", str2);

	/////////////////////////////////////////////////////////////////////

	//char str[80] = "strawberry";
	//printf("%s\n", str);
	//char* pR = NULL;
	//pR = my_strcpy(str, "apple");
	//
	//if (pR != NULL)
	//{
	//	// success
	//	printf("바꾼 후 문자열 : %s\n", str);
	//	printf("다른 문자열 대입 : %s\n", my_strcpy(str, "kiwi"));
	//}

	/////////////////////////////////////////////////////////////////////

	
}
void my_gets2(char* str, int size)
{
	char ch;
	int i = 0;
	scanf("%c", &ch);

	while (ch != '\n' && i < size - 1)
	{
		str[i] = ch;
		i++;
		scanf("%c", &ch);
	}
	str[i] = '\0';
}
void my_gets(char* ps)
{
	char ch;
	while ((ch = getchar()) != '\n')
	{
		*ps = ch;
		ps++;
	}
	*ps = '\0';
}

char* my_strcpy(char* pd, char* ps)
{
	char* po = pd;
	while (*ps != '\0')
	{
		*pd = *ps;
		pd++;
		ps++;
	}
	*pd = '\0';
	return po;
}
char* my_strcat(char* pd, char* ps)
{

}