#include "entity.hpp"
#include "move.hpp"
#include "field.hpp"
#include "io.hpp"
#include <fstream>

Entity::Entity(int _displayChar)
{
	setDisplayChar(_displayChar);
	position.setXY(0, 0);
}
Entity::~Entity()
{
}
Position Entity::getPosition()
{
	Position _pos;
	_pos.from(position);
	return _pos;
}
void Entity::setPosition(Position _pos)
{
	position.from(_pos);
}

void Entity::display()
{
	putCharAt(getDisplayChar(), getPosition());
}

void Entity::hit(Direction dir)
{}

void Entity::clear()
{
	Field <char> * wf = getWallField();
	if (wf == nullptr)
	{
		return;
	}
	
	putCharAt(wf->getAt(getPosition()), getPosition());
}
void Entity::setDisplayChar(int _displayChar)
{
	displayChar = _displayChar;
}

int Entity::getDisplayChar()
{
	return displayChar;
}


void Entity::move(Direction dir)
{
	switch(dir)
	{
		case DIR_UP: case DIR_DOWN: case DIR_LEFT: case DIR_RIGHT:
			bool success = false;
			Position newPosition = getPossibleMovePosition(getPosition(), dir, success);
			if (success)
			{
				clear();
				setPosition(newPosition);
				display();
			}
			break;
		
	}
}

