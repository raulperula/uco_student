/**
 * @file    cesar_dec_fb.c
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
  char codificado[10000];  /*texto que se va a decodificar*/
  char txtplano[10000];    /*texto decodificado*/
  char abc[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";  /*alfabeto usado para la decodificacion*/
  int i,j;       /*contadores*/
  int k;         /*clave secreta*/
  int longitud;  /*numero de caracteres del texto codificado*/
  int codif,opcion;
  int longclave; /*indica el numero de caracteres de la clave (27)*/

  printf("Decodificador para cifrado del Cesar \n\n");
  printf("(1) Cargar el mensaje cifrado desde el archivo cod_cesar.txt \n");
  printf("(2) Introducir el codigo manualmente \nOpcion: ");
  scanf("%d",&opcion);
   
  if(opcion == 2){
  printf("Introduce el mensaje a decodificar: ");
  scanf("%s",codificado);
  }
  
  else{
  f = fopen("cod_cesar.txt","r");
  fgets(codificado,1000,f);
  fclose(f);
  }
  
  longitud = strlen(codificado);
  longclave = strlen(abc);
  g = fopen("dec_cesar_fb.txt","w");
  fprintf(g,"Mensaje codificado = %s\nCaracteres = %d\n\n",codificado,longitud);
  
  for(k=0;k<longclave;k++){
    for(i=0;i<longitud;i++){
      codif = 0;
      j = 0;
      while(codif == 0){
        if(codificado[i] == abc[j]){
           txtplano[i] = abc[(j-k+longclave)%longclave];
           codif = 1;
        }
        else j++;  
      } 
    }
  txtplano[i] = '\0';  
  fprintf(g,"Clave k = %d\nMensaje = %s\n\n",k,txtplano,strlen(txtplano));
  }
  
  fclose(g);
  printf("descifrado completo, pulsa intro \n");
  getchar();
  getchar();
}
