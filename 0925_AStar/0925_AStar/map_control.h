#pragma once

#define BLOCK_ROW 10
#define BLOCK_COL 20

using namespace std;

enum BlockState
{
	BLOCKSTATE_DEFAULT,
	BLOCKSTATE_START,
	BLOCKSTATE_DEST
};

class Block
{
private:
	RECT rect;

public:
	int totalCost;		// f(n)
	int costFromStart;	// g(n)
	int costToEnd;		// h(n)
	int row, col;
	Block* parent;
	BlockState state;

	Block(RECT rect);
	void Draw(HDC& hdc, HBRUSH& hBrush);
	bool IsWithinBlock(POINT point);
	POINT GetGridPos();
	POINT GetCenter();
};

extern RECT rectView;
extern Block *startBlock, *destBlock;
extern vector<vector<Block*>> blocks;
extern vector<Block*> closedBlocks;
extern priority_queue<Block*> openBlocks;

void CreateMap();
void DrawMap(HDC& hdc, HBRUSH& hBrush);
bool IsValidPosition(int x, int y);
Block* GetBlock(POINT point);