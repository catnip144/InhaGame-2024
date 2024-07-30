#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

string version1(const string& s1, const string& s2);
const string& version2(string& s1, const string& s2);
const string& version3(string& s1, const string& s2);

void file_it(ostream& os, double fo, const double fe[], int n);
const int LIMIT = 5;

char* left(const char* str, int n = 1);
const int ArSize = 80;

int main()
{
	//int rats = 101;
	//int& rodents = rats;

	//cout << "rats= " << rats;
	//cout << ", rodents = " << rodents << endl;
	//rodents++;

	//cout << "rats = " << rats;
	//cout << ", rodents = " << rodents << endl;

	//////////////////////////////////////////////////////////////

	//string input;
	//string copy;
	//string result;

	//cout << "문자열을 입력하시오: ";
	//getline(cin, input);
	//copy = input;

	//result = version1(input, "***");
	//cout << "바뀐 문자열: " << result << endl;
	//cout << "원래 문자열: " << input << endl;

	//input = copy;
	//result = version2(input, "###");
	//cout << "바뀐 문자열: " << result << endl;
	//cout << "원래 문자열: " << input << endl;

	//input = copy;
	//result = version3(input, "!!!");
	//cout << "바뀐 문자열: " << result << endl;
	//cout << "원래 문자열: " << input << endl;

	//////////////////////////////////////////////////////////////

	//ofstream fout;
	//const char* fn = "ep-data.txt";
	//fout.open(fn);

	//if (!fout.is_open())
	//{
	//	cout << fn << " 파일을 열 수 없습니다. 끝.\n";
	//	exit(EXIT_FAILURE);
	//}
	//double objective;
	//cout << "대물렌즈 초점거리를 mm 단위로 입력하십시오: ";
	//cin >> objective;

	//double eps[LIMIT];
	//cout << LIMIT << "가지 대안렌즈의 초점거리를 mm 단위로 입력하십시오:\n";

	//for (int i = 0; i < LIMIT; i++)
	//{
	//	cout << "대안렌즈 #" << i + 1 << ": ";
	//	cin >> eps[i];
	//}
	//file_it(fout, objective, eps, LIMIT);
	//file_it(cout, objective, eps, LIMIT);
	//cout << "종료\n";

	//////////////////////////////////////////////////////////////

	char sample[ArSize];

	cout << "문자열을 입력하십시오:\n";
	cin.get(sample, ArSize);

	char* ps = left(sample, 4);
	cout << ps << endl;
	delete[] ps;

	ps = left(sample);
	cout << ps << endl;
	delete[] ps;

	return 0;
}

string version1(const string& s1, const string& s2)
{
	string temp;
	temp = s2 + s1 + s2;
	return temp;
}

const string& version2(string& s1, const string& s2)
{
	s1 = s2 + s1 + s2;
	return s1;
}

const string& version3(string& s1, const string& s2)
{
	// 나쁜 설계 : 지역 변수에 대한 참조를 리턴하므로 안전하지 않다.
	string temp;
	temp = s2 + s1 + s2;
	return temp;
}

void file_it(ostream& os, double fo, const double fe[], int n)
{
	ios_base::fmtflags initial;
	initial = os.setf(ios_base::fixed);

	os.precision(0);
	os << "대물 렌즈의 초점거리 : " << fo << " mm\n";
	os.setf(ios::showpoint);

	os.precision(1);
	os.width(17);
	os << "대안 렌즈 초점거리";
	os.width(15);
	os << "확대배율" << endl;

	for (int i = 0; i < n; i++)
	{
		os.width(17);
		os << fe[i];
		os.width(15);
		os << int(fo / fe[i] + 0.5) << endl;
	}
	os.setf(initial);
}

char* left(const char* str, int n)
{
	if (n < 0)
		n = 0;

	int i;
	char* p = new char[n + 1];
	for (i = 0; i < n && str[i]; i++)
		p[i] = str[i];

	while (i <= n)
		p[i++] = '\0';

	return p;
}