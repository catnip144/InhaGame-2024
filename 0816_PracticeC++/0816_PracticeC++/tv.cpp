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
		cout << "볼륨 = " << volume << endl;
		cout << "채널 = " << channel << endl;
		cout << "모드 = "
		 	 << (mode == Antenna ? "지상파 방송" : "케이블 방송") << endl;
		cout << "입력 = " << (input == TV ? "TV" : "DVD") << endl;
	}
}

void Tv::set_remotemode(Remote& r)
{
	if (!ison())
	{
		cout << "현재 TV가 꺼져있습니다." << endl;
		return;
	}
	r.set_remotemode();
}

void Remote::print_mode()
{
	cout << "현재 리모컨 모드: " << (remoteMode == Normal ? "Normal" : "Communication") << endl;
}
