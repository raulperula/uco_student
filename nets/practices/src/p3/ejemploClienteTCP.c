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
		Pasos que se deben contemplar:
			- El cliente se identifica con el usuario y la clave
			- Se le muestra un menu principal con las siguientes opciones:
				+ Ver los mensajes del servidor
				+ Leer un mensaje
				+ Borrar un mensaje
				+ Salir
	-----------------------------------------------------*/
    
	/*---------------------------------------------------- 
		Descriptor del socket y buffer de datos                
	-----------------------------------------------------*/
	int i, sd, opcion, salir = 0;
	char cadena[25], log[25] = "user ", pas[25] = "pass ", *password, aux[4];
	char fin[] = "\r\n.\r\n", auxFin[10];
	struct sockaddr_in sockname;
	char buffer[1000];
	socklen_t len_sockname;
	struct hostent *host;
	
	host = gethostbyname("lucano110.uco.es");
	
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
	sockname.sin_port = htons(110);
	sockname.sin_addr = * (struct in_addr *) host->h_addr;
  
  /* ------------------------------------------------------------------
		Se solicita la conexión con el servidor
	-------------------------------------------------------------------*/
	len_sockname = sizeof(sockname);
	
	if(connect(sd, (struct sockaddr *) &sockname, len_sockname) == -1){
		perror ("Error de conexión");
		exit(1);
	}
	
	bzero(buffer, sizeof(buffer));
	if(recv(sd, buffer, sizeof(buffer), 0) == -1){
		perror("Error en la operación de recv del servidor");
	}
	printf("%s", buffer);

	printf("Login: ");
  scanf("%s", cadena);
  strcat(log, cadena);
  strcat(log, "\n");
  
  /* Envio del login */
  if(send(sd, log, strlen(log), 0) == -1){
		perror("Error enviando datos");
	}
	/* Recepcion del +OK */
	bzero(buffer, sizeof(buffer));
	if(recv(sd, buffer, sizeof(buffer), 0) == -1){
		perror("Error en la operación de recv del servidor");
	}
	printf("%s", buffer);
  
  bzero(cadena, sizeof(cadena));
  password = getpass("Pass: ");
  strcat(pas, password);
	strcat(pas, "\n");
  
  /* Envio del password */
  if(send(sd, pas, strlen(pas), 0) == -1){
		perror("Error enviando datos");
	}
	/* Recepcion del +OK */
	bzero(buffer, sizeof(buffer));
	if(recv(sd, buffer, sizeof(buffer), 0) == -1){
		perror("Error en la operación de recv del servidor");
	}
	printf("%s", buffer);
  
  do{
  
	  printf("\nMenu:\n");
	  printf("  Opcion 1: Ver los mensajes\n");
	  printf("  Opcion 2: Leer un mensaje\n");
	  printf("  Opcion 3: Borrar un mensaje\n");
	  printf("  Opcion 4: Salir\n");
	  printf("\nOpcion: ");
	  scanf("%d", &opcion);
	  
	  switch(opcion){
	  	case 1: 
	  		bzero(cadena, sizeof(cadena));
			  strcpy(cadena, "LIST\n");
			  
			  if(send(sd, cadena, strlen(cadena), 0) == -1){
					perror("Error enviando datos");
				}
				/* Recepcion */
				do{
				
					bzero(buffer, sizeof(buffer));
					if(recv(sd, buffer, sizeof(buffer), 0) == -1){
						perror("Error en la operación de recv del servidor");
					}
					printf("%s", buffer);
					bzero(auxFin, sizeof(auxFin));
					strcpy(auxFin, &buffer[strlen(buffer)-5]);
				}while(strcmp(fin, auxFin) != 0);
	  		
	  		break;
	  		
	  	case 2: 
	  		bzero(cadena, sizeof(cadena));
	  		bzero(aux, sizeof(aux));
	  		
			  printf("Numero: ");
			  scanf("%s", aux);
			  strcpy(cadena, "RETR ");
			  strcat(cadena, aux);
			  strcat(cadena, "\n");
			  
			  if(send(sd, cadena, strlen(cadena), 0) == -1){
					perror("Error enviando datos");
				}
				/* Recepcion */
				do{
				
					bzero(buffer, sizeof(buffer));
					if(recv(sd, buffer, sizeof(buffer), 0) == -1){
						perror("Error en la operación de recv del servidor");
					}
					printf("%s", buffer);
					bzero(auxFin, sizeof(auxFin));
					strcpy(auxFin, &buffer[strlen(buffer)-5]);
				}while(strcmp(fin, auxFin) != 0);
	  		
	  		break;
	  		
	  	case 3: 
	  		bzero(cadena, sizeof(cadena));
	  		bzero(aux, sizeof(aux));
	  		
			  printf("Numero: ");
			  scanf("%s", aux);
			  strcpy(cadena, "DELE ");
			  strcat(cadena, aux);
			  strcat(cadena, "\n");
			  
			  if(send(sd, cadena, strlen(cadena), 0) == -1){
					perror("Error enviando datos");
				}
				/* Recepcion */
				bzero(buffer, sizeof(buffer));
				if(recv(sd, buffer, sizeof(buffer), 0) == -1){
					perror("Error en la operación de recv del servidor");
				}
				printf("%s", buffer);
	  	
	  		break;
	  		
	  	case 4: 
	  		bzero(cadena, sizeof(cadena));
			  strcpy(cadena, "QUIT\n");
			  
			  if(send(sd, cadena, strlen(cadena), 0) == -1){
					perror("Error enviando datos");
				}
				/* Recepcion */
				bzero(buffer, sizeof(buffer));
				if(recv(sd, buffer, sizeof(buffer), 0) == -1){
					perror("Error en la operación de recv del servidor");
				}
				printf("%s", buffer);
	  		
	  		salir = 1;
	  		break;
	  		
	  	default: 
			  printf("\nOpcion incorrecta, pulse ENTER para continuar...\n");
	  		getchar();
	  		break;
	  }
			
	}while(salir == 0);
		
	close(sd);
}
		
