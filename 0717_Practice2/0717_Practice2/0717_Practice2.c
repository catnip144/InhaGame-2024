#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sumof(int startNum, int endNum)
{
    int sum;
    int addUp = endNum + startNum;

    if (startNum > endNum)
    {
        int temp = startNum;
        startNum = endNum;
        endNum = temp;
    }
    int count = (endNum - startNum) / 2 + 1;
    int multiplier = (count / 2);
    sum = addUp * multiplier;

    //if (count % 2 == 0)
    //    sum += 
    
    return sum;
}

int main()
{
    int startNum, endNum;
    printf("시작 숫자와 끝 숫자를 입력하세요 : ");
    scanf("%d %d", &startNum, &endNum);

    printf("구간 내 모든 숫자의 합 : %d", sumof(startNum, endNum));
}
