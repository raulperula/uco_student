/**
 * @file    client.c
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
#include <string.h>

#define SERVER_PORT		6544
#define SERVER_ADDRESS	"127.0.0.1"
#define MAXLINE			512

int main(int argc, char *argv[])
{
    void fclient(int, struct sockaddr *, int, char *);

    int socketfd;
    struct sockaddr_in server_addr, cli_addr;
    char *pname, *fname;

	if(argc != 2){
		perror("Debe escribir:\n./client fichero_tecto.txt");
		exit(0);
	}
	
    // nombre del proceso
    pname = argv[0];
    // nombre del fichero texto
    fname = argv[1];

    // inicializar el server_addr con la direccion del servidor
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
    server_addr.sin_port = htons(SERVER_PORT);

    // abrir socket UDP
    if((socketfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
		perror("client: Can't open datagram socket");
	}

    // unirse a la direccion local
    bzero((char *) &cli_addr, sizeof(cli_addr));
    cli_addr.sin_family = AF_INET;
    cli_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    cli_addr.sin_port = htons(0);

    if(bind(socketfd, (struct sockaddr *) &cli_addr,sizeof(cli_addr)) < 0){
		perror("server: can't bind local address");
	}

    // envio de la entrada
    fclient(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr), fname);

    close(socketfd);

    return 0;
}

void fclient(int socketfd, struct sockaddr *pserv_addr, int servlen, char *fname)
{
    int tam;
    char sendline[MAXLINE], recvline[MAXLINE+1];
    FILE * ftext, * fcipher, * fdecipher;

	// se lee el fichero de texto
	ftext = fopen(fname, "r");
	fgets(sendline,MAXLINE,ftext);
	tam = strlen(sendline);
	
	// se muestra el mensaje original
	printf("mensaje original: %s\n",sendline);
	
	// se envia al servidor el mensaje original
	if(sendto(socketfd, sendline, tam, 0, pserv_addr, servlen) != tam){
		perror("fclient: sendto mensaje error");
	}

	// lectura del socket servidor, mensaje cifrado
	tam = recvfrom(socketfd, recvline, MAXLINE, 0, (struct sockaddr *) 0, (socklen_t *) 0);
	if(tam < 0){
		perror("fclient: recvfrom error");
	}
	recvline[tam-1] = '\0';
	
	// se muestra el mensaje cifrado
	fprintf(stdout, "client:\n   mensaje cifrado: %s\n\n", recvline);
	
	// se escribe el mensaje cifrado en un fichero
	fcipher = fopen("cifrado.txt", "w");
	fprintf(fcipher, "%s", recvline);
	
	// lectura del socket servidor, mensaje descifrado
	tam = recvfrom(socketfd, recvline, MAXLINE, 0, (struct sockaddr *) 0, (socklen_t *) 0);
	if(tam < 0){
		perror("fclient: recvfrom error");
	}
	recvline[tam-1] = '\0';
	
	// se muestra el mensaje descifrado
	fprintf(stdout, "client:\n   mensaje descifrado: %s\n\n", recvline);
	
	// se escribe el mensaje descifrado en un fichero
	fdecipher = fopen("descifrado.txt", "w");
	fprintf(fdecipher, "%s", recvline);
	
	fclose(ftext);
	fclose(fcipher);
	fclose(fdecipher);
}
