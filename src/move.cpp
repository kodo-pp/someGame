#include "move.hpp"
#include <iostream>

using namespace std;

Position getPossibleMovePosition(Position p, Direction d, bool& success)
{
	Field <char> * f = getWallField();
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
			if (y >= 1 && f->getAt(p) == '=' && f->getAt(Position(p.getX(), p.getY() - 1)) == '=')
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
		
			if (y < f->getH() - 1 && f->getAt(p) == '=' && f->getAt(Position(p.getX(), p.getY() + 1)) == '=')
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
			{	// Нужно для предотвращения ошибки jump to case label. TODO: fix this shit
				if (x >= f->getW() - 1)
				{
					success = false;
					return p;
				}
				Position np(x + 1, y);
				if (f->getAt(np) != '#') // TODO: столкновения с игровыми объектами
				{
					success = true;
					
					for (int fallY = y; fallY < f->getH(); ++fallY)
					{
						np.setY(fallY);
						if (f->getAt(np) != ' ')
						{
							np.setY(max(fallY - 1, y));
							break;
						}
					}
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
			if (f->getAt(np) != '#') // TODO: столкновения с игровыми объектами
			{
				success = true;
				 
				for (int fallY = y; fallY < f->getH(); ++fallY)
				{
					np.setY(fallY);
					if (f->getAt(np) != ' ')
					{
						np.setY(max(fallY - 1, y));
						break;
					}
				}
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
