#include <iostream>
#include <ncurses.h>
#include "io.hpp"
#include <unistd.h>
#include "entity.hpp"
#include "field.hpp"

using namespace std;
int main()
{/*
	onIoInit();
	
	Entity ent('p' | A_BOLD | getColor(COLPR_ENEMY));
	Position pos(4, 7);
	ent.setPosition(pos);
	Position pos1;
	pos1.from(ent.getPosition());
	
	ent.display();
	swapBuffers();
	getch();
	onIoExit();
	*/
	onIoInit();
	Field <char> * wf = getWallField();
	
	for (int x = 0; x < 80; ++x)
	{
		for (int y = 0; y < 24; ++y)
		{
			Position pos(x, y);
			wf->setAt(((y == 5) ? (' ') : ('#')), pos);
			putCharAt(wf->getAt(pos), pos);
		}
	}
	swapBuffers();
	getch();
	onIoExit();
}
