#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <list>

using namespace std;

template<class T>
class TooBig
{
private:
	T cutoff;

public:
	TooBig(const T& t) : cutoff(t) {}
	bool operator() (const T& v) { return v > cutoff; }
};

void outint(int n) { std::cout << n << " "; }
void Show(int);
char toLower(char ch) { return tolower(ch); }
string& ToLower(string& st);
void display(const string& s);

const int LIM = 10;

int main()
{
// C++11 은 다음의 코드를 대신 사용할 수 있다.
// list<int> yadayada = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
// list<int> etcetera = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };

	//TooBig<int> f100(100);
	//int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
	//list<int> yadayada(vals, vals + 10);
	//list<int> etcetera(vals, vals + 10);

	//cout << "원래의 리스트:\n";
	//for_each(yadayada.begin(), yadayada.end(), outint);
	//cout << endl;

	//for_each(etcetera.begin(), etcetera.end(), outint);
	//cout << endl;

	//yadayada.remove_if(f100);
	//etcetera.remove_if(TooBig<int>(200));
	//cout << "정비된 리스트:\n";

	//for_each(yadayada.begin(), yadayada.end(), outint);
	//cout << endl;

	//for_each(etcetera.begin(), etcetera.end(), outint);
	//cout << endl;

	////////////////////////////////////////////////////////////////////////////////////

	//int ar[LIM] = { 4, 5, 4, 2, 2, 3, 4, 8, 1, 4 };
	//list<int> la(ar, ar + LIM);
	//list<int> lb(la);

	//cout << "오리지널 리스트의 내용:\n\t";
	//for_each(la.begin(), la.end(), Show);
	//cout << endl;

	//la.remove(4);
	//cout << "remove() 메서드를 사용한 후:\n";
	//cout << "la:\t";

	//for_each(la.begin(), lb.end(), Show);
	//cout << endl;

	//list<int>::iterator last;
	//last = remove(lb.begin(), lb.end(), 4);

	//cout << "remove() 함수를 사용한 후:\n";
	//cout << "lb:\t";

	//for_each(lb.begin(), lb.end(), Show);
	//cout << endl;

	//lb.erase(last, lb.end());
	//cout << "erase() 메서드를 사용한 후:\n";
	//cout << "lb:\t";

	//for_each(lb.begin(), lb.end(), Show);
	//cout << endl;

	////////////////////////////////////////////////////////////////////////////////////

	vector<string> words;
	cout << "단어들을 입력하십시오 (끝내려면 quit): \n";

	string input;
	while (cin >> input && input != "quit")
		words.push_back(input);

	cout << "다음과 같은 단어들을 입력하셨습니다.\n";
	for_each(words.begin(), words.end(), display);
	cout << endl;

	// 단어들을 소문자로 변환하여 집합에 넣는다.
	set<string> wordset;
	transform(words.begin(), words.end(), insert_iterator<set<string>>(wordset, wordset.begin()), ToLower);

	cout << "\n단어들의 알파벳순 리스트:\n";
	for_each(wordset.begin(), wordset.end(), display);
	cout << endl;

	// 단어와 빈도를 맵에 넣는다.
	map<string, int> wordmap;

	set<string>::iterator si;
	for (si = wordset.begin(); si != wordset.end(); si++)
		wordmap[*si] = count(words.begin(), words.end(), *si);

	// 맵의 내용을 출력한다.
	cout << "\n단어별 빈도:\n";
	for (si = wordset.begin(); si != wordset.end(); si++)
		cout << *si << ": " << wordmap[*si] << endl;

	return 0;
}

void Show(int v)
{
	cout << v << ' ';
}

string& ToLower(string& st)
{
	transform(st.begin(), st.end(), st.begin(), toLower);
	return st;
}

void display(const string& s)
{
	cout << s << " ";
}