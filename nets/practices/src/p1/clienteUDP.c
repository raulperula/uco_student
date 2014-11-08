/**
 * @file    clienteUDP.c
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
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

/* --------------------------------------------------------------------------------------
 
 Envía un número aleatorio al servidor, quien el devuelve el número incremetnado

---------------------------------------------------------------------------------------- */
 
main ( )
{
  
	/*---------------------------------------------------- 
		Descriptor del socket y buffer para datos 
	-----------------------------------------------------*/
	int Socket_Cliente;
	struct sockaddr_in Cliente;
	int Datos;
   
	/* -----------------------------------------------------
		Información del Servidor
	-----------------------------------------------------*/
	struct sockaddr_in Servidor;  
	socklen_t Longitud_Servidor;


	/* --------------------------------------------------
		Se abre el socket cliente
	---------------------------------------------------*/
	Socket_Cliente = socket (AF_INET, SOCK_DGRAM, 0);
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
	

	/*------------------------------------------------------------------------
		Se genera un número aleatorio, que es el que se le manda al
		servidor.
	------------------------------------------------------------------------ */
   	srand (time(NULL)); /* Semilla para números aleatorios */
   	Datos = rand()%20;  /* Aleatorio entre 0 y 19 */
   	printf ("Envio %d\n", Datos);

	/*-----------------------------------------------------------------------
		Se envía mensaje al Servidor
	-----------------------------------------------------------------------*/
	int enviado = sendto (Socket_Cliente, (char *) &Datos, sizeof(Datos), 0,
			(struct sockaddr *) &Servidor, Longitud_Servidor);
   
	if (enviado < 0)
	{
		printf("Error al solicitar el servicio\n");
	}
    
	/*----------------------------------------------------------------------
		Esperamos la respuesta del Servidor
	----------------------------------------------------------------------- */ 
	int recibido = recvfrom (Socket_Cliente, (char *)&Datos, sizeof(Datos), 0,
			(struct sockaddr *) &Servidor, &Longitud_Servidor);
			
   	if (recibido > 0)
  		printf ("Leido %d\n", Datos);
   	else
  		printf ("Error al leer del servidor\n");
		
}
