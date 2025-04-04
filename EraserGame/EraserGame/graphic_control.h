#pragma once
#include <vector>
using std::vector;

#define IMAGE_BG_PATH "images/background.bmp"
#define IMAGE_FRONT_PATH "images/totoro.bmp"

#define WINDOW_WIDTH 1096
#define WINDOW_HEIGHT 759

void SetScreenSize(RECT& rectView);
void CreateBitmap();

void DrawBG(HDC& hdc);
void DrawFrontImage(HDC& hdc);
void DrawMap(HDC& hdc);
void DrawUncoveredPolygon(HDC& hdc);