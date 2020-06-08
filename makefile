all: main

main: bin/main

bin/main: build/src/main.o build/src/howstring.o build/src/howsymbols.o build/src/getstring.o build/src/convert.o build/src/getch.o build/src/enter.o
	gcc -Wall -Werror build/src/main.o build/src/howstring.o build/src/howsymbols.o build/src/getstring.o build/src/convert.o build/src/getch.o build/src/enter.o -o bin/main

build/src/main.o: src/main.c
	gcc -I includes -Wall -lncurses -ltinfo -Werror -c src/main.c -o build/src/main.o

build/src/howstring.o: src/howstring.c
	gcc -Wall -Werror -c src/howstring.c -o build/src/howstring.o

build/src/howsymbols.o: src/howsymbols.c
	gcc -Wall -Werror -c src/howsymbols.c -o build/src/howsymbols.o

build/src/getstring.o: src/getstring.c
	gcc -Wall -Werror -c src/getstring.c -o build/src/getstring.o

build/src/convert.o: src/convert.c
	gcc -Wall -Werror -c src/convert.c -o build/src/convert.o

build/src/getch.o: src/getch.c
	gcc -Wall -Werror -c src/getch.c -o build/src/getch.o

build/src/enter.o: src/enter.c
	gcc -Wall -Werror -c src/enter.c -o build/src/enter.o

.PHONY: clean

clean:
	 rm -rf build/*/*.o
