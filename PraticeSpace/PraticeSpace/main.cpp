#include <vector>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

//void Test()
//{
//    HDC hMemDC = CreateCompatibleDC(hdc);
//
//    float increaseX = 3.5;
//    float increaseY = 4.0;
//
//    HBITMAP hOldBitmap = (HBITMAP)SelectObject(hMemDC, animMap[ANIMTAG_UI_PASSIVE_MAINBOX].bitmapInfo.hImg);
//    int sizePerSprite = animMap[ANIMTAG_UI_PASSIVE_MAINBOX].sizePerSprite;
//
//    int bx = animMap[ANIMTAG_UI_PASSIVE_MAINBOX].bitmapInfo.bitBg.bmWidth;
//    int by = animMap[ANIMTAG_UI_PASSIVE_MAINBOX].bitmapInfo.bitBg.bmHeight;
//    int drawX = widthPerTile * ((double)bx * increaseX / (SPRITE_SIZE * 2));
//    int drawY = heightPerTile * ((double)by * increaseY / (SPRITE_SIZE * 2));
//
//    int posX = (rectView.right) / 2 - (drawX / 2);
//    int posY = (rectView.bottom / 2) - (drawY / 2);
//    int mainBoxHeight = drawY - posY;
//
//    int xStart = 0;
//    int yStart = 0;
//
//    TransparentBlt(hdc, posX, posY, drawX, drawY, hMemDC, xStart, yStart, bx, by, RGB(255, 0, 255));
//    SelectObject(hMemDC, hOldBitmap);
//
//    posY += mainBoxHeight / 5 * 2;
//
//    for (int i = 1; i <= 3; i++)
//    {
//        hOldBitmap = (HBITMAP)SelectObject(hMemDC, animMap[ANIMTAG_UI_PASSIVE_SUBBOX].bitmapInfo.hImg);
//        sizePerSprite = animMap[ANIMTAG_UI_PASSIVE_SUBBOX].sizePerSprite;
//
//        bx = animMap[ANIMTAG_UI_PASSIVE_SUBBOX].bitmapInfo.bitBg.bmWidth;
//        by = animMap[ANIMTAG_UI_PASSIVE_SUBBOX].bitmapInfo.bitBg.bmHeight;
//        drawX = widthPerTile * ((double)bx * increaseX / (SPRITE_SIZE * 2));
//        drawY = heightPerTile * ((double)by * increaseY / (SPRITE_SIZE * 2));
//
//        posX = (rectView.right) / 2 - (drawX / 2);
//
//        xStart = 0;
//        yStart = 0;
//
//        TransparentBlt(hdc, posX, posY, drawX, drawY, hMemDC, xStart, yStart, bx, by, RGB(255, 0, 255));
//        SelectObject(hMemDC, hOldBitmap);
//
//        posY += drawY * 1.2;
//    }
//    DeleteDC(hMemDC);
//}

int main()
{

}