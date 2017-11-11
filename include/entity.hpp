#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "position.hpp"
#include "direction.hpp"

class Entity
{
	public:
		Entity(int);
		virtual ~Entity();
		Position getPosition();
		void setPosition(Position);
		void move(Direction);
		virtual void display();
		virtual void hit(Direction);
	protected:
		void setDisplayChar(int);
		int getDisplayChar();
		virtual void clear();
		Position position;
		int displayChar;
};

#endif // ENTITY_HPP
