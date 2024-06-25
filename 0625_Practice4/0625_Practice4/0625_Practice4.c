/*
달팽이 한 마리가 한 달이 지나면 어른이 되고,
다시 한달이 지나면 새끼를 낳는다.

새로 태어난 달팽이 역시 한달이 지나면 어른이 되고,
다시 한달 후 부터 새끼를 낳는다고 할 때,

달팽이가 매달 새끼를 낳으면 1년 후 전체 달팽이의 수는 얼마인지
알 수 있도록 프로그램을 작성하라.

가정 1. 달팽이는 자웅동체이다.
가정 2. 달팽이는 1년 만에 죽지 않는다.
가정 3. 처음 새끼 달팽이는 1마리이다.

새끼, 성체 달팽이 수를 매달 확인할 수 있도록 변화도 출력하라. (성체: , 새끼: )

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//void MySolution()
//{
//	int adult = 0;
//	int child = 1;
//
//	for (int i = 1; i <= 12; i++)
//	{
//		int newChildren = adult;
//		int newAdult = child;
//
//		adult += newAdult;
//		child = newChildren;
//
//		PrintSnails(i, child, adult);
//	}
//	printf("총 달팽이 수 : %d\n", adult + child);
//}
void PrintSnails(int month, int child, int adult)
{
	printf("%2d달 후: 새끼 달팽이:%3d, 성체 달팽이:%3d\n", month, child, adult);
}
int GrowSnails(int month, int child, int adult)
{
	if (month > 12)
		return child + adult;

	PrintSnails(month, child, adult);

	// 함수의 인수에 바로 반영
	return GrowSnails(month + 1, adult, adult + child);
}
void main()
{
	printf("총 달팽이 수 : %d\n", GrowSnails(1, 1, 0));
}