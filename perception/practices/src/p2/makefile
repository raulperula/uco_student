#makefile

#Escribir "make" para crear el ejecutable y limpiar archivos temporales y objeto

all: ej.exe clean

ej.exe: main.o image.o
	g++ main.o image.o -o ej.exe

main.o: main.cpp image.h imagearith.h
	g++ -I. -g3 -c main.cpp

image.o: image.cpp image.h imageexception.h imagearith.h
	g++ -I. -g3 -c image.cpp

clean:
	rm -f *.o *~

