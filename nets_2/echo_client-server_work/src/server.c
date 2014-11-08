/**
 * @file    server.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
// Programar en lenguaje C, una aplicación cliente/servidor concurrente que
// implemente un servicio que encripte y desencripte un archivo de texto que
// le envíe el cliente.

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT		6544
#define SERVER_ADDRESS	"127.0.0.1"
#define MAXMESG			2048

void fserver(int, struct sockaddr *, int);
void cifrar(char [], char [], int);
void descifrar(char [], char [], int);

int main(int argc, char *argv[])
{
    int socketfd;
    struct sockaddr_in server_addr, client_addr;
    char *pname;

    // nombre del proceso
    pname = argv[0];

    // abrir socket UDP
    if((socketfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
		perror("servidor: no se puede abrir el datagrama");
	}

    // unirse a la direccion local para permitir al cliente enviar
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0){
		perror("servidor: no se puede unir a la direccion local");
	}

	// llamada a la funcion cifrado/descifrado
    fserver(socketfd, (struct sockaddr *) &client_addr, sizeof (client_addr));
    
    return 0;
}

void fserver(int sockfd, struct sockaddr * pcli_addr, int maxclilen)
{
    int tam, clilen;
    char mesg[MAXMESG];
    char msg_c[MAXMESG], msg_d[MAXMESG];

    for(;;){
		clilen = maxclilen;
		
		// recepcion del mensaje del cliente
		tam = recvfrom(sockfd, mesg, MAXMESG, 0, pcli_addr, (socklen_t *) &clilen);
		if(tam < 0){
			perror("fserver: recvfrom error");
		}
		mesg[tam] = '\0';
		
		// se muestra el mensaje original
		fprintf(stdout, "server:\n   mensaje original: %s", mesg);
		
		// cifrado del mensaje
		cifrar(mesg, &msg_c, tam);
		fprintf(stdout, "server:\n   mensaje cifrado: %s", msg_c);
		
		// envio del mensaje al cliente
		if(sendto(sockfd, msg_c, tam, 0, pcli_addr, clilen) != tam){
			perror("fserver: sendto cifrado error");
		}
		
		// descifrado del mensaje
		descifrar(msg_c, &msg_d, tam);
		fprintf(stdout, "server:\n   mensaje descifrado: %s", msg_d);

		// envio del mensaje al cliente
		if(sendto(sockfd, mesg, tam, 0, pcli_addr, clilen) != tam){
			perror("fserver: sendto descifrado error");
		}
    }
}

void cifrar(char mesg[], char msg_c[], int size)
{
	int i;
	
	for(i=0;i<size;i++){
		msg_c[i] = mesg[i]+3;
	}
}

void descifrar(char msg_c[], char msg_d[], int size)
{
	int i;
	
	for(i=0;i<size;i++){
		msg_d[i] = msg_c[i]-3;
	}
}
