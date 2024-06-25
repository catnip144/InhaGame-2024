#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_char(char ch, int count);
void print_line();

void main()
{
	/*
	print_char('@', 5);
	printf("\n");

	print_line();
	printf("학번\t이름\t전공\t학점\n");
	print_line();
	*/

	return 0;
}

void print_char(char ch, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%c", ch);
	}
}

void print_line(void)
{
	for (int i = 0; i < 50; i++)
	{
		printf("-");
	}
	printf("\n");
}

void Recursive(int count)
{

}