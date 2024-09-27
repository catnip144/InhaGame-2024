#include "framework.h"

HBITMAP hImage_Guide;
BITMAP bit_Guide;

void CreateBitmap()
{
    // Guide  /////////////////////////////////////////////////////////////
    hImage_Guide = (HBITMAP)LoadImage(NULL, TEXT(GUIDE_IMAGE_PATH),
        IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

    if (hImage_Guide == NULL)
    {
        DWORD dwError = GetLastError();
        MessageBox(NULL, _T("ani 이미지 로드 에러"), _T("에러"), MB_OK);
    }
    else
        GetObject(hImage_Guide, sizeof(BITMAP), &bit_Guide);
    //////////////////////////////////////////////////////////////////////
}