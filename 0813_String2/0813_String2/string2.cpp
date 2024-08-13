#include "string2.h"

// static 클래스 멤버를 초기화한다.
int String::num_strings = 0;

// static 메서드
int String::HowMany()
{
	return num_strings;
}

// 클래스 메서드
String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::String(const String& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

String::~String()
{
	--num_strings;
	delete[] str;
}

int String::has(char charType)
{
	int count = 0;
	for (int i = 0; i < len; i++)
		count += (str[i] == charType);

	return count;
}

void String::stringup()
{
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= CASEDIFF;
	}
}

void String::stringlow()
{
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += CASEDIFF;
	}
}

// 오버로드 연산자 메서드
String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;

	delete[] str;

	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);

	return *this;
}

// C 스타일의 문자열을 String에 대입한다
String& String::operator=(const char* s)
{
	delete[] str;

	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);

	return *this;
}

// const가 아닌 String에 읽기-쓰기 개별 문자 접근
char& String::operator[](int i)
{
	return str[i];
}

// const String에 읽기 전용 개별 문자 접근
const char& String::operator[](int i) const
{
	return str[i];
}

// 오버로드 연산자 프렌드

bool operator<(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2)
{
	return st1 > st2;
}

bool operator==(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

String operator+(const String& st1, const String& st2)
{
	char newString[String::CINLIM];

	for (int i = 0; i < st1.len; i++)
		newString[i] = st1.str[i];

	for (int i = 0; i < st2.len; i++)
		newString[i + st1.len] = st2.str[i];

	newString[st1.len + st2.len] = '\0';
	return String(newString);
}

ostream& operator<<(ostream& os, const String& st)
{
	os << st.str;
	return os;
}

istream& operator>>(istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);

	if (is)
		st = temp;

	while (is && is.get() != '\n')
		continue;

	return is;
}