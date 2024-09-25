#include "framework.h"

RECT rectView;
Block* startBlock = nullptr;
Block* destBlock = nullptr;
vector<vector<Block*>> blocks;
vector<Block*> closedBlocks;
priority_queue<Block*> openBlocks;

void CreateMap()
{
    int offsetX = 20;
    int offsetY = 20;
    int blockWidth = (rectView.right - rectView.left - offsetX * 2) / BLOCK_COL;
    int blockHeight = (rectView.bottom - rectView.top - offsetY * 2) / BLOCK_ROW;

    blocks = vector<vector<Block*>>
        (BLOCK_ROW, vector<Block*>(BLOCK_COL));

    for (int i = 0; i < BLOCK_ROW; i++)
    {
        for (int j = 0; j < BLOCK_COL; j++)
        {
            Block* newBlock = new Block({
                offsetX + j * blockWidth,
                offsetY + i * blockHeight,
                offsetX + j * blockWidth + blockWidth,
                offsetY + i * blockHeight + blockHeight
            });
            newBlock->row = i;
            newBlock->col = j;
            blocks[i][j] = newBlock;
        }
    }
}

void DrawMap(HDC& hdc, HBRUSH& hBrush)
{
    for (int i = 0; i < BLOCK_ROW; i++)
    {
        for (int j = 0; j < BLOCK_COL; j++)
            blocks[i][j]->Draw(hdc, hBrush);
    }
}

bool IsValidPosition(int x, int y)
{
    return (x >= 0 && x <= BLOCK_COL && y >= 0 && y <= BLOCK_ROW);
}

Block* GetBlock(POINT point)
{
    for (int i = 0; i < BLOCK_ROW; i++)
    {
        for (int j = 0; j < BLOCK_COL; j++)
        {
            if (blocks[i][j]->IsWithinBlock(point))
                return blocks[i][j];
        }
    }
    return nullptr;
}

Block::Block(RECT rect)
{
    this->rect = rect;
    totalCost = costFromStart = costToEnd = 0;
    parent = nullptr;
    state = BLOCKSTATE_DEFAULT;
}

void Block::Draw(HDC& hdc, HBRUSH& hBrush)
{
    switch (state)
    {
    case BLOCKSTATE_START:
        hBrush = CreateSolidBrush(RGB(62, 180, 137));
        break;

    case BLOCKSTATE_DEST:
        hBrush = CreateSolidBrush(RGB(195, 75, 75));
        break;

    default:
        hBrush = CreateSolidBrush(RGB(247, 240, 234));
        break;
    }
    HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
    SelectObject(hdc, oldBrush);

    SetBkMode(hdc, TRANSPARENT);
    TCHAR str[10];

    swprintf(str, 10, L"%d", costFromStart);
    TextOut(hdc, rect.left + 10, rect.top + 3, str, lstrlen(str));

    swprintf(str, 10, L"%d", costToEnd);
    TextOut(hdc, rect.right - 16, rect.top + 3, str, lstrlen(str));

    swprintf(str, 10, L"%d", totalCost);
    TextOut(hdc, rect.left + 10, rect.bottom - 18, str, lstrlen(str));

	DeleteObject(hBrush);
}

bool Block::IsWithinBlock(POINT point)
{
    if (point.x < rect.left || point.x > rect.right)
        return false;

    if (point.y < rect.top || point.y > rect.bottom)
        return false;

    return true;
}

POINT Block::GetGridPos()
{
    return { row, col };
}

POINT Block::GetCenter()
{
    int x = rect.left + (rect.right - rect.left) / 2;
    int y = rect.top + (rect.bottom - rect.top) / 2;
    return { x, y };
}
