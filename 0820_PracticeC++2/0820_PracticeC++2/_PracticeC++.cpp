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
#include <vector>

using namespace std;

void SplitFile()
{
	string fileName;
	ifstream ifs;
	int fileSize;
	int totalFileSize;

	while (1)
	{
		cout << "Enter file name : ";
		cin >> fileName;

		ifs.open(fileName, ios_base::binary);

		if (ifs.is_open())
			break;
		else
			cout << "Invalid file name\n\n";
	}
	ifs.seekg(0, ios::end);
	totalFileSize = ifs.tellg();
	ifs.seekg(0, ios::beg);

	cout << "Enter file size : ";
	cin >> fileSize;

	int repeat = totalFileSize / fileSize;
	if (totalFileSize % fileSize) repeat++;

	for (int i = 0; i < repeat; i++)
	{
		ofstream ofs;
		string newFileName = fileName + "." + to_string(i + 1);
		ofs.open(newFileName, ios_base::binary);

		// buffer 크기 재설정 중요.
		string buffer;
		buffer.resize(fileSize);
		ifs.read(&buffer[0], fileSize);

		ofs.write(&buffer[0], ifs.gcount());
		cout << "\t-> file " << newFileName << '\n';
	}
	cout << ">> Split Done.\n";
}

void CombineFiles()
{
	cout << "Enter file number : ";
	int fileCount;
	cin >> fileCount;

	vector<string> fileNames(fileCount);
	for (int i = 0; i < fileCount; i++)
	{
		cout << "Enter source file : ";
		cin >> fileNames[i];
	}
	cout << "Enter target file : ";
	string targetFileName;
	cin >> targetFileName;

	ofstream ofs;
	ofs.open(targetFileName, ios::binary);

	for (const string& file : fileNames)
	{
		ifstream ifs;
		ifs.open(file, ios::binary);

		if (!ifs.is_open())
		{
			cout << "Failed to open file.\n";
			exit(1);
		}
		ifs.seekg(0, ios::end);
		int totalFileSize = ifs.tellg();
		ifs.seekg(0, ios::beg);

		string buffer;
		buffer.resize(totalFileSize);

		ifs.read(&buffer[0], totalFileSize);
		ofs.write(&buffer[0], ifs.gcount());
	}
	cout << ">> Combine Done.\n";
}

int main()
{
	SplitFile();
	CombineFiles();
	return 0;
}

