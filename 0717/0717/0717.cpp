#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <array>

using namespace std;

int main()
{
    //cout << "지금 사시는 아파트에 언제 입주하셨습니까?\n";
    //int year;
    //(cin >> year).get();

    //cout << "사시는 도시를 말씀해 주시겠습니까?\n";

    //char address[80];
    //cin.getline(address, 80);

    //cout << "아파트 입주 연도: " << year << endl;
    //cout << "도시: " << address << endl;
    //cout << "등록이 완료되었습니다!\n";

    //////////////////////////////////////////////////////////////////////

    //string str = "apple";
    //string str2 = "banana";

    //cout << str << endl;

    //// 이게 가능하다
    //str2 = str;
    //cout << str2 << endl;

    //string str3;
    //str3 = str + str2;

    //////////////////////////////////////////////////////////////////////

    //char charr1[20];
    //char charr2[20] = "jaguar";

    //string str1;
    //string str2 = "panther";

    //str1 = str2;
    //strcpy(charr1, charr2);

    //str1 += " paste";
    //strcat(charr1, " juice");

    //int len1 = str1.size();
    //int len2 = strlen(charr1);

    //cout << str1 << " 문자열에는 "
    //    << len1 << "개의 문자가 들어 있다\n";

    //cout << charr1 << " 문자열에는 "
    //     << len2 << "개의 문자가 들어 있다\n";

    //////////////////////////////////////////////////////////////////////

    //string str;
    //
    //cout << "또 다른 텍스트 한 행을 입력하시오\n";
    //getline(cin, str);

    //cout << "입력한 텍스트: " << str << endl;
    //cout << "입력 이후 str에 있는 문자열의 길이: " << str.size() << endl;

    //////////////////////////////////////////////////////////////////////

    // 메모리 할당과 해제

    int* p = new int;
    delete p; // free(p)

    //////////////////////////////////////////////////////////////////////

    // 배열 메모리 할당, 해제

    int* psome = new int[10];
    delete [] psome;

    //////////////////////////////////////////////////////////////////////

    //// double형 데이터 3개 저장
    //double* p3 = new double[3];

    //p3[0] = 0.2;
    //p3[1] = 0.5;
    //p3[2] = 0.8;
    //cout << "p3[0]은 " << p3[0] << "입니다.\n";
    //cout << "p3[1]은 " << p3[1] << "입니다.\n";
    //cout << "p3[2]은 " << p3[2] << "입니다.\n\n";

    //// 포인터 증가
    //cout << "p3 = p3 + 1\n\n";
    //p3 = p3 + 1;

    //cout << "이제는 p3[0]이 " << p3[0] << "이고, " << "p3[1]이 " << p3[1] << "입니다.\n\n";

    //// 반드시 되돌려야 함 ... Debug assertion fail
    //p3 = p3 - 1;
    //delete[] p3;

    //////////////////////////////////////////////////////////////////////

    // C, original C++
    double a1[5] = { 1,2, 2.4, 3.6, 4.8 };

    vector<double> a2(4);

    a2[0] = 1.0 / 3.0;
    a2[1] = 1.0 / 5.0;

    a2[2] = 1.0 / 7.0;
    a2[3] = 1.0 / 9.0;

    array<double, 4> a3 = { 3.14, 2.72, 1.62, 1.41 };
    array<double, 4> a4;
    a4 = a3;

    cout << "a1[2] : " << a1[2] << " at " << &a1[2] << endl;
    cout << "a2[2] : " << a2[2] << " at " << &a2[2] << endl;
    cout << "a3[2] : " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2] : " << a4[2] << " at " << &a4[2] << endl << endl;

    // 잘못됨
    a1[-2] = 20.2;
    cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
}
