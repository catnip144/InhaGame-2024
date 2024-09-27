#include "framework.h"

int dx[] = { 0, 0,-1, 1,-1,-1, 1, 1 };
int dy[] = {-1, 1, 0, 0,-1, 1,-1, 1 };

bool FindPath()
{
	if (startBlock == nullptr || destBlock == nullptr)
		return false;

	priority_queue<Block*, vector<Block*>, BlockCompare> openBlocks;

	startBlock->totalCost = startBlock->costToEnd = Heuristic(
		startBlock->GetGridPos(),
		destBlock->GetGridPos()
	);
	openBlocks.push(startBlock);
	startBlock->isOpen = true;

	while (!openBlocks.empty())
	{
		Block* current = openBlocks.top();

		bool hasReachedDest = (current == destBlock);
		int curCostFromStart = current->costFromStart;
		int curcostToEnd     = current->costToEnd;
		int curTotalCost	 = current->totalCost;
		int x				 = current->col;
		int y				 = current->row;

		openBlocks.top()->isOpen = false;
		openBlocks.top()->isClosed = true;
		openBlocks.pop();

		if (hasReachedDest)
			return true;

		for (int i = 0; i < 8; i++)
		{
			int cost = i < 4 ? COST_STRAIGHT : COST_DIAGONAL;
			int nx   = x + dx[i];
			int ny	 = y + dy[i];

			if (!IsValidPosition(nx, ny))
				continue;

			Block* adjacent	= blocks[ny][nx];

			if (adjacent->state == BLOCKSTATE_WALL)
				continue;

			if (adjacent->isClosed)
				continue;

			if (adjacent->isOpen)
			{
				if (adjacent->costFromStart <= curCostFromStart + cost)
					continue;

				adjacent->costFromStart = curCostFromStart + cost;
				adjacent->totalCost = adjacent->costFromStart + adjacent->costToEnd;
				adjacent->parent = current;
			}
			else
			{
				adjacent->costFromStart = curCostFromStart + cost;
				adjacent->costToEnd = Heuristic({ nx, ny }, destBlock->GetGridPos());
				adjacent->totalCost = adjacent->costFromStart + adjacent->costToEnd;
				adjacent->parent = current;

				if (adjacent != destBlock)
					adjacent->state = BLOCKSTATE_CANDIDATE;

				adjacent->isOpen = true;
				openBlocks.push(blocks[ny][nx]);
			}
		}
	}
	return false;
}

int Heuristic(POINT pos1, POINT pos2)
{
	int dX = abs(pos1.x - pos2.x);
	int dY = abs(pos1.y - pos2.y);

	// Manhattan Distance
	return COST_STRAIGHT * (dX + dY);
}