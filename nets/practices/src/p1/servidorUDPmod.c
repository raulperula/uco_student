/**
 * @file    servidorUDPmod.c
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
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>

/*
 * El servidor ofrece el servicio de incrementar un número recibido de un cliente
 */
 
main ()
{
	/*---------------------------------------------------- 
		Descriptor del socket y buffer de datos                
	-----------------------------------------------------*/
	int Socket_Servidor;
	struct sockaddr_in Servidor;
	int opcion = -1;
	struct tm *info;
	time_t timelocal;
	char cadena[100];
	
	/* -----------------------------------------------------
		Información del Cliente
	-----------------------------------------------------*/
	struct sockaddr_in Cliente;
	socklen_t Longitud_Cliente;
	
	
	/* --------------------------------------------------
		Se abre el socket Servidor
	---------------------------------------------------*/
	Socket_Servidor = socket (AF_INET, SOCK_DGRAM, 0);
	if (Socket_Servidor == -1)
	{
		printf ("No se puede abrir socket servidor\n");
		exit (-1);	
	}

	/* ------------------------------------------------------------------
		Se rellenan los campos de la estructura servidor, necesaria
		para la llamada a la funcion bind().
	-------------------------------------------------------------------*/
	Servidor.sin_family = AF_INET;
	Servidor.sin_port = htons(2000);
	Servidor.sin_addr.s_addr = INADDR_ANY; 

	if (bind (Socket_Servidor, (struct sockaddr *)&Servidor, sizeof (Servidor)) == -1)
	{
		close (Socket_Servidor);
	}
	

	/*---------------------------------------------------------------------
		Del cliente sólo necesitamos el tamaño de su estructura, el 
		resto de información (familia, puerto, ip), la obtendremos 
		nos la proporcionará el propio método recvfrom, cuando
		recibamos la llamada de un cliente.
	----------------------------------------------------------------------*/
	Longitud_Cliente = sizeof (Cliente);

   	
	/*-----------------------------------------------------------------------
		El servidor espera continuamente los mensajes de los clientes
	------------------------------------------------------------------------ */
	while(1){
		/* -----------------------------------------------------------------
			Esperamos la llamada de algún cliente
		-------------------------------------------------------------------*/
	 	int recibido = recvfrom (Socket_Servidor, &opcion, sizeof(opcion), 0,
		(struct sockaddr *) &Cliente, &Longitud_Cliente);

		/* -----------------------------------------------------------------
			Comprobamos si hemos recibido alguna información 
		-------------------------------------------------------------------*/
		if (recibido > 0)
		{
			time(&timelocal);
			info = localtime(&timelocal);
			
			switch(opcion){
				/* DAY */
				case 0: strftime(cadena, 100, "%d", info);
								break;
				/* TIME */
				case 1: strftime(cadena, 100, "%T", info);
								break;
				/* DAYTIME */
				case 2: strftime(cadena, 100, "%d %T", info);
								break;
			}
      
			/* ------------------------------------------------------------------
				Devolvemos la opcion elegida al cliente
			--------------------------------------------------------------------*/
			int enviado = sendto (Socket_Servidor, cadena, sizeof(cadena), 0,
			(struct sockaddr *) &Cliente, Longitud_Cliente);

		}

  }
}
