CFLAGS:=-Wall -Wextra

build: src/pargser.c src/pargser.h tests/test.c
	${CC} ${CFLAGS} src/pargser.c tests/test.c -o pargser

test: build
	.\pargser.exe