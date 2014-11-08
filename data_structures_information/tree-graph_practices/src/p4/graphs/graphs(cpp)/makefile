#Herramientas y opciones
CC		=	g++
CFLAGS	=	-Wall -g3

all: codigo clean

codigo: grafo.cpp grafo.h lado.h cola.h
	@echo Generando ejecutable...
	@$(CC) $(CFLAGS) grafo.cpp -o grafos.exe
	@echo Ejecutable generado correctamente.
	
.PHONY: clean
clean:
	@echo Eliminando archivos temporales...
	@rm -f *~
	@echo Eliminacion concluida.

