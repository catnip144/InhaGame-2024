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

enum BlockReset
{
	BLOCKRESET_ALL,
	BLOCKRESET_EXCEPT_WALL,
	BLOCKRESET_EXCEPT_CONTEXT
};

enum DrawMode
{
	DRAWMODE_NONE,
	DRAWMODE_WALL,
	DRAWMODE_ERASER
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
	bool isOpen;
	bool isClosed;
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
extern DrawMode currentDrawMode;

void CreateMap();
void ResetBlocks(BlockReset mode);
void RegisterPathBlocks();
void DrawMap(HDC& hdc, HBRUSH& hBrush);
void SetCurrentDrawmode(POINT ptMouse, bool isDrawing);
void SetWall(POINT ptMouse);
void SetPathContext(Block* block);
bool IsValidPosition(int x, int y);
Block* GetBlock(POINT point);