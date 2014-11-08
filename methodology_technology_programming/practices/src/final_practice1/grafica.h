#ifndef GRAFICA_H
#define GRAFICA_H

/**
 * @file    grafica.h
 * @brief   Header file. Prototipos de las funciones para pintar figuras por pantalla.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */


/*---------------------------------------------------
  Estructura que define las componentes de color RGB
  Cada componente toma un valor entre 0 y 255
---------------------------------------------------*/
struct color{
   int rojo;
   int verde;
   int azul;
};
typedef struct color stColor;


/*--------------------------------------------------
  Configura los dispositivos para poder pintar en la
  pantalla

  Se le pasa: colorFondo --> las componentes RGB para 
                             el color del fondo
              alto -> alto de la ventana grafica
              ancho -> ancho de la ventana grafica

  Devuelve: nada

  Utiliza: funciones de graphics.h
  --------------------------------------------------*/
void abrirVentana(stColor colorFondo, int alto, int ancho);



/* -------------------------------------------------------
   Cambia el color de fondo por el que se indica

   Se le pasa: color -> estructura con las componentes RGB
                       del color que se quiere poner

   Devuelve: nada

   Utiliza: nada
   ----------------------------------------------------------*/
void setColorFondo(stColor color);


/* -------------------------------------------------------
   Cambia el color utilizado para dibujar las líneas

   Se le pasa: color -> estructura con las componentes RGB
                       del color que se quiere poner

   Devuelve: nada

   Utiliza: nada
   ----------------------------------------------------------*/
void setColorLinea(stColor color);

/* -------------------------------------------------------
   Cambia el color utilizado para rellenar las figuras

   Se le pasa: color -> estructura con las componentes RGB
                       del color que se quiere poner

   Devuelve: nada

   Utiliza: nada
   ----------------------------------------------------------*/
void setColorRelleno(stColor color);

/* ----------------------------------------------------------
    Pinta un polígono de n lados dados sus puntos
	
    Se le pasa: lados -> numero de lados del polígono
                puntos -> vector de 2*lados elementos que
                          almacena las coordenadas (x,y) de los
                          puntos del polígono
    
    Devuelve: nada

    Utiliza: pintaLinea (módulo graphics)
   -----------------------------------------------------------*/
void pintaPoligono(int lados, int * puntos);


/* ------------------------------------------------------------
    Pinta un polígono relleno

    Se le pasa: lados -> numero de lados del poligono
                puntos -> vector de 2*lados elementos que
                          almacena las coordenadas (x,y) de los
                          puntos del polígono

    Devuelve: nada

    Utiliza: pintaPoligono
   ----------------------------------------------------------*/
void rellenaPoligono(int lados, int * puntos);


/* ---------------------------------------------------------
   Muestra la imagen en la pantalla

   Se le pasa: nada

   Devuelve: nada

   Utiliza: LSIX_Sincroniza (módulo LSIX)
   ----------------------------------------------------------*/
void muestra();

/* ----------------------------------------------------------
   Cierra la ventana gráfica

   Se le pasa: nada

   Devuelve: nada

   Utiliza: LSIX_CerrarVentana (módulo LSIX)
   ---------------------------------------------------------*/
void cerrarVentana();

/* -----------------------------------------------------------
   Limpia la ventana gráfica

   Se le pasa: nada

   Devuelve: nada

   Utiliza: clearDevice (modulo graphics)
   -----------------------------------------------------------*/
void limpiaVentana();




#endif 
