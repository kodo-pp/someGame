#ifndef AI_ENTITY_HPP
#define AI_ENTITY_HPP

#include "entity.hpp"

class AIEntity : public Entity
{
	public:
		virtual void ai() = 0;
};

#endif // AI_ENTITY_HPP
