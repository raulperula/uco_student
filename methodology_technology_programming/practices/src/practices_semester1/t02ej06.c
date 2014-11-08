/**
 * @file    t02ej06.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include <stdio.h>


int presentar_menu (void);

int
main(void)
{
  int opcion;  /*recoje la opcion elegida por el usuario*/
  
  presentar_menu();
  scanf("%d",&opcion);  
  
  switch (opcion) {
    
    case 1:
    printf("Ha elegido la opcion 1 \n");
    break;
    
    case 2:
    printf("Ha elegido la opcion 2 \n");
    break;
    
    case 3:
    printf("Ha elegido la opcion 3 \n");
    break;
    
    case 4:
    printf("Ha elegido la opcion 4 \n");
    break;
    
    default:
    printf("La opcion debe ser 1, 2, 3 o 4 \n");
    system("PAUSE");
    main();
    break;
  }
  
  system("PAUSE");
 
  return 0;
}

int presentar_menu(void)
{  
  system("CLS");        
  printf("Menu Principal \n \n");
  printf("(1) Comprobar si un numero es primo \n");
  printf("(2) Descomponer un numero impar en la suma de dos numeros primos \n");
  printf("(3) Calcular factorial mas exacto o mas proximo de un numero \n");
  printf("(4) Comprobar si un numero es o no capicua \n \n");
  printf("Elige una opcion: ");   
}

