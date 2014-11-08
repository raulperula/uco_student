################################################################################
#	Este es el makefile para compilar los archivos en C y en BACI de los				 #
# algoritmos: productores/consumidores y cena de los filosofos.							 	 #
#																																							 #
# Para compilar cualquiera de los codigos solo tendra que poner 'make' en la	 #
# terminal, dependiendo que codigo haya querido ver, el codigo en C le creara  #
# un ejecutable con el nombre del algoritmo implementado y el codigo en BACI	 #
# compilara y utilizara su interprete para ejecutar el algoritmo directamente. #
################################################################################

CC			=	gcc
CFLAGS	=	-g
HFLAGS	= -lpthread

# Regla para compilar los archivos (descomente la que quiera compilar y comente
# la otra)

#allC: FilosofosC ProConC cleanC
allBACI: FilosofosBACI ProConBACI cleanBACI

################################################################################

#Makefile para archivos en C

FilosofosC: Filosofos.o
	@echo
	@echo ======================================================
	@echo Compilando filosofos...
	@$(CC) $< -o $@ $(HFLAGS)
	@echo Completado.
	@echo ======================================================

Filosofos.o: Filosofos.c
	@$(CC) $(CFLAGS) -c Filosofos.c

ProConC: ProCon.o
	@echo
	@echo ======================================================
	@echo Compilando productores-consumidores...
	@$(CC) $< -o $@ $(HFLAGS)
	@echo Completado.
	@echo ======================================================

ProCon.o: ProCon.c
	@$(CC) $(CFLAGS) -c ProCon.c

################################################################################

#Makefile para archivos en BACI

FilosofosBACI: Filosofos.pco
	@echo
	@echo ======================================================
	@echo Ejecutando codigo Filosofos en el interprete...
	@echo
	@bainterp $<
	@echo ======================================================

Filosofos.pco: Filosofos.cm
	@echo
	@echo ======================================================
	@echo Compilando filosofos...
	@bacc $<
	@echo Completado.
	@echo ======================================================

ProConBACI: ProCon.pco
	@echo
	@echo ======================================================
	@echo Ejecutando codigo Pro-Con en el interprete...
	@echo
	@bainterp $<
	@echo ======================================================

ProCon.pco: ProCon.cm
	@echo
	@echo ======================================================
	@echo Compilando productores-consumidores...
	@bacc $<
	@echo Completado.
	@echo ======================================================

################################################################################

# Opcion para limpiar los archivos en C
cleanC:
	@echo
	@echo ======================================================
	@echo Eliminando codigo objeto y archivos temporales...
	@rm -f *~ *.o
	@echo Eliminacion completada.
	@echo ======================================================

# Opcion para limpiar los archivos en BACI
cleanBACI:
	@echo
	@echo ======================================================
	@echo Eliminando codigo .pco y .lst y archivos temporales...
	@rm -f *~ *.pco *.lst
	@echo Eliminacion completada.
	@echo ======================================================

