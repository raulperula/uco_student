##############################################################
#  Practicas MTP
#  Makefile de ejemplo para la construccion de las practicas.
##############################################################

# EJECUTABLE=  nombre del fichero ejecutable que queremos crear
#

EJECUTABLE=  ejemplo

#  MODULOS=  lista de nombres con los modulos que se van a 
#            compilar. Cada uno se corresponde con un fichero C
#            Se le pone la extension .o para indicar el fichero objeto
#            generado por el compilador.
#
#            El modulo libGrafica.a constituye la librería gráfica de 
#            bajo nivel
#         
#
#

MODULOS=  ejemplo.o libGrafica.a


################ NO MODIFICAR A PARTIR DE AQUI ########################

#  CFLAGS= Parametros para el compilador de C
#        
#	      -G   (para que genere informacion para el depurador)
#             -c   (solo compilar cada modulo, no linkar)
#             -I   (indicamos directiorios donde buscar los include)

CFLAGS=  -g -c -DXWINDOWS -I/usr/openwin/include  -I.

#  LDFLAGS= Parametros para el linkador. (ld)
#           le decimos que busque las librerias 
#           de X WINDOWS en el directorio indicado         

# sun
#LDFLAGS=   -L /usr/openwin/lib/X11R4

# linux
LDFLAGS=   -L /usr/X11R6/lib
   
#  LIBS= librerias que vamos a linkar para hacer nuestro programa
#
#        en este caso necesitamos las siguientes:
#
#              X11      manejo de X Windows
#              c        libreria estandard de C
#              malloc   para usar la funcion malloc
#              m        funciones matematicas (sin y cos, p.ej.)


# linux
LIBS=    -lc -lm libX11.so.6.2

#  CC= orden de UNIX que invoca al compilador de C
#      (en este caso "gcc" llama al compilador de C/C++ de GNU) 

CC=        gcc

#   Las siguientes lineas le indican al programa make que
#   para construir el ejecutable debe compilar primero los 
#   ficheros objeto que aun no esten compilados y despues linkarlos 
#   todos juntos.

$(EJECUTABLE): $(MODULOS)	
	$(CC)  -o$(EJECUTABLE) $(LDFLAGS) $(MODULOS)  $(LIBS)   


#  la siguiente linea permite que mediante la instruccion:
#
#       make todo 
#
#   se recompilen todos los fuentes.

todo:
	touch *.c
	make
