all: main

main: bin/main

bin/main: build/src/main.o build/src/howstring.o
	gcc -Wall -Werror build/src/main.o build/src/howstring.o -o bin/main

build/src/main.o: src/main.c
	gcc -I includes -Wall -lncurses -ltinfo -Werror -c src/main.c -o build/src/main.o

build/src/howstring.o: src/howstring.c
	gcc -Wall -Werror -c src/howstring.c -o build/src/howstring.o
