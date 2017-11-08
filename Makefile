CXXIFLAGS=-I/usr/include/ncursesw
# Флаги включений заголовков

CXXLFLAGS=-lncursesw
# Флаги подключения библиотек

CXXAFLAGS=-O2 -Wall -std=gnu++11
# Дополнительные флаги

CXXLDAFLAGS=
# Дополнительные флаги для линковщика

CXXLDFLAGS=$(CXXLFLAGS) $(CXXLDAFLAGS)
# Все флаги для линковщика

CXXFLAGS=$(CXXIFLAGS) $(CXXAFLAGS)
# Все флаги для компилятора (без линковки)

.PHONY: all run clean ee
# all   - Выполнить сборку, но не заппускать
# run   - Если нужно, выполнить сборку, а затем запустить
# clean - Удалить исполняемые и объектные файлы
# ee    - Равносильно make clean && make run

all: main
main: main.o entity.o io.o move.o field.o
	g++ main.o entity.o io.o move.o field.o $(CXXLDFLAGS) -o main
	strip --strip-debug main # Немного уменьшим размер исполняемого файла
main.o: main.cpp
	g++ main.cpp $(CXXFLAGS) -c -o main.o
entity.o: entity.cpp
	g++ entity.cpp $(CXXFLAGS) -c -o entity.o
io.o: io.cpp
	g++ io.cpp $(CXXFLAGS) -c -o io.o
move.o: move.cpp
	g++ move.cpp $(CXXFLAGS) -c -o move.o
field.o: field.cpp
	g++ field.cpp $(CXXFLAGS) -c -o field.o
run: main
	./main || true
clean:
	rm main *.o || true
ee: clean run

