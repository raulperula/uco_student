/**
 * @file    ejemploClienteTCP.c
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
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

main ( )
{

	/*----------------------------------------------------
		Descriptor del socket y buffer de datos
	-----------------------------------------------------*/
	int sd, fin = 0;
	struct sockaddr_in sockname;
	char cadena[250];	
	socklen_t len_sockname;
	fd_set general, buffer;

	/* --------------------------------------------------
		Se abre el socket
	---------------------------------------------------*/
  sd = socket (AF_INET, SOCK_STREAM, 0);
	if(sd == -1){
		perror("No se puede abrir el socket cliente\n");
		exit (1);
	}

	/* ------------------------------------------------------------------
		Se rellenan los campos de la estructura con la IP del
		servidor y el puerto del servicio que solicitamos
	-------------------------------------------------------------------*/
	sockname.sin_family = AF_INET;
	sockname.sin_port = htons(2000);
	sockname.sin_addr.s_addr = inet_addr("127.0.0.1");

	/* ------------------------------------------------------------------
		Se solicita la conexión con el servidor
	-------------------------------------------------------------------*/	
	len_sockname = sizeof(sockname);
	
	/* Inicializacion */
	FD_ZERO(&general);
	FD_ZERO(&buffer);
	
	if(connect(sd, (struct sockaddr *) &sockname, len_sockname) == -1){
		perror("Error de conexión");
		exit(1);
	}

	/* ------------------------------------------------------------------
		Se transmite la información de forma que:
			1.- Se inicializan los fd_set 'general' y 'buffer' (arriba)
			2.- Mientras que no se reciba 'QUIT'
				2.1.- Se iguala buffer a general (buffer=general;)
				2.2.- Se bloque hasta: dos opciones, una, que se escriba algo por
							teclado,
							o dos, que se reciba algun mensaje desde el servidor
							Esto se realizara con la funcion 'select'
				2.3.- Ahora se controlaran con 'FD_SET' las dos opciones posibles que
							hemos dicho, 0 para la entrada estandar, y 'buffer' para los
							mensajes
				2.4.- Si se ha escrito por teclado (FD_ISSET(0, &buffer)), se enviara al
						 	servidor para su posterior tratamiento
				2.5.- Si no, sera que el servidor esta mandando algo, con lo que nos
							ponemos a la recepcion del mensaje
	-------------------------------------------------------------------*/
	FD_SET(0, &general);
	FD_SET(sd, &general);
	
	do{
		buffer = general;
		
		printf("Mensaje:\n");
		
		if(select(FD_SETSIZE, &buffer, NULL, NULL, NULL) == -1){
      perror("Error en la funcion <select>");
      exit(1);
    }
		
		if(FD_ISSET(0, &buffer)){
			fgets(cadena, sizeof(cadena), stdin);

			if(send(sd, cadena, strlen(cadena), 0) == -1){
				perror("Error enviando datos en el cliente");
			}
			
			if(strncmp(cadena, "quit", 4) == 0){
				fin = 1;
			}
		}
		else{
			bzero(cadena, sizeof(cadena));
			if(recv(sd, cadena, sizeof(cadena), 0) == -1){
				perror("Error en la operación de recv con el cliente");
			}
			
			/*habria que recibir el mensaje con el nick*/
			printf("%s\n", cadena);
		}

	}while(fin == 0);
	
	/* Por ultimo, liberamos memoria y cerramos los sockets */
	close(sd);
}

