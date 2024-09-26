#pragma once

#define BLOCK_ROW 10
#define BLOCK_COL 20

using namespace std;

enum BlockState
{
	BLOCKSTATE_DEFAULT,
	BLOCKSTATE_START,
	BLOCKSTATE_DEST,
	BLOCKSTATE_CANDIDATE,
	BLOCKSTATE_PATH,
	BLOCKSTATE_WALL
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

class BlockCompare
{
public:
	bool operator() (Block* a, Block* b)
	{
		return a->totalCost > b->totalCost;
	}
};

extern RECT rectView;
extern Block *startBlock, *destBlock;
extern vector<vector<Block*>> blocks;
extern vector<vector<bool>> visited;

void CreateMap();
void ResetBlocks(bool excludeStartDest = false);
void RegisterPathBlocks();
void DrawMap(HDC& hdc, HBRUSH& hBrush);
void CreateWall(Block* block);
bool IsValidPosition(int x, int y);
Block* GetBlock(POINT point);