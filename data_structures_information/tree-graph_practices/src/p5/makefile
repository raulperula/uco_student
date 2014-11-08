#Herramientas y opciones
CC			=	g++
CFLAGS	=	-Wall -g3

all: grafos.exe clean

grafos.exe: grafo.o grafo.h lado.h cola.h
	@echo Generando ejecutable...
	@$(CC) grafo.o -o grafos.exe
	@echo Ejecutable generado correctamente.

grafo.o: grafo.cpp grafo.h lado.h cola.h
	@echo Generando codigo objeto...
	@$(CC) $(CFLAGS) -c grafo.cpp
	@echo Codigo objeto generado correctamente.
	
.PHONY: clean
clean:
	@echo Eliminando archivos temporales...
	@rm -f *.o *~
	@echo Eliminacion concluida.

