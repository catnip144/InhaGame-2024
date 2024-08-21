/*
	Q1. Encoding
		파일 내의 모든 바이트에 임의 수를 더해 파일을 부호화하라.
		사용자가 입력 파일 이름과 출력 파일 이름을 입력하면
		입력 파일의 암호화된 버전을 출력 파일로 저장하는 프로그램을 작성하라.

		ex> Input source filename : source.txt
			Input encoding filename : encoding.txt
			encoding.txt 에는 더한 임의 수를 알아 볼 수 있도록 정보 기입.

	Q2. Decoding
		암호화된 파일을 복호화하는 프로그램을 작성하라.
		사용자가 입력 파일 이름과 출력 파일 이름을 입력하면
		입력 파일의 암호가 풀린 버전을 출력 파일에 저장하라.
		파일에서 더해진 임의 수에 대한 정보를 읽어서 decoding 하도록 한다.
		
		ex> Input source filename : encoding.txt
			Input decoding filename : dest.txt
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void EncodeFile()
{
	string sourceFile, encodedFile;
	ifstream ifs;
	ofstream ofs;

	srand(time(NULL));
	int randNum = rand() % 5 + 1;
	int fileSize;

	while (1)
	{
		cout << "Input source filename : ";
		cin >> sourceFile;

		ifs.open(sourceFile, ios::binary);

		if (ifs.is_open())
			break;
		else
			cout << "Wrong file name.\n";
	}
	ifs.seekg(0, ios::end);
	fileSize = ifs.tellg();
	ifs.seekg(0, ios::beg);

	cout << "Input encoding filename : ";
	cin >> encodedFile;
	ofs.open(encodedFile, ios::binary);

	char buffer;
	ofs << randNum << endl;

	while (fileSize--)
	{
		ifs.read(&buffer, 1);
		buffer += randNum;
		ofs.write(&buffer, 1);
	}
	cout << "인코딩 완료" << endl;
}
void DecodeFile()
{
	string sourceFile, decodedFile;
	ifstream ifs;
	ofstream ofs;

	int fileSize;
	int decodingKey;

	while (1)
	{
		cout << "Input source filename : ";
		cin >> sourceFile;

		ifs.open(sourceFile, ios::binary);

		if (ifs.is_open())
			break;
		else
			cout << "Wrong file name.\n";
	}
	ifs.seekg(0, ios::end);
	fileSize = ifs.tellg();
	ifs.seekg(0, ios::beg);

	char buffer;
	ifs.read(&buffer, 1);
	decodingKey = buffer - '0';

	ifs.read(&buffer, 1);
	fileSize -= 2;

	cout << "Input decoding filename : ";
	cin >> decodedFile;

	ofs.open(decodedFile, ios::binary);
	
	while (fileSize--)
	{
		ifs.read(&buffer, 1);
		buffer -= decodingKey;
		ofs.write(&buffer, 1);
	}
	cout << "디코딩 완료" << endl;
}

int main()
{
	EncodeFile();
	DecodeFile();

	return 0;
}

