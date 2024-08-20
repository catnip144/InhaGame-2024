/*
	파일 입출력
*/
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void eatline();

struct planet
{
	char name[20];		// 행성의 이름
	double population;	// 행성의 인구
	double g;			// 행성의 중력가속도
};

const char* file = "planets.dat";
const int LIM = 20;

int main()
{
	//cout.setf(ios_base::left, ios_base::adjustfield);
	//cout.setf(ios_base::showpos);
	//cout.setf(ios_base::showpoint);
	//cout.precision(3);

	//// 과학적 E 표기 사용, 이전의 출력 형식 설정을 저장한다.
	//ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield);

	//cout << "왼쪽 정렬:\n";
	//long n;

	//for (n = 1; n <= 41; n += 10)
	//{
	//	cout.width(4);
	//	cout << n << "|";
	//	cout.width(12);
	//	cout << sqrt(double(n)) << "|\n";
	//}
	//// 내부(internal) 정렬로 변경한다
	//cout.setf(ios_base::internal, ios_base::adjustfield);

	//// 디폴트 부동 소수점 표기로 복원한다
	//cout.setf(old, ios_base::floatfield);

	//cout << "내부(internal) 정렬:\n";
	//for (n = 1; n <= 41; n += 10)
	//{
	//	cout.width(4);
	//	cout << n << "|";
	//	cout.width(12);
	//	cout << sqrt(double(n)) << "|\n";
	//}
	//// 오른쪽 정렬 사용, 고정 소수점 표기로 출력한다.
	//cout.setf(ios_base::right, ios_base::adjustfield);
	//cout.setf(ios_base::fixed, ios_base::floatfield);
	//cout << "오른쪽 정렬:\n";

	//for (n = 1; n <= 41; n += 10)
	//{
	//	cout.width(4);
	//	cout << n << "|";
	//	cout.width(12);
	//	cout << sqrt(double(n)) << "|\n";
	//}

	////////////////////////////////////////////////////////////////////////////

//	string filename;
//
//	cout << "새 파일을 위한 이름을 입력하시오: ";
//	cin >> filename;
//
//// 새 파일을 위한 출력 스트림 객체를 fout 이라는 이름으로 생성한다
//	ofstream fout(filename.c_str());
//
//	fout << "비밀 번호 노출에 주의하십시오.\n";
//	cout << "비밀 번호를 입력하십시오: ";
//	float secret;
//
//	cin >> secret;
//	fout << "귀하의 비밀 번호는 " << secret << "입니다.\n";
//	fout.close();
//
//// 새 파일을 위한 입력 스트림 객체를 fin이라는 이름으로 생성한다
//	ifstream fin(filename.c_str());
//	cout << filename << " 파일의 내용은 다음과 같습니다:\n";
//	char ch;
//
//	while (fin.get(ch))
//		cout << ch;
//
//	cout << "프로그램을 종료합니다.\n";
//	fin.close();

	////////////////////////////////////////////////////////////////////////////

	//planet pl;
	//cout << fixed << right;

	//ifstream fin;

	//// 어떤 컴파일러는 ios_base::binary 모드를 받아들이지 않는다
	//fin.open(file, ios_base::in | ios_base::binary);

	//if (fin.is_open())
	//{
	//	cout << file << " 파일의 현재 내용은 다음과 같습니다:\n";
	//	while (fin.read((char*)&pl, sizeof pl))
	//	{
	//		cout << setw(20) << pl.name << ": "
	//			 << setprecision(0) << setw(12) << pl.population
	//			 << setprecision(2) << setw(6)  << pl.g << endl;
	//	}
	//	fin.close();
	//}

	//// 새로운 데이터를 추가한다.
	//ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);

	//if (!fout.is_open())
	//{
	//	cerr << "출력을 위해 " << file << " 파일을 열 수 없습니다.\n";
	//	exit(EXIT_FAILURE);
	//}
	//cout << "행성의 이름을 입력하십시오(끝내려면 빈 줄 입력):\n";
	//cin.get(pl.name, 20);

	//while (pl.name[0] != '\0')
	//{
	//	eatline();
	//	cout << "행성의 인구를 입력하십시오: ";
	//	cin >> pl.population;

	//	cout << "행성의 중력가속도를 입력하십시오: ";
	//	cin >> pl.g;
	//	eatline();

	//	fout.write((char*)&pl, sizeof pl);
	//	cout << "행성의 이름을 입력하십시오(끝내려면 빈 줄 입력):\n";
	//	cin.get(pl.name, 20);
	//}
	//fout.close();

	//// 개정된 파일을 화면에 표시한다.
	//fin.clear();
	//fin.open(file, ios_base::in | ios_base::binary);

	//if (fin.is_open())
	//{
	//	cout << file << " 파일의 개정된 내용은 다음과 같습니다:\n";
	//	while (fin.read((char*)&pl, sizeof(pl)))
	//	{
	//		cout << setw(20) << pl.name << ": "
	//			<< setprecision(0) << setw(12) << pl.population
	//			<< setprecision(2) << setw(6) << pl.g << endl;
	//	}
	//	fin.close();
	//}
	//cout << "프로그램을 종료합니다.\n";

	////////////////////////////////////////////////////////////////////////////

	planet pl;
	cout << fixed;

// 초기의 내용을 화면에 표시한다.
	fstream finout;
	finout.open(file, ios_base::in | ios_base::out | ios_base::binary);

	int ct = 0;
	if (finout.is_open())
	{
		// 시작 위치로 간다
		finout.seekg(0);

		cout << file << " 파일의 현재 내용은 다음과 같습니다:\n";
		while (finout.read((char*)&pl, sizeof pl))
		{
			cout << ct++ << ": " << setw(LIM) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
		}
		if (finout.eof())
			finout.clear(); // eof 플래그 해제
		else
		{
			cerr << file << " 파일을 읽다가 에러 발생.\n";
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << file << " 파일을 열 수 없습니다. 종료.\n";
		exit(EXIT_FAILURE);
	}

// 레코드를 수정한다
	cout << "수정할 레코드 번호를 입력하십시오: ";
	long rec;
	cin >> rec;

	eatline();

	if (rec < 0 || rec >= ct)
	{
		cerr << "잘못된 레코드 번호입니다. 종료.\n";
		exit(EXIT_FAILURE);
	}
	streampos place = rec * sizeof pl;
	finout.seekg(place);

	if (finout.fail())
	{
		cerr << "레코드를 찾다가 에러 발생.\n";
		exit(EXIT_FAILURE);
	}
	finout.read((char*)&pl, sizeof pl);

	cout << "현재 레코드의 내용:\n";
	cout << rec << ": " << setw(LIM) << pl.name << ": "
		<< setprecision(0) << setw(12) << pl.population
		<< setprecision(2) << setw(6) << pl.g << endl;

	if (finout.eof())
		finout.clear();

	cout << "행성의 이름을 입력하십시오: ";
	cin.get(pl.name, LIM);
	eatline();

	cout << "행성의 인구를 입력하십시오: ";
	cin >> pl.population;

	cout << "행성의 중력가속도";

	return 0;
}

void eatline()
{
	while (cin.get() != '\n')
		continue;
}