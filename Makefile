CXXIFLAGS=-I/usr/include/ncursesw -Iinclude
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

OBJECTS:=$(shell find src/*.cpp | sed 's/\.cpp/.o/g')
# Объектные файлы, используемые в проекте

EXECNAME?=main
# Имя исполняемого файла после сборки
# Внимание: во избежание «замусоривания» необходимо выполнить `make clean´
# перед изменением этого значения

.PHONY: all run clean ee
# all   - Выполнить сборку, но не заппускать
# run   - Если нужно, выполнить сборку, а затем запустить
# clean - Удалить исполняемые и объектные файлы
# ee    - Равносильно make clean && make run

all: $(EXECNAME)

$(EXECNAME): $(OBJECTS)
	$(CXX) $(OBJECTS) $(CXXLDFLAGS) -o $(EXECNAME)
	strip --strip-all $(EXECNAME)
	if ! ls -F "$(EXECNAME)" | grep '[*]' >/dev/null ; then chmod +x "$(EXECNAME)" ; fi
run: $(EXECNAME)
	./$(EXECNAME) || true
clean:
	rm $(EXECNAME) src/*.o || true
ee: clean run
