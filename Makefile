CXXIFLAGS=-I/usr/include/ncursesw
# Флаги включений заголовков

CXXLFLAGS=-lncursesw
# Флаги подключения библиотек

CXXAFLAGS=-O2 -Wall -std=c++11
# Дополнительные флаги

CXXLDAFLAGS=
# Дополнительные флаги для линковщика

CXXLDFLAGS=$(CXXLFLAGS) $(CXXLDAFLAGS)
# Все флаги для линковщика

CXXFLAGS+=$(CXXIFLAGS) $(CXXAFLAGS)
# Все флаги для компилятора (без линковки)


.PHONY: all run clean ee
# all   - Выполнить сборку, но не заппускать
# run   - Если нужно, выполнить сборку, а затем запустить
# clean - Удалить исполняемые и объектные файлы
# ee    - Равносильно make clean && make run

all: main

main: main.o entity.o io.o move.o field.o
	$(CXX) main.o entity.o io.o move.o field.o $(CXXLDFLAGS) -o main
	strip --strip-all main
run: main
	./main || true
clean:
	rm main *.o || true
ee: clean run
