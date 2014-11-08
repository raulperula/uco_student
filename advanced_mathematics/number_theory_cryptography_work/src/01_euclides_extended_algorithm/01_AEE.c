/**
 * @file    01_AEE.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <stdio.h>
#define N 50

int
main(void)
{
  int matriz[N][3];  /*matriz donde se haran las operaciones*/
  int i = 2;  /*variable que controla los terminos de la matriz*/
  int cociente;  /*almacena los cocientes parciales*/             
  int j,k;  /*variables contador*/

  /*inicilizamos la matriz*/
  for(j=0;j<N;j++){
    for(k=0;k<3;k++){
    matriz[j][k] = 0;
    }
  }
  matriz[0][1] = 1;
  matriz[1][2] = 1;

  printf("Este programa calcula el MCD de dos numeros y la ");
  printf("identidad de Bezout. \n");
  printf("Introduce dos numeros: \n");
  scanf("%d",&matriz[0][0]);
  scanf("%d",&matriz[1][0]);        

  while (1) {
    cociente = (matriz[i-2][0] / matriz[i-1][0]);
    matriz[i][0] = (matriz[i-2][0] % matriz[i-1][0]);
    matriz[i][1] = (matriz[i-2][1] - (cociente * matriz[i-1][1]));
    matriz[i][2] = (matriz[i-2][2] - (cociente * matriz[i-1][2]));

    if (matriz[i][0] == 0) break; /*cuando el resto sea 0 nos salimos*/
    i++;
  }

  printf("\n");
  printf("El MCD de %d y %d es %d \n\n", matriz[0][0], matriz[1][0], 
                                       matriz[i-1][0]);
  printf("Los coeficientes de la Identidad de Bezout son: \n\n");
  printf("x0 = %d \n",matriz[i-1][1]);
  printf("y0 = %d \n\n",matriz[i-1][2]);
  printf("%d*(%d) + %d*(%d) = %d", matriz[0][0], matriz[i-1][1], matriz[1][0],
                                  matriz[i-1][2], matriz[i-1][0]);
  getchar();
  getchar();
}
