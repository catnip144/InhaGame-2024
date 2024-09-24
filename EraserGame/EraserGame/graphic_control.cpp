#include "game_control.h"

HWND	        g_hWnd = NULL;
HDC		        g_hdc, g_backMemDC;

RECT            rectView;
int		        screenWidth, screenHeight;

HBRUSH          hBrush, oldBrush;
HPEN            hPen, oldPen;

HBITMAP         g_backBitmap, g_hOldBitmap;

HBITMAP	        hBgImage;
BITMAP	        bitBg;

HBITMAP         hFrontImage;
BITMAP          bitFront;

vector<POINT>   uncoveredPolygon;

void SetScreenSize(RECT& rectView)
{
    screenWidth = rectView.right - rectView.left;
    screenHeight = rectView.bottom - rectView.top;
}

void CreateBitmap()
{
    // >> : Background
    hBgImage = (HBITMAP)LoadImage(NULL, TEXT(IMAGE_BG_PATH),
        IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

    if (hBgImage == NULL)
    {
        DWORD dwError = GetLastError();
        MessageBox(NULL, _T("배경 이미지 로드 에러"), _T("에러"), MB_OK);
    }
    else
        GetObject(hBgImage, sizeof(BITMAP), &bitBg);
    // << :
    // >> : Front Image
    hFrontImage = (HBITMAP)LoadImage(NULL, TEXT(IMAGE_FRONT_PATH),
        IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

    if (hFrontImage == NULL)
    {
        DWORD dwError = GetLastError();
        MessageBox(NULL, _T("Front 이미지 로드 에러"), _T("에러"), MB_OK);
    }
    else
        GetObject(hFrontImage, sizeof(BITMAP), &bitFront);
    // << :
}

void DrawBG(HDC& hdc)
{
    HDC hMemDC;
    HBITMAP hOldBitmap;
    int bx, by;

    hMemDC = CreateCompatibleDC(hdc);
    hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBgImage);
    bx = bitBg.bmWidth;
    by = bitBg.bmHeight;

    BitBlt(hdc, 0, 0, bx, by, hMemDC, 0, 0, SRCCOPY);
    StretchBlt(hdc, 0, 0, bx, by, hMemDC, 0, 0, bx, by, SRCCOPY);

    SelectObject(hMemDC, hOldBitmap);
    DeleteDC(hMemDC);
}

void DrawFrontImage(HDC& hdc)
{
    HDC hMemDC;
    HBITMAP hOldBitmap;
    int bx, by;

    hMemDC = CreateCompatibleDC(hdc);
    hOldBitmap = (HBITMAP)SelectObject(hMemDC, hFrontImage);
    bx = bitFront.bmWidth;
    by = bitFront.bmHeight;

    TransparentBlt(hdc, screenWidth / 3, screenHeight / 5, bx, by, hMemDC, 0, 0, bx, by, RGB(255, 0, 255));

    SelectObject(hMemDC, hOldBitmap);
    DeleteDC(hMemDC);
}

void DrawMap(HDC& hdc)
{
    hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
    oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

    Rectangle(
        hdc,
        player.GetRadius(),
        player.GetRadius(),
        rectView.right - player.GetRadius(),
        rectView.bottom - player.GetRadius()
    );
    SelectObject(hdc, oldBrush);
    DeleteObject(hBrush);
}

void DrawUncoveredPolygon(HDC& hdc)
{
    int count = remainingArea.size();

    hPen = (HPEN)GetStockObject(NULL_PEN);
    oldPen = (HPEN)SelectObject(hdc, hPen);

    hBrush = CreateSolidBrush(RGB(92, 150, 255));
    oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

    Polygon(hdc, uncoveredPolygon.data(), uncoveredPolygon.size());

    SelectObject(hdc, hBrush);
    SelectObject(hdc, oldPen);

    DeleteObject(hBrush);
    DeleteObject(hPen);
}