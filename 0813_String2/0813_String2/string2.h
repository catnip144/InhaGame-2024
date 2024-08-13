#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
	static const int CASEDIFF = 'a' - 'A';

public:
	// 생성자와 기타 메서드
	String(const char* s);
	String();
	String(const String& st);
	~String();
	int length() const { return len; }
	int has(char charType);
	void stringup();
	void stringlow();

	// 오버로딩 연산자 메서드
	String& operator=(const String& st);
	String& operator=(const char* s);
	char& operator[](int i);
	const char& operator[](int i) const;

	// 오버로딩 연산자 프렌드
	friend bool operator<(const String& st1, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st1, const String& st2);

	friend String operator+(const String& st1, const String& st2);

	friend ostream& operator<<(ostream& os, const String& st);
	friend istream& operator>>(istream& is, String& st);

	// static 함수
	static int HowMany();
};