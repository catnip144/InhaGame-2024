/*
사용자로부터 양의 두 정수를 입력받아 (M, N)
N개 만큼 M의 배수를 출력하는 프로그램을 작성하라.
*/

#define _CRT_SECURE_NO_WARNINGS // 위에 써야 함
#include <stdio.h>

void main()
{
	int M, N;
	scanf("%d %d", &M, &N);

	for (int i = 1; i <= N; i++) {
		printf("%d\n", M * i);
	}
}
