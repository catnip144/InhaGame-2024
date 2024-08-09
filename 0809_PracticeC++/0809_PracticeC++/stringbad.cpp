#include "stringbad.h"

int StringBad::num_strings = 0;

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++");
	++num_strings;

	cout << num_strings << ": \"" << str << "\" ����Ʈ ��ü ����" << endl;
}

StringBad::StringBad(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	++num_strings;

	cout << num_strings << ": \"" << str << "\" ��ü ����" << endl;
}

StringBad::StringBad(const StringBad& sb)
{
	// Deep Copy

	len = std::strlen(sb.str);
	str = new char[len + 1];
	std::strcpy(str, sb.str);
	++num_strings;

	cout << num_strings << ": \"" << str << "\" ���� ��ü ����" << endl;
}

StringBad::~StringBad()
{
	cout <<"\"" << str << "\" ��ü�ı�" << endl;
	--num_strings;

	cout << "���� ��ü ��: " << num_strings << endl;
	delete[] str;
}

StringBad& StringBad::operator=(const StringBad& st)
{
	if (this == &st)
		return *this;

	delete[] str;

	len = std::strlen(st.str);
	str = new char[len + 1];
	std::strcpy(str, st.str);

	cout << num_strings << ": \"" << str << "\" ��ü ���� ����" << endl;
	return* this;
}

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
}
