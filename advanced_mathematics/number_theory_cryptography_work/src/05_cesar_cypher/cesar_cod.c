/**
 * @file    cesar_cod.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */
 
#include <stdio.h>

int
main(void)
{
 
  FILE *f,*g;
  char abc[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char mensaje[10000];
  int longitud;  /*numero de caracteres del mensaje*/
  int clave; /*clave K*/
  int codif;
  int i,j;
  int longclave; /*indica el numero de caracteres de la clave (27)*/

  printf("Este programa codifica un mensaje con el cifrado del Cesar. \n");
  printf("Introduce el mensaje: \n");
  gets(mensaje);

  printf("Introduce clave de codificacion k: ");
  scanf("%d",&clave);
  longitud = strlen(mensaje);
  longclave = strlen(abc);
  f = fopen("info.txt","w");
  g = fopen("cod_cesar.txt","w");

  fprintf(f,"Texto plano: \n%s \n\nClave k = %d \n\nNumero de caracteres: %d \n\n",mensaje,clave,longitud);

  for(i=0;i<longitud;i++){
    codif = 0;
    j = 0;
    while(codif == 0){
      if (mensaje[i] == abc[j]){
         mensaje[i] = abc[(j+clave)%longclave];
         codif = 1;
      }
      else j++;  
    } 
  }

  fprintf(f,"Mensaje codificado: \n%s \n\nLongitud: %d",mensaje,strlen(mensaje));
  fprintf(g,"%s",mensaje);
  printf("Mensaje codificado, pulsa intro");
  
  getchar();
  getchar();
  
  fclose(g);
  fclose(f);
  
  return 0;
}
