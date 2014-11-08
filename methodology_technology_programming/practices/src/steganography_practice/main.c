/**
 * @file    main.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "imagen.h"
#include "esteganografia.h"

int
main(int argc, char *argv[])
{
	int opcion = -1;
	char *nomImagen, *nomStego, *nomMensaje;
	char *mensaje;
	int **matrizLSB, **matrizImagen; /* Matrices que contienen las imagenes */
	int *mensaje; /* Vector que contiene el mensaje en binario */
	int fil, col;
	int i;
	
	/* Opcion del sistema, limpiado de pantalla */
	system("clear");
	
	do{
		printf("\n -------------------------------------\n");
		printf(" | Elija una opcion:                 |\n");
		printf(" -------------------------------------\n");
		printf(" | Opcion 1: Codificar una imagen    |\n");
		printf(" -------------------------------------\n");
		printf(" | Opcion 2: Descodificar una imagen |\n");
		printf(" -------------------------------------\n");
		printf(" | Opcion 0: Salir del menu          |\n");
		printf(" -------------------------------------\n");
		printf("\n Opcion: ");
		scanf("%d", &opcion);
	
		switch(opcion){
			/* Codificar una imagen */
			case 1: printf("\n\t** CODIFICANDO **\n");
			
							/* Se pide el nombre del fichero con la imagen original */
							printf("\nNombre del fichero con la imagen: ");
							if((nomImagen = (char *) malloc(10*sizeof(char))) == NULL){
								fprintf(stderr, "\nERROR: no ha podido asignarse memoria\n");
								exit(-1);
							}
							scanf("%s", nomImagen);
							
							/* Se pide el nombre del fichero con la imagen que contendra el mensaje */
							printf("\nNombre del fichero que contendra la nueva imagen: ");
							if((nomStego = (char *) malloc(10*sizeof(char))) == NULL){
								fprintf(stderr, "\nERROR: no ha podido asignarse memoria\n");
								exit(-1);
							}
							scanf("%s", nomStego);
							
							/* Se pide el nombre del fichero con el mensaje original */
							printf("\nNombre del fichero donde esta el mensaje: ");
							if((nomMensaje = (char *) malloc(10*sizeof(char))) == NULL){
								fprintf(stderr, "\nERROR: no ha podido asignarse memoria\n");
								exit(-1);
							}
							scanf("%s", nomMensaje);
							
							/* Se lee la imagen original en formato 'unsigned char' */
							printf("\nCARGANDO IMAGEN...\n");
							
							cargarImagen(nomImagen, matrizImagen, &fil, &col); /* Funcion en 'imagen.c' */
							
							/* Se lee el mensaje y se almacena en una cadena de caracteres. Se añade siempre
								 al final la cadena '***' como fin de mensaje */
							printf("LEYENDO MENSAJE...	\n");
							
							leerMensaje(nomMensaje, mensaje);
							
							/* Se comprueba que el mensaje quepa dentro de la imagen. Se tiene en cuenta
								 la cadena '***' de fin de mensaje */
							printf("COMPROBANDO CAPACIDAD DE IMAGEN...\n");
							
							
							
							/* Se pasa el mensaje a binario */
							printf("PASANDO MENSAJE A BINARIO...\n");
							
							
							
							/* Se esconde el mensaje en los bits menos significativos de la imagen original */
							printf("OCULTANDO MENSAJE...\n");
							
							
							
							/* Se escribe la nueva imagen en un fichero */
							
							
							printf("FICHERO <%s> CREADO\n", nomStego);
							
							/* Se libera la memoria */
							free(nomImagen);
							free(nomStego);
							free(nomMensaje);
							
/*							for(i=0;i<col;i++){*/
/*								free(matrizLSB[i]);*/
/*							}*/
/*							free(matrizLSB);*/
/*							*/
/*							for(i=0;i<col;i++){*/
/*								free(matrizImagen[i]);*/
/*							}*/
/*							free(matrizImagen);*/
							
							break;
							
			/* Descodificar una imagen */
			case 2: printf("\n\t** DESCODIFICANDO **\n");
			
							/* Se pide el nombre del fichero con la imagen */
							printf("\nNombre del fichero con la imagen: ");
							if((nomImagen = (char *) malloc(10*sizeof(char))) == NULL){
								fprintf(stderr, "\nERROR: no ha podido asignarse memoria\n");
								exit(-1);
							}
							scanf("%s", nomImagen);
							
							/* Se pide el nombre del fichero donde se guardara el mensaje */
							printf("\nNombre del fichero donde se guardara el mensaje: ");
							if((nomMensaje = (char *) malloc(10*sizeof(char))) == NULL){
								fprintf(stderr, "\nERROR: no ha podido asignarse memoria\n");
								exit(-1);
							}
							scanf("%s", nomMensaje);
							
							/* Se lee la imagen con el mensaje en formato 'unsigned char' */
							printf("\nCARGANDO IMAGEN...\n");
							
							cargarImagen(nomImagen, matrizImagen, &fil, &col); /* Funcion en 'imagen.c' */
							
							/* Se obtiene la matriz LSB con los bits menos significativos de cada pixel */
							if((matrizLSB = (int **) malloc(fil*sizeof(int *))) == NULL){
								fprintf(stderr, "\nERROR: no ha podido asignarse memoria\n");
								exit(-1);
							}
							for(i=0;i<fil;i++){
								if((matrizLSB[i] = (int *) malloc(col*sizeof(int))) == NULL){
									fprintf(stderr, "\nERROR: no ha podido asignarse memoria\n");
									exit(-1);
								}
							}
							
							printf("OBTENIENDO MATRIZ LSB...\n");
							
							obtenerLSB(matrizImagen, matrizLSB, fil, col); /* Funcion en 'esteganografia.c' */
							
							/* Se obtiene el mensaje codificado en la matriz LSB */
							if((mensaje = (int *) malloc(((fil*col)/8)*sizeof(int))) == NULL){
								fprintf(stderr, "\nERROR: no ha podido asignarse memoria\n");
								exit(-1);
							}
							
							printf("OBTENIENDO MENSAJE...\n");
							
							obtenerMensaje(mensaje, matrizLSB, fil, col, (fil*col)/8); /* Funcion en 'esteganografia.c' */
							
							/* Se escribe el mensaje en un fichero de texto */
							escribirMensaje(nomMensaje, mensaje, (fil*col)/8); /* Funcion en 'imagen.c' */
							
							printf("FICHERO <%s> CREADO\n", nomMensaje);
							
							/* Se libera la memoria */
							free(nomImagen);
							free(nomMensaje);
							free(mensaje);
							
							for(i=0;i<col;i++){
								free(matrizLSB[i]);
							}
							free(matrizLSB);
							
							for(i=0;i<col;i++){
								free(matrizImagen[i]);
							}
							free(matrizImagen);
							
							break;
							
			/* Salida del programa */
			case 0: /* Opcion del sistema, limpiado de pantalla */
							system("clear");
							printf("\n\t** GRACIAS POR UTILIZAR EL PROGRAMA **\n\n");
							break;
							
			/* Opcion por defecto */
			default: printf("\nOpcion incorrecta, pruebe de nuevo\n");
							 break;
		}
		
		if(opcion != 0){
			getchar();
			getchar();
			/* Opcion del sistema, limpiado de pantalla */
			system("clear");
		}
		
	}while(opcion != 0);
	
	return(0);
}

