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
		std::vector < std::vector < T > > container;
		int width, height;
};

Field <char> * getWallField();
//Field getEntityField();

#endif // FIELD_HPP
