#include <ncurses.h>
#include "position.hpp"
#include "io.hpp"

int getColor(colorPairs cpno)
{
	return COLOR_PAIR(cpno);
}

void initColorPairs()
{
	init_pair(COLPR_NORMAL, COLOR_WHITE, COLOR_BLACK);
	init_pair(COLPR_EXPLOSION, COLOR_WHITE, COLOR_RED);
	init_pair(COLPR_MY_PLAYER, COLOR_BLACK, COLOR_GREEN);
	init_pair(COLPR_OTHER_PLAYER, COLOR_BLACK, COLOR_YELLOW);
	init_pair(COLPR_GHOST_INVIS, COLOR_BLUE, COLOR_CYAN);
	init_pair(COLPR_ENEMY, COLOR_RED, COLOR_BLACK);
}

void onIoInit()
{
	initscr();
	start_color();
	initColorPairs();
	noecho();
	curs_set(0);
	keypad(stdscr, true);
}

void putCharAt(int ch, Position pos)
{
	move(pos.getY(), pos.getX());
	addch(ch);
}

void swapBuffers()
{
	refresh();
}

void onIoExit()
{
	echo();
	curs_set(1);
	keypad(stdscr, false);
	endwin();
}

