#include "game_control.h"

RECT    rectView;
int		screenWidth, screenHeight;

HBRUSH  hBrush, oldBrush;
HPEN    hPen, oldPen;

HBITMAP g_backBitmap, g_hOldBitmap;

HBITMAP	hBgImage;
BITMAP	bitBg;

HBITMAP hFrontImage;
BITMAP bitFront;

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

void DrawCoverImage(HDC& hdc)
{

}

void MaskPolygon::Init(vector<POINT>& path)
{
    count = path.size();
    points = new POINT[count];

    for (int i = 0; i < count; i++)
        points[i] = path[i];
}

void MaskPolygon::Draw(HDC& hdc)
{
    hPen = (HPEN)GetStockObject(NULL_PEN);
    oldPen = (HPEN)SelectObject(hdc, hPen);
    
    hBrush = CreateSolidBrush(RGB(92, 150, 255));
    oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

    Polygon(hdc, points, count);

    SelectObject(hdc, hBrush);
    SelectObject(hdc, oldPen);

    DeleteObject(hBrush);
    DeleteObject(hPen);
}
