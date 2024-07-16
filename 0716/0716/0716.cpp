#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define MILE 1.60934

using namespace std;

void PrintMice()
{
    cout << "Three blind mice" << endl;
}

void PrintRun()
{
    cout << "See how they run" << endl;
}

double ConvertCelsius(double celsius)
{
    return 1.8 * celsius + 32.0;
}

int main()
{
    // std::cout
    
    int distance;
    cout << "거리 마일 : ";
    cin >> distance;

    cout << distance * MILE << "km" << endl << endl;

    for (int i = 0; i < 2; i++)
        PrintMice();

    for (int i = 0; i < 2; i++)
        PrintRun();
    cout << endl;

    double celsius;
    cout << "섭씨 온도를 입력하고 Enter 키를 누르십시오 : ";
    cin >> celsius;

    cout << "섭씨 " << celsius << "도는 화씨로 " << ConvertCelsius(celsius) << "도입니다." << endl;


    return 0;
}
