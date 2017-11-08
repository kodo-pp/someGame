#ifndef IO_H
#define IO_H
;
#include <ncurses.h>
#include "position.hpp"

enum colorPairs
{
	COLPR_NORMAL,
	COLPR_EXPLOSION,
	COLPR_MY_PLAYER,
	COLPR_OTHER_PLAYER,
	COLPR_GHOST_INVIS,
	COLPR_ENEMY
};

int getColor(colorPairs);
void onIoInit();
void putCharAt(int, Position);
void swapBuffers();
void onIoExit();
static const int CLEAR_CHAR = ' ' | A_NORMAL;
#endif
