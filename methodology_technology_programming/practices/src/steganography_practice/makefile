#makefile

CC			=	gcc
WFLAGS	=	-Wall
OBJ			= -c

all: estego.exe clean

estego.exe: main.o imagen.o esteganografia.o
	$(CC) main.o imagen.o esteganografia.o -o estego.exe -lm

main.o: main.c
	$(CC) $(WFLAGS) $(OBJ) main.c

imagen.o: imagen.c imagen.h
	$(CC) $(WFLAGS) $(OBJ) imagen.c

esteganografia.o: esteganografia.c esteganografia.h
	$(CC) $(WFLAGS) $(OBJ) esteganografia.c

clean:
	rm -f *.o *~

