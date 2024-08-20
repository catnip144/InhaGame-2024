/*
Q2.
	용량이 큰 파일을 작은 용량으로 분할해서 작은 단위의 파일로 나누는 프로그램을 작성하라.
	사용자로부터 소스 파일명을 입력 받은 후,
	각각 분할된 작은 파일의 바이트 값을 입력 받아야한다.

	ex> Enter file name : test.png
		Enter file size : 1024
		   -> file test.png.01
		   -> file test.png.02
		   -> file test.png.03
		   -> file test.png.04
		   .....
		   >> Split Done.

Q3.
	사용자로부터 소스 파일의 개수, 소스 파일의 이름, 목적 파일의 이름을 입력 받아
	새로운 하나의 파일로 파일들을 조합하는 프로그램을 작성하라.

	ex> Enter file number : 4
		Enter source file : file test.png.01
		Enter source file : file test.png.02
		Enter source file : file test.png.03
		Enter source file : file test.png.04
		Enter target file : Dest.png
		....
		>> Combine Done.
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void SplitFile()
{
	string fileName;
	ifstream fin;
	int fileSize;
	int totalFileSize;

	while (1)
	{
		cout << "Enter file name : ";
		cin >> fileName;

		fin.open(fileName, ios_base::in | ios_base::out | ios_base::binary);

		if (fin.is_open())
			break;
		else
			cout << "Invalid file name\n\n";
	}
	fin.seekg(0, ios::end);
	totalFileSize = fin.tellg();
	fin.seekg(0, ios::beg);

	cout << "Enter file size : ";
	cin >> fileSize;

	int repeat = totalFileSize / fileSize;
	if (totalFileSize % fileSize) repeat++;

	for (int i = 0; i < repeat; i++)
	{
		ofstream newOf;
		string newFileName = fileName + "." + to_string(i + 1);
		newOf.open(newFileName);

		string buffer;
		buffer.resize(fileSize); // buffer 크기 설정

		fin.read(&buffer[0], fileSize);

		newOf << buffer;
		newOf.close();

		cout << "\t-> file " << newFileName << '\n';
	}
	cout << ">> Split Done.\n";
}

int main()
{
	SplitFile();
	//cout << "Enter file number : ";
	return 0;
}

