#include <iostream>
using namespace std;

void ConvertHeight()
{
    const int METER = 100;
    int height, meters, centimeters;

    cout << "키를 입력하세요 :_____\b\b\b\b\b";
    cin >> height;

    meters = height / METER;
    centimeters = height % METER;

    cout << meters << "m " << centimeters << "cm" << endl << endl;
}

void ConvertLatitude()
{
    const double MINUTE_DEGREE = 1 / 60.0;
    const double SECOND_DEGREE = MINUTE_DEGREE / 60.0;

    int degrees, minutesOfArc, secondsOfArc;

    cout << "위도룰 도, 분, 초 단위로 입력하시오:" << endl;
    cout << "먼저, 도각을 입력하시오: ";
    cin >> degrees;

    cout << "다음에, 분각을 입력하시오: ";
    cin >> minutesOfArc;

    cout << "끝으로, 초각을 입력하시오: ";
    cin >> secondsOfArc;

    double totalDegrees = degrees + minutesOfArc * MINUTE_DEGREE + secondsOfArc * SECOND_DEGREE;
    cout << endl << degrees << "도, " << minutesOfArc << "분, " << secondsOfArc << "초 = " << totalDegrees << "도" << endl << endl;
}

void PopulationPercent()
{
    long long worldPopulation, nationPopulation;
    cout << "세계 인구수를 입력하시오: ";
    cin >> worldPopulation;

    cout << "국가 인구수를 입력하시오: ";
    cin >> nationPopulation;
    
    double percentage = (double)nationPopulation / worldPopulation * 100;
    cout << "세계 인구수에서 현재 국가가 차지하는 비중은 " << percentage << "%이다." << endl << endl;
}

void ConvertGasoline()
{
    const double GALLON = 3.875;
    const double MILE = 62.14;

    double liters;
    cout << "100km 당 리터(L) 수를 입력하세요: ";
    cin >> liters;

    double gallons = liters / GALLON;
    int milesPerGallon = 62.14 / gallons;

    cout << "미국 단위 : " << milesPerGallon << "mpg";
}

int main()
{
    ConvertHeight();
    ConvertLatitude();
    PopulationPercent();
    ConvertGasoline();
}
