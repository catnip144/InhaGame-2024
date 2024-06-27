/*
	혼공C 320 도전 실전 예제
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input_nums(int* lotto_nums);
void print_nums(int* lotto_nums);

void main()
{
	int lotto_nums[6];

	input_nums(lotto_nums);
	print_nums(lotto_nums);
}
void input_nums(int* lotto_nums)
{
	int existingNums[46] = { 0, };

	for (int i = 0; i < 6; i++)
	{
		printf("번호 입력 : ");
		scanf("%d", &lotto_nums[i]);

		if (existingNums[lotto_nums[i]])
		{
			printf("같은 번호가 있습니다!\n");
			i--;
			continue;
		}
		existingNums[lotto_nums[i]] = 1;
	}
}
void print_nums(int* lotto_nums)
{
	printf("로또 번호 : ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", lotto_nums[i]);
	}
}