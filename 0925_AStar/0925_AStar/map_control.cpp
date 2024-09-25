#include "0925_AStar.cpp"

void CreateMap()
{

}

void DrawMap(HDC hdc)
{
#define BLOCK_ROW 10
#define BLOCK_COL 20
    int offsetX = 20;
    int offsetY = 20;
    int blockWidth = (rectView.right - rectView.left - offsetX * 2) / BLOCK_COL;
    int blockHeight = (rectView.bottom - rectView.top - offsetY * 2) / BLOCK_ROW;

    for (int i = 0; i < BLOCK_ROW; i++)
    {
        for (int j = 0; j < BLOCK_COL; j++)
        {
            Rectangle(hdc, offsetX + j * blockWidth, offsetY + i * blockHeight, offsetX + j * blockWidth + blockWidth, offsetY + i * blockHeight + blockHeight);
        }
    }
}

Block::Block()
{
    pos = { 0, 0 };
    totalCost = costFromStart = costToEnd = 0;
    parent = nullptr;
}
