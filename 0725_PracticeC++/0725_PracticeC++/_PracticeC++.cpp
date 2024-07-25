/*

*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

void menu();
void lobby();
void (*update)(void);

void main()
{
	update = menu;
	while (1)
		update();

}

void menu()
{
	update = menu;
}

void lobby()
{
	update = lobby;
}
