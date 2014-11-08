/**
 * @file    t01ej02a.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include <stdio.h>

int
main(void)
{

  double a1,b1,c1,d1;  /*Coordenadas del plano 1*/
  double a2,b2,c2,d2;  /*Coordenadas del plano 2*/


  /*Se piden todos los coeficientes del plano 1*/
  printf("Escribe los coeficientes del primer plano Ax+By+Cz+D\n");
  scanf("%lf",&a1);
  scanf("%lf",&b1);
  scanf("%lf",&c1);
  scanf("%lf",&d1);
  
  /*Se piden todos los coeficientes del plano 2*/
  printf("Escribe los coeficientes del segundo plano Ax+By+Cz+D\n");
  scanf("%lf",&a2);
  scanf("%lf",&b2);
  scanf("%lf",&c2);
  scanf("%lf",&d2);
  
  /*Se comprueba la condicion de planos coincidentes*/
  if ( ((a1/a2) == (b1/b2)) && 
       ((a1/a2) == (c1/c2)) && 
       ((a1/a2) == (d1/d2))
     ) 
     
    printf("Los planos son coincidentes\n");
    
  else if ( ((a1/a2) == (b1/b2)) && 
            ((a1/a2) == (c1/c2)) && 
            ((b1/b2) == (c1/c2)) &&
            ((a1/a2) != (d1/d2)) 
	  )
	    
    /*Se comprueba la condicion de planos paralelos*/
    printf("Los planos son paralelos\n");
    
  else if ( (a1*a2)+(b1*b2)+(c1*c2) == 0)
  
    /*Se comprueba la condicion de planos perpendiculares*/
    printf("Los planos son perpendiculares\n");
    
  else{
  
    /*Si no se cumple ninguna de las condiciones anteriores, los*/
    /*planos han de ser secantes*/
    printf("Los planos son secantes\n");
  }
  
  return 0;
}


