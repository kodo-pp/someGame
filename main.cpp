#include <iostream>
#include <ncurses.h>
#include "io.hpp"
#include <unistd.h>
#include "entity.hpp"
#include "field.hpp"

#include <fstream>

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
	Entity ent('p' | getColor(COLPR_MY_PLAYER));
	Position pos(2, 5);
	ent.setPosition(pos);
	ent.display();
	
	ofstream fout("log.log");
	
	while (true)
	{
		int ch = getch();
		switch(ch)
		{
			case KEY_LEFT:
				fout << "left_key\n";
				ent.move(DIR_LEFT);
				break;
			case KEY_RIGHT:
				fout << "right_key\n";
				ent.move(DIR_RIGHT);
				break;
			case ' ':
				onIoExit();
				return 0;
		}
		ent.display();
		swapBuffers();
	}
	fout.close();
	swapBuffers();
	getch();
	onIoExit();
}
