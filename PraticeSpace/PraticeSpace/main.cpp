#include <vector>
#include <string>
#include <queue>
#include <iostream>

using namespace std;


class Block
{
public:
	int totalCost;		// f(n)
	int costFromStart;	// g(n)
	int costToEnd;		// h(n)
};

class BlockCompare
{
public:
	bool operator() (Block* a, Block* b)
	{
		return a->totalCost > b->totalCost;
	}
};

int main()
{
	Block* a = new Block();
	a->totalCost = 2;

	Block* b = new Block();
	b->totalCost = 5;

	Block* c = new Block();
	c->totalCost = 1;

	Block* d = new Block();
	d->totalCost = 9;

	priority_queue<Block*, vector<Block*>, BlockCompare> openBlocks;

	openBlocks.push(a);
	openBlocks.push(b);
	openBlocks.push(c);
	openBlocks.push(d);

	while (!openBlocks.empty())
	{
		cout << openBlocks.top()->totalCost << endl;
		openBlocks.pop();
	}

}