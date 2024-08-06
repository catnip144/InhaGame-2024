/*
	Q3.	p706 6번
		M1(0, 0), M2(5, 5)
		M1 + M2 -> M1.showmove();
*/
#include "move.h"

int main()
{
	Move M1 = Move(2, 3);
	Move M2 = Move(5, 5);
	Move M3 = M1.add(M2);

	M1.showmove();
	M2.showmove();
	M3.showmove();

	M3.reset(1, 6);
	M3.showmove();

	return 0;
}

