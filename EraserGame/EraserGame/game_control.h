#pragma once

#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include "framework.h"
#include "graphic_control.h"
#include "player.h"

using namespace std;

#define TIMER_ID 1
#define TIMER_ANI 2

#define TIMER_ID_INTERVAL 45
#define TIMER_ANI_INTERVAL 140

extern vector<vector<bool>> occupied;
extern vector<POINT> remainingArea;

void CreateOccupiedGrid();
void FillOccupiedArea(vector<POINT>& path);
int GetUserInput();

///////////////////////////  graphic_control.cpp   ///////////////////////////

extern HWND		g_hWnd;
extern HDC		g_hdc, g_backMemDC;

extern RECT		rectView;
extern int		screenWidth, screenHeight;

extern HBRUSH   hBrush, oldBrush;
extern HPEN     hPen, oldPen;

extern HBITMAP  g_backBitmap, g_hOldBitmap;

extern HBITMAP	hBgImage;
extern BITMAP	bitBg;

extern HBITMAP	hFrontImage;
extern BITMAP	bitFront;

///////////////////////////  graphic_control.cpp   ///////////////////////////

///////////////////////////  player.cpp   ////////////////////////////////////

extern Player	player;
extern POINT	playerStartPos;
extern POINT	entryPos;

///////////////////////////  player.cpp   ////////////////////////////////////