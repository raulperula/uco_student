#makefile

all: practica1 practica2 practica3 primos

practica1: practica1_2a practica1_2b practica1_2c practica1_2d practica1_2e practica1_2f practica1_3

practica2: practica2_1 practica2_2 practica2_3 practica2_4 practica2_7

practica1_2a: practica1_2a.c
	mpicc practica1_2a.c -o practica1_2a.exe -lmpi
practica1_2b: practica1_2b.c
	mpicc practica1_2b.c -o practica1_2b.exe -lmpi
practica1_2c: practica1_2c.c
	mpicc practica1_2c.c -o practica1_2c.exe -lmpi
practica1_2d: practica1_2d.c
	mpicc practica1_2d.c -o practica1_2d.exe -lmpi
practica1_2e: practica1_2e.c
	mpicc practica1_2e.c -o practica1_2e.exe -lmpi
practica1_2f: practica1_2f.c
	mpicc practica1_2f.c -o practica1_2f.exe -lmpi
practica1_3: practica1_3.c
	mpicc practica1_3.c -o practica1_3.exe -lmpi

practica2_1: practica2_1.c
	mpicc practica2_1.c -o practica2_1.exe -lmpi
practica2_2: practica2_2.c
	mpicc practica2_2.c -o practica2_2.exe -lmpi
practica2_3: practica2_3.c
	mpicc practica2_3.c -o practica2_3.exe -lmpi
practica2_4: practica2_4.c
	mpicc practica2_4.c -o practica2_4.exe -lmpi
practica2_7: practica2_7.c
	mpicc practica2_7.c -o practica2_7.exe -lmpi
	
practica3: practica3.c
	mpicc practica3.c -o practica3.exe -lmpi

primos: primos.c
	mpicc primos.c -o primos.exe -lmpi -lm

clean:
	rm -f *.o *~ PI* *.exe
