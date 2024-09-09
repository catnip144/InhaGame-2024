#pragma once
#include "framework.h"
#include "map_control.h"

#define TIMER_ID 1
#define TIMER_ANI 2

#define TIMER_ID_INTERVAL 1
#define TIMER_ANI_INTERVAL 140


extern HDC		hdc;
extern RECT		rectView;
extern int		screenWidth, screenHeight;

extern HBITMAP	hBgImage;
extern BITMAP	bitBg;

void SetScreenSize(RECT& rectView, int screenWidth, int screenHeight);
