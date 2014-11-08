#makefile

#Escribir "make" para crear el ejecutable y limpiar archivos temporales y objeto

all: ej.exe clean

ej.exe: main.o image.o fimage.o imageutils.h histogram.h morphologicalutils.h
	g++ -I. -lm main.o image.o fimage.o -o ej.exe

main.o: main.cpp image.h imagearith.h linearcontrast.h linearfunction.h
	g++ -I. -Wall -g3 -c main.cpp

image.o: image.cpp image.h imageexception.h imagearith.h
	g++ -I. -Wall -g3 -c image.cpp
	
fimage.o: fimage.cpp fimage.h imageexception.h
	g++ -I. -Wall -g3 -c fimage.cpp

clean:
	rm -f *.o *~

