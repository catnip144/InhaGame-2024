#include "framework.h"

Guide guide({ 50, 50 });
double deltaTime = 0;
DWORD previousTime = GetTickCount64();

Guide::Guide(POINT pos)
{
	this->pos = pos;
    dir = DIR_D;
    curFrame = 0;
    pathIndex = 0;
    speed = GUIDE_SPEED;
    isMoving = false;
}

void Guide::Draw(HDC hdc)
{
    HDC hMemDC = CreateCompatibleDC(hdc);
    HBITMAP hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage_Guide);

    int bx = SPRITE_SIZE_X;
    int by = SPRITE_SIZE_Y;
    int spriteCount = SPRITE_COUNT;

    int xStart = (spriteCount * dir + curFrame) * bx;
    int yStart = 0;

    TransparentBlt(hdc, pos.x - GUIDE_OFFSET_X, pos.y - GUIDE_OFFSET_Y, bx * SPRITE_SCALE, by * SPRITE_SCALE, hMemDC, xStart, yStart, bx, by, RGB(255, 0, 255));

    SelectObject(hMemDC, hOldBitmap);
    DeleteDC(hMemDC);
}

void Guide::UpdateFrame()
{
    curFrame = (curFrame + 1) % SPRITE_COUNT;
}

void Guide::SetFacingDir(int dx, int dy)
{
    if (dx == 0 && dy > 0)
        dir = DIR_D;

    else if (dx == 0 && dy < 0)
        dir = DIR_U;

    else if (dx > 0 && dy == 0)
        dir = DIR_R;

    else if (dx < 0 && dy == 0)
        dir = DIR_L;

    else if (dx > 0 && dy > 0)
        dir = DIR_RD;

    else if (dx > 0 && dy < 0)
        dir = DIR_RU;

    else if (dx < 0 && dy > 0)
        dir = DIR_LD;

    else if (dx < 0 && dy < 0)
        dir = DIR_LU;
}

void Guide::SetEnabled(bool isEnabled)
{
    if (isEnabled && !path.empty())
    {
        isMoving = true;
        pathIndex = path.size() - 1;
        guide.Move(path.back());
    }
    else
        isMoving = false;
}

void Guide::Move(POINT pos)
{
    this->pos = pos;
}

void Guide::MoveAlongPath(vector<POINT>& inputPath)
{
    if (!isMoving || path.empty())
        return;

    int dx = inputPath[pathIndex].x - pos.x;
    int dy = inputPath[pathIndex].y - pos.y;

    if (dx + dy == 0)
    {
        pos.x = inputPath[pathIndex].x;
        pos.y = inputPath[pathIndex].y;
        --pathIndex;

        if (pathIndex == -1)
        {
            isMoving = false;
            return;
        }
        dx = inputPath[pathIndex].x - pos.x;
        dy = inputPath[pathIndex].y - pos.y;
        SetFacingDir(dx, dy);
        return;
    }
    int moveX = dx != 0 ? dx / abs(dx) * speed : 0;
    int moveY = dy != 0 ? dy / abs(dy) * speed : 0;
    int nx = pos.x + moveX;
    int ny = pos.y + moveY;

    if (abs(moveX) > abs(dx))
        nx = inputPath[pathIndex].x;

    if (abs(moveY) > abs(dy))
        ny = inputPath[pathIndex].y;

    Move({ nx, ny });
}
