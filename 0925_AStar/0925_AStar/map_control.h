#pragma once

class Block
{
private:
	POINT pos;
	int totalCost;		// f(n)
	int costFromStart;	// g(n)
	int costToEnd;		// h(n)
	Block* parent;

public:
	Block();
};

void CreateMap();
void DrawMap(HDC hdc);