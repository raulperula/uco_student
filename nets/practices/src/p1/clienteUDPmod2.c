/**
 * @file    clienteUDPmod2.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <time.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

/* --------------------------------------------------------------------------------------
 
 Envía un número aleatorio al servidor, quien el devuelve el número incremetnado

---------------------------------------------------------------------------------------- */
 
main ( )
{
  struct timeval timeout;
  int c, opcion = -1;
  fd_set readfds;
  
	/*---------------------------------------------------- 
		Descriptor del socket y buffer para datos 
	-----------------------------------------------------*/
	int Socket_Cliente;
	struct sockaddr_in Cliente;
	char Datos[100], peticion[10];
   
	/* -----------------------------------------------------
		Información del Servidor
	-----------------------------------------------------*/
	struct sockaddr_in Servidor;  
	socklen_t Longitud_Servidor;


	/* --------------------------------------------------
		Se abre el socket cliente
	---------------------------------------------------*/
	Socket_Cliente = socket (AF_INET, SOCK_DGRAM, 0);
	FD_ZERO(&readfds);
	FD_SET(Socket_Cliente, &readfds);
	if (Socket_Cliente == -1)
	{
		printf ("No se puede abrir el socket cliente\n");
		exit (-1);	
	}

	/* ------------------------------------------------------------------
		Se rellenan los campos de la estructura cliente, necesaria
		para la llamada a la funcion bind().
	-------------------------------------------------------------------*/
	Cliente.sin_family = AF_INET;
	Cliente.sin_port = htons(1999);
	Cliente.sin_addr.s_addr =  inet_addr("127.0.0.1");

	if (bind (Socket_Cliente, (struct sockaddr *)&Cliente, sizeof (Cliente)) == -1)
	{
		close (Socket_Cliente);
	}

	/*---------------------------------------------------------------------
		Necesitamos una estructura con la información del Servidor
		para poder solicitarle un servicio.
	----------------------------------------------------------------------*/
	Servidor.sin_family = AF_INET;
	Servidor.sin_port = htons(2000);
	Servidor.sin_addr.s_addr =  inet_addr("127.0.0.1");
	Longitud_Servidor = sizeof(Servidor);
	
	/*-----------------------------------------------------------------------
		Peticion por pantalla
	-----------------------------------------------------------------------*/
	printf("\nEscriba la opcion que desee:\n");
	printf("  - DAY: ver el dia.\n");
	printf("  - TIME: ver la hora.\n");
	printf("  - DAYTIME: ver el dia y la hora.\n");
	printf("\nOpcion: ");
	scanf("%s", peticion);
	
	if(!strcmp("DAY", peticion)){
		opcion = 0;
	}
	else if(!strcmp("TIME", peticion)){
		opcion = 1;
	}
	else if(!strcmp("DAYTIME", peticion)){
		opcion = 2;
	}
		
	/*-----------------------------------------------------------------------
		Se envía mensaje al Servidor
	-----------------------------------------------------------------------*/
	int i = 0, encontrado = 0;
	int recibido;
	
	int enviado = sendto (Socket_Cliente, &opcion, sizeof(opcion), 0,
			(struct sockaddr *) &Servidor, Longitud_Servidor);
	 
	if (enviado < 0){
		printf("Error al solicitar el servicio\n");
	}
  
  timeout.tv_sec = 5;
  timeout.tv_usec = 0;
    
  while(!encontrado && i < 3){
  
    c = select(Socket_Cliente+1, &readfds, NULL, NULL, &timeout);
    
    if(c == 0){
    	printf ("Error al leer del servidor\n");
    }
		else if(c == -1){
  		printf("Error en select");
   		encontrado = 1;
    }
    else{
  	  recibido = recvfrom (Socket_Cliente, Datos, sizeof(Datos), 0,
				(struct sockaddr *) &Servidor, &Longitud_Servidor);
			printf ("\nLeido %s\n\n", Datos);
			encontrado = 1;
    }
    i++;
	}	
}
