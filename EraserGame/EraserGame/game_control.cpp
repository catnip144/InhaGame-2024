#include "game_control.h"

HDC		hdc;
RECT    rectView;
int		screenWidth, screenHeight;

HBITMAP	hBgImage;
BITMAP	bitBg;

void SetScreenSize(RECT& rectView, int screenWidth, int screenHeight)
{
	screenWidth = rectView.right - rectView.left;
	screenHeight = rectView.bottom - rectView.top;
}
