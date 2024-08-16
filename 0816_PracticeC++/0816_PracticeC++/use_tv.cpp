#define _CRT_SECURE_NO_WARNINGS
#include "tv.h"

int main()
{
	Tv s42;
	cout << "42\" TV의 초기 설정값:\n";
	s42.settings();

	Remote grey;

	cout << endl;
	grey.print_mode();

	cout << endl << "리모컨 상태 변경 시도" << endl;
	s42.set_remotemode(grey);

	cout << endl << "TV 전원 ON" << endl;
	s42.onoff();

	cout << "42\" TV의 변경된 설정값:\n";
	s42.settings();

	cout << endl;
	grey.print_mode();

	cout << endl << "리모컨 상태 변경 시도" << endl;
	s42.set_remotemode(grey);

	cout << endl;
	grey.print_mode();

	return 0;
}

