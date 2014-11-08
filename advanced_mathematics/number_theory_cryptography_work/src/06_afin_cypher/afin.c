/**
 * @file    afin.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */
 
#include <stdio.h>
#include <string.h>
#define N 100

int
main(void)
{
  int a,b;   //los dos numeros del criptosistema afin introducidos por el usuario 
  int a_inv; //inverso de a mod 28         
  int D;
  char clave[]="ABCDEFGHIJKLMNnOPQRSTUVWXYZ*";
  char mensaje[1000];
  char decodificado[1000];
  int codif;
 
  //Variables para obtener el inversdo de A usando AEE 
  int matriz[N][3];  /*matriz donde se haran las operaciones*/
  int i = 2;  /*variable que controla los terminos de la matriz*/
  int cociente;  /*almacena los cocientes parciales*/             
  int j,k;  /*variables contador*/
  
  
  printf("Introduce los dos numeros del criptosistema afin: \n");
  scanf("%d",&a);
  scanf("%d",&b);
  printf("Introduce el mensaje a decodificar: \n");
  scanf("%s",mensaje);
  
  //averiguamos el inverso de a mod27
  for(j=0;j<N;j++){
    for(k=0;k<3;k++){
    matriz[j][k] = 0;
    }
  }
  matriz[0][1] = 1;
  matriz[1][2] = 1; 
  matriz[0][0] = a;
  matriz[1][0] = 28;        

  while (1) {
    cociente = (matriz[i-2][0] / matriz[i-1][0]);
    matriz[i][0] = (matriz[i-2][0] % matriz[i-1][0]);
    matriz[i][1] = (matriz[i-2][1] - (cociente * matriz[i-1][1]));
    matriz[i][2] = (matriz[i-2][2] - (cociente * matriz[i-1][2]));

    if (matriz[i][0] == 0) break; /*cuando el resto sea 0 nos salimos*/
    i++;
  }

  //decodificamos el mensaje
  printf("El inverso de %d modulo 28 es %d\n",a,matriz[i-1][1]);
  printf("Comprobamos: %d * %d = %d\n",a,matriz[i-1][1],matriz[i-1][1]*a);  
  a_inv = (matriz[i-1][1]%28);
  for(i=0;i<strlen(mensaje);i++){
    codif = 0;
    j = 0;
    while(codif==0){
      if(mensaje[i] == clave[j]){
        decodificado[i] = clave[((a_inv*(j-b))+2800)%28];
        codif = 1;
      }
      j++; 
    }
  }
  
  //finalizamos la cadena
  decodificado[i] = '\0'; 
  
  //mostramos el mensaje
  printf("Mensaje decodificado: \n%s",decodificado);                        
  getchar();
  getchar();          
}
