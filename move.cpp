#include "move.hpp"
Position getPossibleMovePosition(Position p, Direction d, bool& success)
{
	Field <char> * f = getWallField();
//	Field <Entity*> ef = getEntityField();
	int x = p.getX();
	int y = p.getY();
	
	if (x < 0 || y < 0 || x >= f->getW() || y >= f->getH())
	{
		success = false;
		return p;
	}
	
	switch (d)
	{
		case DIR_UP:
			if (y >= 1 && f->getAt(p) == '=')
			{
				success = true;
				Position np(x, y - 1);
				return np;
			}
			else
			{
				success = false;
				return p;
			}
			break;
		case DIR_DOWN:
			if (y < f->getH() - 1 && f->getAt(p) == '=')
			{
				success = true;
				Position np(x, y + 1);
				return np;
			}
			else
			{
				success = false;
				return p;
			}
			break;
		case DIR_RIGHT:
			{	// FIXES jump to case label. TODO: fix this shit
			if (x > f->getW() - 1)
			{
				success = false;
				return p;
			}
			Position np(x + 1, y);
			if (f->getAt(np) == '#') // TODO: entities
			{
				 // TODO: more complex check
				 success = true;
				 return np;
			}
			else
			{
				success = false;
				return p;
			}
			break;
			}
		case DIR_LEFT:
			if (x <= 0)
			{
				success = false;
				return p;
			}
			Position np(x - 1, y);
			if (f->getAt(np) == '#') // TODO: entities
			{
				 // TODO: more complex check
				 success = true;
				 return np;
			}
			else
			{
				success = false;
				return p;
			}
			break;
	}
	
	success = false;
	return p;
}
