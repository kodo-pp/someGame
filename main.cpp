#include <iostream>
#include <ncurses.h>
#include "io.hpp"
#include <unistd.h>
#include "entity.hpp"
#include "field.hpp"
#include <sys/time.h>
#include <signal.h>

#include <fstream>

using namespace std;


bool in = true;

void onSigAlrm(int sig)
{
	in = true;
}


int main()
{
	signal(SIGALRM, onSigAlrm);
	struct itimerval iv;
	struct timeval tvc, tvn;
	tvc.tv_sec = 0;
	tvc.tv_usec = 1000 * 150;
	tvn.tv_sec = 0;
	tvn.tv_usec = 1000 * 150;
	iv.it_interval = tvn;
	iv.it_value = tvc;
	setitimer(ITIMER_REAL, &iv, NULL);
	
	onIoInit();
	Field <char> * wf = getWallField();
	
	for (int x = 0; x < 80; ++x)
	{
		for (int y = 0; y < 24; ++y)
		{
			Position pos(x, y);
			wf->setAt(((y == 5 || y == 3 || y == 2 || y == 10 || (y == 4 && x < 30)) ? (' ') : ('#')), pos);
			
			putCharAt(wf->getAt(pos), pos);
		}
	}
	
	wf->setAt('#', Position(60, 5));
	putCharAt('#', Position(60, 5));
	
	for (int y = 2; y < 13; ++y)
	{
		Position pos(73, y);
		wf->setAt('=', pos);
		putCharAt('=', pos);
	}
	
	Entity ent('p' | getColor(COLPR_MY_PLAYER));
	Position pos(70, 5);
	ent.setPosition(pos);
	ent.display();
	
	while (true)
	{
		int ch = getch();
		if (!in)
		{
			continue;
		}
		in = false;
		switch(ch)
		{
			case KEY_LEFT:
				ent.move(DIR_LEFT);
				break;
			case KEY_RIGHT:
				ent.move(DIR_RIGHT);
				break;
			case KEY_DOWN:
				ent.move(DIR_DOWN);
				break;
			case KEY_UP:
				ent.move(DIR_UP);
				break;
			case ' ': case 'q': 
				onIoExit();
				return 0;
		}
		ent.display();
		swapBuffers();
	}
	swapBuffers();
	getch();
	onIoExit();
}
