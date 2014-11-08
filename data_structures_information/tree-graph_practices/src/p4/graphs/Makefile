####### Compiler, tools and options

CC       = gcc
CFLAGS   = -pipe -Wall -O2
LINK     = gcc
LIBS     = -lm


####### Output directory

OBJECTS_DIR = .

####### Files

HEADERS = principal.h \
                menu.h \
                creargrafo.h \
		caminosminimos.h \
		arbolabarcadorminimo.h \
		recorridos.h \
                tiposlados.h              
SOURCES = principal.c \
                menu.c \
                creargrafo.c \
                caminosminimos.c \
		arbolabarcadorminimo.c \
		recorridos.c \
		tiposlados.c \
		colas.c
OBJECTS = principal.o \
                menu.o \
                creargrafo.o \
                caminosminimos.o \
		arbolabarcadorminimo.o \
		recorridos.o \
		tiposlados.o \
		colas.o
QMAKE_TARGET = grafos
DESTDIR  = 
TARGET   = grafos

first: all
####### Implicit rules

.SUFFIXES: .c .C

.C.o:
	$(CC) -c $(CFLAGS) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) -o $@ $<

####### Build rules

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS)  $(LIBS)
        
clean: 
	-rm -f $(OBJECTS)

FORCE:

####### Compile

principal.o: principal.c principal.h \
                creargrafo.h \
                caminosminimos.h \
		arbolabarcadorminimo.h \
		recorridos.h \
                tiposlados.h 
	$(CC) -c $(CFLAGS)  -o principal.o principal.c

menu.o: menu.c menu.h 
	$(CC) -c $(CFLAGS)  -o menu.o menu.c

creargrafo.o: creargrafo.c creargrafo.h  
	$(CC) -c $(CFLAGS) -o creargrafo.o creargrafo.c

caminosminimos.o: caminosminimos.c caminosminimos.h \
                creargrafo.h  
	$(CC) -c $(CFLAGS)  -o caminosminimos.o caminosminimos.c

arbolabarcadorminimo.o: arbolabarcadorminimo.c arbolabarcadorminimo.h \
                creargrafo.h  
	$(CC) -c $(CFLAGS)  -o arbolabarcadorminimo.o arbolabarcadorminimo.c
	
colas.o: colas.c colas.h 
	$(CC) -c $(CFLAGS)  -o colas.o colas.c

recorridos.o: recorridos.c recorridos.h \
                creargrafo.h \
		colas.h 
	$(CC) -c $(CFLAGS)  -o recorridos.o recorridos.c
	
tiposlados.o: tiposlados.c tiposlados.h \
                creargrafo.h  
	$(CC) -c $(CFLAGS)  -o tiposlados.o tiposlados.c


####### Install

install: all 

uninstall: 
