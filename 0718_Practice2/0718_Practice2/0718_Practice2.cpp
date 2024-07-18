#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

/*
Q3. 1 ~ 10 사이의 정수를 입력받아 다음과 같은 형태로 출력하는 프로그램을 작성하라.

ex) 라인 수 입력 : 5

      1
     212
    32123
   4321234
  543212345

  4
  3
  2
  1
  0
*/

using namespace std;

int main()
{
    int n;
    cout << "라인 수 입력 : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
            printf(" ");

        int start = i + 1;
        int temp = start;

        while (temp > 1)
        {
            cout << temp;
            temp--;
        }
        while (temp <= start)
        {
            cout << temp;
            temp++;
        }
        cout << endl;
    }
}
