#include "framework.h"

RECT rectView;
Block* startBlock = nullptr;
Block* destBlock = nullptr;
vector<vector<Block*>> blocks;
vector<vector<bool>> visited;

void CreateMap()
{
    int offsetX = 20;
    int offsetY = 20;
    int blockWidth = (rectView.right - rectView.left - offsetX * 2) / BLOCK_COL;
    int blockHeight = (rectView.bottom - rectView.top - offsetY * 2) / BLOCK_ROW;

    blocks = vector<vector<Block*>>
        (BLOCK_ROW, vector<Block*>(BLOCK_COL));

    visited = vector<vector<bool>>
        (BLOCK_ROW, vector<bool>(BLOCK_COL));

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

void ResetBlocks(bool excludeStartDest)
{
    for (int i = 0; i < BLOCK_ROW; i++)
    {
        for (int j = 0; j < BLOCK_COL; j++)
        {
            blocks[i][j]->costFromStart = 0;
            blocks[i][j]->costToEnd = 0;
            blocks[i][j]->totalCost = 0;
            blocks[i][j]->parent = nullptr;
            blocks[i][j]->state = BLOCKSTATE_DEFAULT;

            visited[i][j] = false;
        }
    }
    if (excludeStartDest)
    {
        if (startBlock) startBlock->state = BLOCKSTATE_START;
        if (destBlock) destBlock->state = BLOCKSTATE_DEST;
        return;
    }
    startBlock = nullptr;
    destBlock = nullptr;
}

void RegisterPathBlocks()
{
    Block* current = destBlock;
    while (current)
    {
        if (current->state != BLOCKSTATE_START && current->state != BLOCKSTATE_DEST)
            current->state = BLOCKSTATE_PATH;
        current = current->parent;
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
    return (x >= 0 && x < BLOCK_COL && y >= 0 && y < BLOCK_ROW);
}

void CreateWall(Block* block)
{
    block->state = (block->state == BLOCKSTATE_WALL) ? BLOCKSTATE_DEFAULT : BLOCKSTATE_WALL;
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
    row = col = 0;
    parent = nullptr;
    this->rect = rect;
    state = BLOCKSTATE_DEFAULT;
    totalCost = costFromStart = costToEnd = 0;
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

    case BLOCKSTATE_CANDIDATE:
        hBrush = CreateSolidBrush(RGB(209, 206, 197));
        break;

    case BLOCKSTATE_PATH:
        hBrush = CreateSolidBrush(RGB(3, 252, 207));
        break;

    case BLOCKSTATE_WALL:
        hBrush = CreateSolidBrush(RGB(0, 0, 0));
        break;

    default:
        hBrush = CreateSolidBrush(RGB(247, 240, 234));
        break;
    }
    HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
    SelectObject(hdc, oldBrush);
	DeleteObject(hBrush);

    if (state == BLOCKSTATE_WALL)
        return;

    SetBkMode(hdc, TRANSPARENT);
    TCHAR str[10];

    swprintf(str, 10, L"%d", costFromStart);
    TextOut(hdc, rect.left + 8, rect.top + 3, str, lstrlen(str));

    swprintf(str, 10, L"%d", costToEnd);
    TextOut(hdc, rect.right - 25, rect.top + 3, str, lstrlen(str));

    swprintf(str, 10, L"%d", totalCost);
    TextOut(hdc, rect.left + 8, rect.bottom - 18, str, lstrlen(str));
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
    return { col, row };
}

POINT Block::GetCenter()
{
    int x = rect.left + (rect.right - rect.left) / 2;
    int y = rect.top + (rect.bottom - rect.top) / 2;
    return { x, y };
}