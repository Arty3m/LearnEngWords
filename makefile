OBJ_CATALOG=build/src

CC=gcc
CFLAGS=-c -Wall -Werror
LDFLAGS=-Wall -Werror
SOURCES=main.c howstring.c howsymbols.c getstring.c convert.c getch.c enter.c randposition.c compareansw.c readres.c wresult.c randword.c rres.c

OBJECTS=$(addprefix $(OBJ_CATALOG)/, $(SOURCES:.c=.o))
EXECUTABLE=EngWords

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
$(CC) $(LDFLAGS) $(OBJECTS) -o bin/main

$(OBJ_CATALOG)/main.o: src/main.c
$(CC) $(CFLAGS) src/main.c -o $@

$(OBJ_CATALOG)/howstring.o: src/howstring.c
$(CC) $(CFLAGS) src/howstring.c -o $@

$(OBJ_CATALOG)/howsymbols.o: src/howsymbols.c
$(CC) $(CFLAGS) src/howsymbols.c -o $@

$(OBJ_CATALOG)/getstring.o: src/getstring.c
$(CC) $(CFLAGS) src/getstring.c -o $@

$(OBJ_CATALOG)/convert.o: src/convert.c
$(CC) $(CFLAGS) src/convert.c -o $@

$(OBJ_CATALOG)/getch.o: src/getch.c
$(CC) $(CFLAGS) src/getch.c -o $@

$(OBJ_CATALOG)/enter.o: src/enter.c
$(CC) $(CFLAGS) src/enter.c -o $@

$(OBJ_CATALOG)/randposition.o: src/randposition.c
$(CC) $(CFLAGS) src/randposition.c -o $@

$(OBJ_CATALOG)/compareansw.o: src/compareansw.c
$(CC) $(CFLAGS) src/compareansw.c -o $@

$(OBJ_CATALOG)/readres.o: src/readres.c
$(CC) $(CFLAGS) src/readres.c -o $@

$(OBJ_CATALOG)/wresult.o: src/wresult.c
$(CC) $(CFLAGS) src/wresult.c -o $@

$(OBJ_CATALOG)/randword.o: src/randword.c
$(CC) $(CFLAGS) src/randword.c -o $@

$(OBJ_CATALOG)/rres.o: src/rres.c
$(CC) $(CFLAGS) src/rres.c -o $@

.PHONY: all clean

clean:
rm -rf build/*/*.o
