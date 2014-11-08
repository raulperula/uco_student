/**
 * @file    colas.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include "colas.h"

struct cola *nuevoElemento()
{
 return ((struct cola *)malloc(sizeof(struct cola)));
}

void insertarCola(struct cola **cabeza, int n)
{
 struct cola *nuevo = NULL;
 nuevo = nuevoElemento();

 nuevo->sig = *cabeza;
 nuevo->n = n;
 *cabeza = nuevo;
}

int extraerCola(struct cola **cabeza)
{
 struct cola *penultimo = NULL;
 int aux;

 if (((*cabeza)->sig) == NULL) /* Hay un solo elemento */
  {
   aux = (*cabeza)->n;
   free(*cabeza);
   *cabeza = NULL;
   return aux;
  }
 else
  {
   penultimo = *cabeza;
   while(penultimo->sig->sig != NULL)
    penultimo = penultimo->sig;

   aux = penultimo->sig->n;
   free(penultimo->sig); /* se borra el ultimo*/
   penultimo->sig = NULL;
   return aux;
  }
}

int colaVacia(struct cola *cabeza)
{
 if (cabeza == NULL)
  return 1;
 return 0;
}
