#include "move.h"

Move::Move(double a, double  b)
{
	x = a;
	y = b;
}

void Move::showmove() const
{
	cout << "���� x : " << x << endl;
	cout << "���� y : " << y << endl;
	cout << endl;
}

Move Move::add(const Move& m) const
{
	Move newMove(this->x + m.x, this->y + m.y);
	return newMove;
}

void Move::reset(double a, double b)
{
	x = a;
	y = b;
}