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

// Флаг возможности ввода. Если false, то ввод игнорируется. Каждые 0.15с устанавливается в true,
// после каждого ввода устанавливается в false
bool in = true;

// Обработчик события таймера
void onSigAlrm(int sig)
{
	in = true;
}


int main()
{
	// Установка таймеров
	// TODO: убрать в отдельный файл
	signal(SIGALRM, onSigAlrm);
	struct itimerval iv;
	struct timeval tvc, tvn;
	tvc.tv_sec = 0;
	tvc.tv_usec = 1000 * 150; // TODO: убрать в константу или конфиг
	tvn.tv_sec = 0;
	tvn.tv_usec = 1000 * 150;
	iv.it_interval = tvn;
	iv.it_value = tvc;
	setitimer(ITIMER_REAL, &iv, NULL);
	
	// Инициализация ncurses
	onIoInit();
	
	// Заполнение игрового поля
	Field <char> * wf = getWallField();
	
	// Просто что-то жудкое для генерации тестового поля
	for (int x = 0; x < 80; ++x)
	{
		for (int y = 0; y < 24; ++y)
		{
			Position pos(x, y);
			wf->setAt(((y == 5 || y == 3 || y == 2 || y == 10 || (y == 4 && x < 30)) ? (' ') : ('#')), pos);
			
			putCharAt(wf->getAt(pos), pos);
		}
	}
	// Всё ещё генерация
	wf->setAt('#', Position(60, 5));
	putCharAt('#', Position(60, 5));
	
	for (int y = 2; y < 13; ++y)
	{
		Position pos(73, y);
		wf->setAt('=', pos);
		putCharAt('=', pos);
	}
	// Конец генерации
	
	// Создаём движущийся объект
	Entity ent('p' | getColor(COLPR_MY_PLAYER));
	Position pos(70, 5);
	ent.setPosition(pos);
	ent.display();
	
	// Основной цикл
	// ВНИМАНИЕ: только для тестирования, перепродумать перед релизом
	while (true)
	{
		// Ввод с задержкой
		int ch = getch();
		if (!in)
		{
			continue;
		}
		in = false;
		
		// Обработка ввода
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
				// Выход
				onIoExit();
				return 0;
		}
		
		// Отображаем наши объекты на экране
		ent.display();
		swapBuffers();
	}
	
	// Выход
	onIoExit();
}
