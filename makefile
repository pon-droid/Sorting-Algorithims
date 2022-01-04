PKGS=sdl2
CFLAGS=-Wall -Wextra -pedantic -std=c11 `pkg-config --cflags $(PKGS)`
LIBS=`pkg-config --libs $(PKGS)`

sorting: main.c
	$(CC) $(CFLAGS) -o sorting main.c $(LIBS)
