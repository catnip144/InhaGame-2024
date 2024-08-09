#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>

using std::cout;
using std::endl;

class StringBad
{
private:
	char* str;
	int len;
	static int num_strings;

public:
	StringBad();
	StringBad(const char* s);
	StringBad(const StringBad& sb);
	~StringBad();

	StringBad& operator=(const StringBad& st);
	friend std::ostream& operator<<(std::ostream& os, const StringBad& st);
};
