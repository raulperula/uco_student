/**
 * @file    vernam.c
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
#define MAX 1000

int letra_a_numero(char letra, char caracteres[64]);
void descomponer(int numero, int vector[6]);
int suma_xor(int binariomsj[6], int binarioclv[6], int binariotxt[6]);
int base2tobase10(int binariotxt[6]);

int
main(void)
{
  char caracteres[] = "#ABCDEFGHIJKLMNnOPQRSTUVWXYZÇ0123456789@(){}<>=+_*/%&ºª,;.:¿?¡!'";
  char mensaje[MAX];    //almecena el mensaje para decodificar
  char clave[MAX];      //almacena la clave de deCodificado
  char textoplano[MAX]; //almacena el mensaje decodificado
  char letramsj;        //almacena una letra del mensaje temporalmente
  char letraclv;        //almacena una letra de la clave temporalmente
  int aux1;             //almacena el numero del caracter n del mensaje
  int aux2;             //almacena el numero del caracter n de la clave 
  int aux3;             //almacena el numero del caracter n del mensaje decodificado
  int binariomsj[6];    //almacena la descomposicion binaria del caracter n del mensaje
  int binarioclv[6];    //almacena la descomposicion binaria del caracter n de la clave
  int binariotxt[6];    //almacena la descomposicion binaria del caracter n del mensaje decodificado
  int i,j;              //contadores

  printf("Cifrado de Vernam\nIntroduce el mensaje codificado:\n");
  scanf("%s",mensaje);
  printf("Introduce la clave de descifrado:\n");          
  scanf("%s",clave);
  
  
  for(i=0;i<strlen(mensaje);i++){
    //asignamos a dos char el caracter n del mensaje y de la clave
    letramsj = mensaje[i];
    letraclv = clave[i];
    //pasamos el caracter n de la clave y del mensaje a forma numerica
    aux1 = letra_a_numero(letramsj,caracteres);
    aux2 = letra_a_numero(letraclv,caracteres);
    //descomponemos aux1 y aux2 en su forma binaria
    descomponer(aux1,binariomsj);
    descomponer(aux2,binarioclv);
    //hacemos la suma xor de binariomsj y binarioclv
    suma_xor(binariomsj,binarioclv,binariotxt);
    //convertimos binariotxt en numero decimal
    aux3 = base2tobase10(binariotxt);
    printf("%d ",aux3);
    //convertimos el numero obtenido en su caracter correspondiente y 
    //lo almacenamos en un vector
    textoplano[i] = caracteres[aux3];
  }
  
  printf("Mensaje decodificado:\n");
  for(i=0;i<strlen(mensaje);i++)
    printf("%c",textoplano[i]);
  printf("\n");
  
  getchar();
  getchar();
  return 0;
}



int
letra_a_numero(char letra, char caracteres[64])
{
  int i;
  int numero;
                    
  for(i=0;i<64;i++){
    if(letra == caracteres[i]){
      numero = i;
      break;
    }
  }
  return numero;                
}


void 
descomponer(int numero, int vector[6])
{
  int k; 
                  
  for(k=5;k>=0;k--){
    vector[k]=numero%2;
    numero=numero/2;
  }
}


int 
suma_xor(int binariomsj[6], int binarioclv[6], int binariotxt[6])
{
  int i;
  
  for(i=0;i<6;i++)
    binariotxt[i] = ((binariomsj[i]+binarioclv[i])%2);
}


int
base2tobase10(int binariotxt[6])
{
  int numero = 0;
  int i;
  int j = 5;

  for(i=0;i<6;i++){
    numero = numero+(binariotxt[i]*(pow(2,j)));    
    j--;
  }
  return numero;
}
