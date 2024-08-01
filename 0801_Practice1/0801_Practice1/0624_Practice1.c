/*
Doit 자료구조&알고리즘 124p
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int int_cmp(const int* target, const int* b)
{
	if (*target < *b)
		return -1;
	else if (*target > *b)
		return 1;
	else
		return 0;
}

void main()
{
	int nx, target;
	puts("bsearch 함수를 사용하요 검색");
	printf("요소 개수 : ");
	scanf("%d", &nx);

	int* x = calloc(nx, sizeof(int));

	printf("오름차순으로 입력하세요.\n");

	for (int i = 0; i < nx; i++)
	{
		do {
			printf("x[%d]: ", i);
			scanf("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}
	printf("검색값: ");
	scanf("%d", &target);

	int* p = bsearch(
		&target,
		x,
		nx,
		sizeof(int),
		(int(*)(const void*, const void*)) int_cmp
	);
	if (p == NULL)
		puts("검색에 실패했습니다.\n");
	else
		printf("%d은(는) x[%d]에 있습니다.\n", target, (int)(p - x));

	free(x);
}