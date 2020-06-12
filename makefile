OBJ_CATALOG=build/src

CC=gcc
CFLAGS=-c -Wall -Werror
LDFLAGS=-Wall -Werror
SOURCES=main.c howstring.c howsymbols.c getstring.c convert.c getch.c enter.c randposition.c compareansw.c readres.c wresult.c randword.c rres.c

OBJECTS=$(addprefix $(OBJ_CATALOG)/, $(SOURCES:.c=.o))
EXECUTABLE=main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o bin/main

$(OBJ_CATALOG)/%.o: src/%.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: all clean

clean:
	 rm -rf build/*/*.o
