#pragma once
#include <vector>
using std::vector;

#define IMAGE_BG_PATH "images/background.bmp"
#define IMAGE_FRONT_PATH "images/totoro.bmp"

#define WINDOW_WIDTH 1100
#define WINDOW_HEIGHT 760

extern RECT		rectView;
extern int		screenWidth, screenHeight;

extern HBRUSH   hBrush, oldBrush;
extern HPEN     hPen, oldPen;

extern HBITMAP  g_backBitmap, g_hOldBitmap;

extern HBITMAP	hBgImage;
extern BITMAP	bitBg;

extern HBITMAP	hFrontImage;
extern BITMAP	bitFront;

void SetScreenSize(RECT& rectView);
void CreateBitmap();

void DrawBG(HDC& hdc);
void DrawFrontImage(HDC& hdc);
void DrawCoverImage(HDC& hdc);

class MaskPolygon
{
private:
	POINT* points;
	int count = 0;

public:
	void Init(vector<POINT>& path);
	void Draw(HDC& hdc);
};