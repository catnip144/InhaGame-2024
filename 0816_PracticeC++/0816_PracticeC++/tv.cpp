#include <iostream>
#include "tv.h"

bool Tv::volup()
{
	if (volume < MaxVal)
	{
		volume++;
		return true;
	}
	else
		return false;
}

bool Tv::voldown()
{
	if (volume > MinVal)
	{
		volume--;
		return true;
	}
	else
		return false;
}

void Tv::chanup()
{
	if (channel < maxchannel)
		channel++;
	else
		channel = 1;
}

void Tv::chandown()
{
	if (channel > 1)
		channel--;
	else
		channel = maxchannel;
}

void Tv::settings() const
{
	using std::cout;
	using std::endl;

	cout << "TV = " << (state == Off ? "OFF" : "ON") << endl;
	if (state == On)
	{
		cout << "���� = " << volume << endl;
		cout << "ä�� = " << channel << endl;
		cout << "��� = "
		 	 << (mode == Antenna ? "������ ���" : "���̺� ���") << endl;
		cout << "�Է� = " << (input == TV ? "TV" : "DVD") << endl;
	}
}

void Tv::set_remotemode(Remote& r)
{
	if (!ison())
	{
		cout << "���� TV�� �����ֽ��ϴ�." << endl;
		return;
	}
	r.set_remotemode();
}

void Remote::print_mode()
{
	cout << "���� ������ ���: " << (remoteMode == Normal ? "Normal" : "Communication") << endl;
}
