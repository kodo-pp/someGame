#include "entity.hpp"
#include "move.hpp"
#include "field.hpp"
#include "io.hpp"
#include <fstream>

/*
class Entity
{
	public:
		virtual Entity();
		virtual ~Entity();
		Position getPosition();
		MoveState move(Direction);
		virtual void display();
		virtual void hit(Direction)
	protected:
		void setDisplayChar(int);
		int getDisplayChar();
		virtual void clear();
		Position position;
		int displayChar;
};
*/
std::ofstream efout;

Entity::Entity(int _displayChar)
{
	setDisplayChar(_displayChar);
	efout.open("efout.log");
	position.setXY(0, 0);
}
Entity::~Entity()
{
	efout.close();
}
Position Entity::getPosition()
{
	Position _pos;
	_pos.from(position);
	return _pos;
}
void Entity::setPosition(Position _pos)
{
	efout << "setPosition(" << _pos.getX() << ", " << _pos.getY() << ")\n";
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
	putCharAt(CLEAR_CHAR, getPosition());
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
			efout << "move(" << dir << ")\n";
			bool success = false;
			Position newPosition = getPossibleMovePosition(getPosition(), dir, success);
			if (success)
			{
				//moveChar(newPosition);
				setPosition(newPosition);
			}
			break;
		
	}
}

