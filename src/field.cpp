#include "field.hpp"

// TODO: Field::, move code to field.hpp (https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file)
// And, traditionally, TODO: fix this shit
/*

Field::Field(int _w, int _h)
{
	cont.resize(_h);
	for (int y = 0; y < _h; ++y)
	{
		cont[y].resize(_w);
	}
	width = _w;
	height = _h;
}
T getAt(Position pos)
{
	int x = pos.getX();
	int y = pos.getY();
	
	if (x < 0)
	{
		x = 0;
	}
	if (x >= getW())
	{
		x = getW() - 1;
	}
	if (y < 0)
	{
		y = 0;
	}
	if (y >= getH())
	{
		y = getH() - 1;
	}
	
	return cont[y][x];
}

void setAt(T val, Position pos)
{
	int x = pos.getX();
	int y = pos.getY();
	
	if (x < 0)
	{
		x = 0;
	}
	if (x >= getW())
	{
		x = getW() - 1;
	}
	if (y < 0)
	{
		y = 0;
	}
	if (y >= getH())
	{
		y = getH() - 1;
	}
	
	cont[y][x] = val;
}

int getW()
{
	return width;
}
int getH()
{
	return height;
}*/

Field <char> wallField(80, 24);

Field <char> * getWallField()
{
	return &wallField;
}
