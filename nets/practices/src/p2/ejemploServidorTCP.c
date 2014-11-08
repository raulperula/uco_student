/**
 * @file    ejemploServidorTCP.c
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

/*
 * El servidor ofrece el servicio de incrementar un número recibido de un cliente
 */

main()
{
  
	/*---------------------------------------------------- 
		Descriptor del socket y buffer de datos                
	-----------------------------------------------------*/
	int i, sd, new_sd, fd[50], cont = 0;
	int rec_sd;
	struct sockaddr_in sockname, from;
	char cadena[250];
	socklen_t from_len;
	char nick[50][250];
	
	for(i=0;i<50;i++){
		fd[i] = 0;
	}
	
  fd_set auxBuffer, buffer;
  
  FD_ZERO(&buffer);
  FD_ZERO(&auxBuffer);

	/* --------------------------------------------------
		Se abre el socket de escucha
	---------------------------------------------------*/
	if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		perror("No se puede abrir el socket cliente\n");
		exit (1);
	}

	/*
 		* El servidor ofrece el servicio de incrementar un número recibido de un cliente
 	*/

	sockname.sin_family = AF_INET;
	sockname.sin_port = htons(2000);
	sockname.sin_addr.s_addr =  INADDR_ANY;

	if(bind(sd, &sockname, sizeof(sockname)) == -1){
		perror("Error en la operación bind");
		exit(1);
	}

	/*---------------------------------------------------------------------
	De las peticiones que vamos a aceptar sólo necesitamos el 
	tamaño de su estructura, el resto de información (familia, puerto, 
	ip), nos la proporcionará el métoFD_ZERO(&buffer);do que recibe las peticiones.
  	----------------------------------------------------------------------*/
	from_len = sizeof(from);

	if(listen(sd, 50) == -1){
		perror("Error en la operación de listen");
		exit(1);
	}
   	
	/*-----------------------------------------------------------------------
		Recepcion y aceptacion de clientes:
			1.- Se esta bloqueado hasta recibir: una nueva peticion o un mensaje de un
					cliente conectado
			2.- Si ha salido del bloqueo por una nueva conexion
					(FD_ISSET(sd, &auxBuffer))
				2.1.- Se acepta la conexion (se crea un nuevo descriptor que habra que
							almacenar)
			3.- Si no, se recibe del cliente el mensaje que haya enviado, seguidamente
					se recorren todos los sockets cliente para enviarles el mensaje junto
					con el nick de quien lo envia (nick: mensaje)
	------------------------------------------------------------------------ */
	FD_SET(sd, &buffer);
	
	while(1){
		auxBuffer = buffer;
			
		if(select(FD_SETSIZE, &auxBuffer, NULL, NULL, NULL) == -1){
      perror("Error en la funcion <select>");
      exit(1);
    }
		
		if(FD_ISSET(sd, &auxBuffer)){
			if((new_sd = accept(sd, &from, &from_len)) == -1){
				perror("Error aceptando peticiones");
				exit(1);
			}
			
			FD_SET(new_sd, &buffer);
			fd[new_sd] = 1;
			
			if(send(new_sd, "+Ok. Usuario Conectado.", 25, 0) == -1){
				perror("Error enviando datos en el servidor");
			}
		}
		else{
			for(i=0;i<FD_SETSIZE;i++){
				if(FD_ISSET(i, &auxBuffer)){
					rec_sd = i;
				}
			}
			
			//if(strncmp(cadena, "JOIN", 4) != 0){
			//	strncpy(nick[0], &cadena[5], 245);
			//}
			
			bzero(cadena, sizeof(cadena));
			if(recv(rec_sd, cadena, sizeof(cadena), 0) == -1){
				perror("Error en la operación de recv del servidor");
			}
			printf("<<<<<<%s>>>>>\n", cadena);
			if(strncmp(cadena, "quit", 4) == 0){
				fd[rec_sd] = 0;
				printf("Usuario <%d> ha abandonado el chat", rec_sd/*nick[]*/);
				FD_CLR(rec_sd, &buffer);
				close(rec_sd);
			}
			else{
				printf("\n<%d> escribio:\n", rec_sd/*nick[0]*/);
				printf("%s\n", cadena);
				for(i=0;i<FD_SETSIZE;i++){
					if(FD_ISSET(i, &buffer) && (i != rec_sd) && (i != sd)){
						/*concatenar las cadenas*/
						if(send(i, cadena, sizeof(cadena), 0) == -1){
  	          perror("Error enviando datos desde el servidor");
  	        }
  	      }
				}
			}
		}
	}
	
	close(sd);
}
