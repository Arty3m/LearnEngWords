OBJ_CATALOG=build/src
OBJ_CATALOG_TEST=build/test

CC=gcc
CFLAGS=-c -Wall -Werror
LDFLAGS=-Wall -Werror
SOURCES=main.c howstring.c howsymbols.c getstring.c convert.c getch.c enter.c randposition.c compareansw.c readres.c wresult.c randword.c rres.c
SOURCES_TEST=main-test.c howstring.c howsymbols.c randposition.c randword.c rres.c getstring.c
VPATH=src test

OBJECTS=$(addprefix $(OBJ_CATALOG)/, $(SOURCES:.c=.o))
OBJECTS_TEST=$(addprefix $(OBJ_CATALOG_TEST)/, $(SOURCES_TEST:.c=.o))
EXECUTABLE=main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(OBJECTS_TEST)
	$(CC) $(LDFLAGS) $(OBJECTS) -o bin/main
	$(CC) $(LDFLAGS) $(OBJECTS_TEST) -o bin/main-test
	./bin/main-test

$(OBJ_CATALOG)/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(OBJ_CATALOG_TEST)/%.o: %.c
	$(CC) -I thirdparty -I src $(CFLAGS) $< -o $@

.PHONY: all clean

clean:
	 rm -rf build/*/*.o
