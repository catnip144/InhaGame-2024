#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

#define FILE_PATH "../data/BopMembers.txt"

using namespace std;
/*
Q3. c++ 기초 플러스 p368 4번
+a. 회원등록 -> 파일 저장
b. 실명으로 열람
...
e. 회원이 지정한 것으로 열람
q. 종료

*/
struct bop {
	string fullname;
	string title;
	string bopname;
	int preference;
};

enum BopId
{
	BOP_FULLNAME,
	BOP_TITLE,
	BOP_NAME,
	BOP_PREFERENCE
};

void InitMembers(vector<bop>& members);
void AddMember(vector<bop>& members);
void PrintMenu();
void PrintMembers(vector<bop>& bopList, BopId id);

void main()
{
	vector<bop> members;
	char option;

	InitMembers(members);

	while (1)
	{
		PrintMenu();
		cin >> option;
		getchar();
		
		switch (option)
		{
		case 'a':
			AddMember(members);
			break;

		case 'b':
			PrintMembers(members, BOP_FULLNAME);
			break;

		case 'c':
			PrintMembers(members, BOP_TITLE);
			break;

		case 'd':
			PrintMembers(members, BOP_NAME);
			break;

		case 'e':
			PrintMembers(members, BOP_PREFERENCE);
			break;

		default:
			cout << "종료합니다.";
			return;
		}
	}
}

void InitMembers(vector<bop>& members)
{
	ifstream infile;
	infile.open(FILE_PATH);
	if (!infile.is_open()) return;

	string line;
	while (getline(infile, line))
	{
		string buffer;
		stringstream ss(line);
		vector<string> bopInfo;

		while (getline(ss, buffer, ','))
		{
			bopInfo.push_back(buffer);
		}
		if (bopInfo.size() != 4)
		{
			cout << "File format error";
			return;
		}
		bop member;
		member.fullname = bopInfo[0];
		member.title = bopInfo[1];
		member.bopname = bopInfo[2];
		member.preference = stoi(bopInfo[3]);

		members.push_back(member);
	}
	infile.close();
}

void AddMember(vector<bop>& members)
{
	string fullname, title, bopname;
	int preference;

	cout << "\n회원 이름: ";
	getline(cin, fullname);

	cout << "회원 직함: ";
	getline(cin, title);

	cout << "BOP 아이디: ";
	getline(cin, bopname);

	cout << "지정 방식 (0 = fullname, 1 = title, 2 = bopname): ";
	cin >> preference;
	getchar();

	bop newMember;
	newMember.fullname = fullname;
	newMember.title = title;
	newMember.bopname = bopname;
	newMember.preference = preference;

	members.push_back(newMember);

	ofstream outfile(FILE_PATH, ios::app);
	if (!outfile.is_open()) return;

	outfile << fullname << ',' << title << ',' << bopname << ',' << preference << '\n';
	outfile.close();
}

void PrintMenu()
{
	cout << "\n==== Benevolent Order of Programmers ====\n\n"
		<< "a. 회원 등록                  b. 실명으로 열람" << '\n'
		<< "c. 직함으로 열람              d. BOP 아이디로 열람" << '\n'
		<< "e. 회원이 지정한 것으로 열람  q. 종료" << '\n'
		<< "원하는 것을 선택하십시오: ";
}

void PrintMembers(vector<bop>& bopList, BopId id)
{
	cout << '\n';
	for (const auto& member : bopList)
	{
		BopId idType = (id == BOP_PREFERENCE) ? BopId(member.preference) : id;

		switch (idType)
		{
		case BOP_FULLNAME:
			cout << member.fullname << '\n';
			break;

		case BOP_TITLE:
			cout << member.title << '\n';
			break;

		case BOP_NAME:
			cout << member.bopname << '\n';
			break;
		}
	}
}