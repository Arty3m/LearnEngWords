all: main

main: bin/main

bin/main: build/src/main.o build/src/howstring.o build/src/howsymbols.o
	gcc -Wall -Werror build/src/main.o build/src/howstring.o build/src/howsymbols.o -o bin/main

build/src/main.o: src/main.c
	gcc -I includes -Wall -lncurses -ltinfo -Werror -c src/main.c -o build/src/main.o

build/src/howstring.o: src/howstring.c
	gcc -Wall -Werror -c src/howstring.c -o build/src/howstring.o

build/src/howsymbols.o: src/howsymbols.c
	gcc -Wall -Werror -c src/howsymbols.c -o build/src/howsymbols.o
