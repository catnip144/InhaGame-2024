#include "framework.h"

int dx[] = { 0, 0,-1, 1,-1,-1, 1, 1 };
int dy[] = {-1, 1, 0, 0,-1, 1,-1, 1 };

bool FindPath()
{
	if (startBlock == nullptr || destBlock == nullptr)
		return false;

	vector<Block*> closedBlocks;
	priority_queue<Block*, vector<Block*>, BlockCompare> openBlocks;

	startBlock->totalCost = startBlock->costToEnd = Heuristic(
		startBlock->GetGridPos(),
		destBlock->GetGridPos()
	);
	openBlocks.push(startBlock);
	visited[startBlock->row][startBlock->col] = true;

	while (!openBlocks.empty())
	{
		Block* current = openBlocks.top();

		bool hasReachedDest = (current == destBlock);
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

			Block* adjacent	= blocks[ny][nx];

			if (visited[ny][nx])
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

				visited[ny][nx] = true;
				openBlocks.push(blocks[ny][nx]);
			}
		}
		if (hasReachedDest)
			return true;
	}
	return false;
}

int Heuristic(POINT pos1, POINT pos2)
{
	int dX = abs(pos1.x - pos2.x);
	int dY = abs(pos1.y - pos2.y);

	// Octile Distance - Grid based movements
	return COST_STRAIGHT * (dX + dY) + (COST_DIAGONAL - 2 * COST_STRAIGHT) * min(dX, dY);
}