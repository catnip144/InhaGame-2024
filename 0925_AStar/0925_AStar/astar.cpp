#include "framework.h"

vector<POINT> path;

int dx[] = { 0, 0,-1, 1,-1,-1, 1, 1 };
int dy[] = {-1, 1, 0, 0,-1, 1,-1, 1 };

vector<POINT> FindPath()
{
	if (startBlock == nullptr || destBlock == nullptr)
		return vector<POINT>();

	startBlock->totalCost = startBlock->costToEnd = ManhattanDistance(
		startBlock->GetGridPos(),
		destBlock->GetGridPos()
	);
	openBlocks.push(startBlock);

	while (!openBlocks.empty())
	{
		Block* current = openBlocks.top();

		int curCostFromStart = current->costFromStart;
		int curcostToEnd     = current->costToEnd;
		int curTotalCost	 = current->totalCost;
		int x				 = current->col;
		int y				 = current->row;

		closedBlocks.push_back(openBlocks.top());
		openBlocks.pop();

		for (int i = 0; i < 8; i++)
		{
			int cost = i < 4 ? COST_STRAIGHT : COST_DIAGONAL;
			int nx   = x + dx[i];
			int ny	 = y + dy[i];

			if (!IsValidPosition(nx, ny))
				continue;

			// check wall
				//continue;

			Block* adjacent			= blocks[ny][nx];

			// if adjacent exists in openBlocks
				// compare cost, update parent

			adjacent->costFromStart = curCostFromStart + cost;
			adjacent->costToEnd		= ManhattanDistance({ nx, ny }, destBlock->GetGridPos());
			adjacent->totalCost		= adjacent->costFromStart + adjacent->costToEnd;
			adjacent->parent		= current;

			openBlocks.push(blocks[ny][nx]);
		}
	}

	return vector<POINT>();
}

int ManhattanDistance(POINT pos1, POINT pos2)
{
	return abs(pos1.x - pos2.x) + abs(pos1.y - pos2.y);
}