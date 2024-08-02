/*
Do it 자료구조&알고리즘 140p, 148p
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct IntStack {
	int max = 0;
	int ptr = -1;
	int* stk;
};

void Initialize(IntStack* s, int max);
int Push(IntStack* s, int x);
int Pop(IntStack* s);
int Peek(const IntStack* s);
void Clear(IntStack* s);
int Capacity(const IntStack* s);
int Size(const IntStack* s);
int IsEmpty(const IntStack* s);
int IsFull(const IntStack* s);
int Search(const IntStack* s, int x);
void Print(const IntStack* s);
void Terminate(const IntStack* s);

int main()
{
	IntStack s;
	Initialize(&s, 64);

	while (1)
	{
		int menu, x, searchIndex;
		printf("\n현재 데이터 수: %d / %d\n", Size(&s), Capacity(&s));
		printf("(1)푸시  (2)팝  (3)피크  (4)출력  (5)비우기  (6)검색  (0)종료: ");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			printf("데이터: ");
			scanf("%d", &x);
			Push(&s, x);
			break;

		case 2:
			Pop(&s);
			break;

		case 3:
			Peek(&s);
			break;

		case 4:
			Print(&s);
			break;

		case 5:
			Clear(&s);
			break;

		case 6:
			printf("데이터: ");
			scanf("%d", &x);
			searchIndex = Search(&s, x);

			if (searchIndex == -1)
				puts("데이터를 찾지 못했습니다.\n");
			else
				printf("데이터를 %d 인덱스에서 찾았습니다.\n", searchIndex);
			break;

		default:
			printf("종료합니다.\n");
			return 0;
		}
	}
	return 0;
}

void Initialize(IntStack* s, int max)
{
	s->stk = (int*)calloc(max, sizeof(int));
	if (s->stk == NULL)
	{
		puts("스택 생성에 실패했습니다.\n");
		exit(1);
	}
	s->max = max;
}

int Push(IntStack* s, int x)
{
	if (IsFull(s))
	{
		puts("오류: 푸시에 실패했습니다.\a\n");
		return -1;
	}
	int lastIndex = s->ptr;
	s->stk[lastIndex + 1] = x;
	s->ptr++;

	return 1;
}

int Pop(IntStack* s)
{
	if (IsEmpty(s))
	{
		puts("팝 실패: 스택이 비어있습니다.\n");
		return -1;
	}
	int popped = s->stk[s->ptr];
	s->stk[s->ptr] = 0;
	s->ptr--;

	printf("팝 데이터: %d\n", popped);
	return popped;
}

int Peek(const IntStack* s)
{
	if (IsEmpty(s))
	{
		puts("피크 실패: 스택이 비어있습니다.\n");
		return -1;
	}
	int peeked = s->stk[s->ptr];
	printf("피크 데이터: %d\n", peeked);
	return peeked;
}

void Clear(IntStack* s)
{
	int stackSize = Size(s);

	for (int i = 0; i < stackSize; i++)
		s->stk[i] = 0;

	s->ptr = -1;
	puts("스택을 비웠습니다.\n");
}

int Capacity(const IntStack* s)
{
	return s->max;
}

int Size(const IntStack* s)
{
	return s->ptr + 1;
}

int IsEmpty(const IntStack* s)
{
	return (Size(s) == 0);
}

int IsFull(const IntStack* s)
{
	return (s->ptr + 1 == s->max);
}

int Search(const IntStack* s, int x)
{
	int stackSize = Size(s);
	for (int i = 0; i < stackSize; i++)
	{
		if (s->stk[i] == x)
			return i;
	}
	return -1;
}

void Print(const IntStack* s)
{
	printf("=== 현재 스택 내용 ===\n");

	for (int i = 0; i < Size(s); i++)
		printf("%d ", s->stk[i]);
	printf("\n\n");
}

void Terminate(const IntStack* s)
{
	free(s->stk);
}