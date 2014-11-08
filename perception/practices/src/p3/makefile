#makefile

#Escribir "make" para crear el ejecutable y limpiar archivos temporales y objeto

all: ej1.exe ej2.exe ej3.exe clean

ej1.exe: prueba1.o image.o
	g++ -I. prueba1.o image.o -o ej1.exe

prueba1.o: prueba1.cpp image.h imagearith.h linearcontrast.h linearfunction.h
	g++ -I. -g3 -c prueba1.cpp

ej2.exe: prueba2.o image.o
	g++ -I. prueba2.o image.o -o ej2.exe

prueba2.o: prueba2.cpp image.h imagearith.h linearcontrast.h linearfunction.h
	g++ -I. -g3 -c prueba2.cpp

ej3.exe: prueba3.o image.o
	g++ -I. prueba3.o image.o -o ej3.exe

prueba3.o: prueba3.cpp image.h imagearith.h linearcontrast.h linearfunction.h
	g++ -I. -g3 -c prueba3.cpp

image.o: image.cpp image.h imageexception.h imagearith.h
	g++ -I. -g3 -c image.cpp

clean:
	rm -f *.o *~

