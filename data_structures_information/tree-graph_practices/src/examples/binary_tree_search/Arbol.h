#ifndef _ARBOL_H_
#define _ARBOL_H_

/**
 * @file    Arbol.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <iostream>
#include "NodoArbol.h"

using namespace std;

class Arbol
{
public:

   Arbol();
   void insertaNodo(int);
   void preOrden();
   void inOrden();
   void postOrden();

private:

   NodoArbol *raizPtr;

   void insertaNodoAyuda(NodoArbol **, int);
   void preOrdenAyuda(NodoArbol *);
   void inOrdenAyuda(NodoArbol *);
   void postOrdenAyuda(NodoArbol *);
};

Arbol::Arbol()
{
   raizPtr = 0;
}

void Arbol::insertaNodo(int valor)
{
   insertaNodoAyuda(&raizPtr, valor);
}

void Arbol::insertaNodoAyuda(NodoArbol **ptr,  int valor)
{
   if(*ptr == 0){
      *ptr = new NodoArbol(valor);
   }
   else{
      if(valor < (*ptr)->dato){
         insertaNodoAyuda(&((*ptr)->izquierdaPtr), valor);
      }
      else{
         insertaNodoAyuda(&((*ptr)->derechaPtr), valor);
      }
   }
}

void Arbol::preOrden()
{
   preOrdenAyuda(raizPtr);
}

void Arbol::preOrdenAyuda(NodoArbol *ptr)
{
   if(ptr != 0){
      cout << ptr->dato << ' ';
      preOrdenAyuda(ptr->izquierdaPtr);
      preOrdenAyuda(ptr->derechaPtr);
   }
}

void Arbol::inOrden()
{
   inOrdenAyuda( raizPtr );
}

void Arbol::inOrdenAyuda(NodoArbol *ptr)
{
   if(ptr != 0){
      inOrdenAyuda(ptr->izquierdaPtr);
      cout << ptr->dato << ' ';
      inOrdenAyuda(ptr->derechaPtr);
   }
}

void Arbol::postOrden()
{
   postOrdenAyuda(raizPtr);
}

void Arbol::postOrdenAyuda(NodoArbol *ptr)
{
   if (ptr != 0){
      postOrdenAyuda(ptr->izquierdaPtr);
      postOrdenAyuda(ptr->derechaPtr);
      cout << ptr->dato << ' ';
   }
}

#endif
