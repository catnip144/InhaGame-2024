#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main()
{
	int* arr;
	int num;
	int size = 6;
	int count = 0;
	arr = (int*)calloc(size, sizeof(int));

	while (1)
	{
		printf("숫자 입력(종료: -999) :");
		scanf("%d", &num);

		if (num == -999)
			break;

		arr[count] = num;
		++count;

		if (count >= size - 1)
		{
			size *= 2;
			arr = (int*)realloc(arr, sizeof(int) * size);
		}
	}
	for (int i = 0; i < count / 2; i++)
	{
		printf("\na[%d] 와 a[%d] 를 교환합니다.\n", i, count - 1 - i);
		int temp = arr[i];
		arr[i] = arr[count - 1 - i];
		arr[count - 1 - i] = temp;

		for (int j = 0; j < count; j++)
			printf("%d ", arr[j]);
		printf("\n\n");
	}
	printf("역순 정렬을 종료합니다.\n");
}