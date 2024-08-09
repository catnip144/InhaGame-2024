#include "stringbad.h"

void callme1(StringBad&);
void callme2(StringBad);

void VGNEWS()
{
	{
		cout << "====== 내부 블록을 시작한다. ======" << endl << endl;

		StringBad headline1("Celery stalks at midnight");
		StringBad headline2("Lettuce Prey");
		StringBad sports("Spinach leaves bowl for dollars");
		cout << endl;

		cout << "headline1: " << headline1 << endl;
		cout << "headline2: " << headline2 << endl;
		cout << "sports: " << sports << endl << endl;

		callme1(headline1);
		cout << "headline1: " << headline1 << endl << endl;


		// 객체 파괴에 의한 에러 발생
		//callme2(headline2);
		//cout << "headline2: " << headline2 << endl << endl;


		cout << "하나의 객체를 다른 객체로 초기화:" << endl;
		StringBad sailor = sports;
		cout << "sailor: " << sailor << endl << endl;

		cout << "하나의 객체를 다른 객체에 대입:" << endl;
		StringBad knot;
		knot = headline1;
		cout << "knot: " << knot << endl << endl;

		cout << "====== 블록을 빠져나온다 ======" << endl;
	}
}

//int main()
//{
//
//	return 0;
//}

void callme1(StringBad& rsb)
{
	cout << "참조로 전달된 StringBad:\n";
	cout << "     \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
	cout << "값으로 전달된 StringBad:\n";
	cout << "     \"" << sb << "\"\n";
}