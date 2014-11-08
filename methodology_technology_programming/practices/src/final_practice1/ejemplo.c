/**
 * @file    ejemplo.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
/* -----------------------------------------------------
     Ejemplo de uso de la librería gráfica libGrafica
    ---------------------------------------------------*/

#include <stdio.h>
#include "grafica.h"


int main(){
  stColor colorFondo={255,255,255};
  stColor colorLinea={0,0,255};
  stColor colorRelleno={0,255,0};

  //Definición de los poligonos
  int triangulo[6]={400, 288, 260, 208, 260, 369};
  int cuadrado[8]={265, 125, 140, 0,14, 125, 140, 250};


  //Creamos la ventana gráfica
  abrirVentana(colorFondo,500,600);
  setColorLinea(colorLinea);
  setColorRelleno(colorRelleno);

  //Imprimimos un triangulo relleno
  rellenaPoligono(3,triangulo);  
  muestra();

  printf("Pulsa una tecla para imprimir un cuadrado\n");
  getchar();
  limpiaVentana();

  //Imprimimos un cuadrado sin rellenar
  pintaPoligono(4,cuadrado);
  muestra();
  getchar();
  return(0);
}
