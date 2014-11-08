/**
 * @file    t02ej02.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include <stdio.h>


int espar(int num);
int esprimo(int i);
int goldbach(int i, int num);




int
main(void)
{
  int num;        /*numero que se va a descomponer*/
  int i = 1;      /*variable contador*/
  

  printf("Introduce un numero par \n");
  scanf("%d",&num);

  if (espar(num)) {
     
    printf("El numero %d no es par \n",num);
  }
  
  else {
       
    while (i < num) {
      
      if (esprimo(i)) {
         
        goldbach(i, num);
      }
      
    i++;
    }
  
  }
  
system("PAUSE");           
return 0;
}









/*funcion que determina si num es o no par*/
int espar(num)
{
int par = 1;     /*variable que valdra 1 si num es impar o 0 si es par*/

if (num%2 == 0) {
   par = 0;
}

return par;          
}




/*funcion que nos dice si un numero es o no primo*/
int esprimo(i)
{
  int primo = 1;  /*variable que devolvera 1 si num es primo o 0 si no lo es*/
  int a = 2;      /*variable contador*/   
  
  while (a < i && primo == 1) {
   
    if (i%a == 0) {
      primo = 0;
    }
    
    a++;
  }

  return primo;
}




/*funcion que verifica si es posible descomponer num usando i si i es primo*/
int goldbach(i, num)
{
  int desc1;      /*primer sumando de la conj goldbach*/
  int desc2;      /*segundo sumando de la conj goldbach*/
  
  desc1 = i;
  i = num - i;
  
  if (esprimo(i)) {
     desc2 = i;
     printf("%d = %d + %d \n",num,desc1,desc2);
  }
  
  i = desc1;
  return 0;
}
