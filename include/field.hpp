#ifndef FIELD_HPP
#define FIELD_HPP

#include <vector>
#include "position.hpp"

//; // magic!!1!
template <class T> class Field
{
	public:
		Field(int, int);
		T getAt(Position);
		void setAt(T, Position);
		int getW();
		int getH();
	protected:
		std::vector < std::vector < T > > cont;
		int width, height;
};

Field <char> * getWallField();



template <class T> Field<T>::Field(int _w, int _h)
{
	cont.resize(_h);
	for (int y = 0; y < _h; ++y)
	{
		cont[y].resize(_w);
	}
	width = _w;
	height = _h;
}
template <class T> T Field<T>::getAt(Position pos)
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

template <class T> void Field<T>::setAt(T val, Position pos)
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

template <class T> int Field<T>::getW()
{
	return width;
}
template <class T> int Field<T>::getH()
{
	return height;
}




//Field getEntityField();

#endif // FIELD_HPP
