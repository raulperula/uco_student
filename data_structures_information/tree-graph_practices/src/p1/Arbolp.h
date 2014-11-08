#ifndef _ARBOLP_H_
#define _ARBOLP_H_

/**
 * @file    Arbolp.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <iostream>
#include "NodoArbolp.h"

using namespace std;

template<typename TIPONODO> class Arbol
{

public:

   Arbol();
   void insertaNodo(TIPONODO);
   void preOrden();
   void inOrden();
   void postOrden();
   void busquedaSubarbol(TIPONODO);

private:

   NodoArbol<TIPONODO> *raizPtr;

   void insertaNodoAyuda(NodoArbol<TIPONODO> **, TIPONODO);
   void preOrdenAyuda(NodoArbol<TIPONODO> *);
   void inOrdenAyuda(NodoArbol<TIPONODO> *);
   void postOrdenAyuda(NodoArbol<TIPONODO> *);
}; 

template<typename TIPONODO>
Arbol<TIPONODO>::Arbol()
{ 
   raizPtr = 0;
} 

template<typename TIPONODO>
void Arbol<TIPONODO>::insertaNodo(TIPONODO valor)
{ 
   insertaNodoAyuda(&raizPtr, valor);
} 

template<typename TIPONODO>
void Arbol<TIPONODO>::insertaNodoAyuda(NodoArbol<TIPONODO> **ptr, TIPONODO valor)
{
   if(*ptr == 0){
      *ptr = new NodoArbol<TIPONODO>(valor);
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

template<typename TIPONODO>
void Arbol<TIPONODO>::preOrden()
{ 
   preOrdenAyuda(raizPtr);
}

template<typename TIPONODO>
void Arbol<TIPONODO>::preOrdenAyuda(NodoArbol<TIPONODO> *ptr)
{
   if(ptr != 0){
      cout << ptr->dato << ' ';
      preOrdenAyuda(ptr->izquierdaPtr);
      preOrdenAyuda(ptr->derechaPtr);
   }
}

template<typename TIPONODO>
void Arbol<TIPONODO>::inOrden()
{ 
   inOrdenAyuda(raizPtr);
}

template<typename TIPONODO>
void Arbol<TIPONODO>::inOrdenAyuda(NodoArbol<TIPONODO> *ptr)
{
   if(ptr != 0){
      inOrdenAyuda(ptr->izquierdaPtr);
      cout << ptr->dato << ' ';
      inOrdenAyuda(ptr->derechaPtr);
   }
}

template<typename TIPONODO>
void Arbol<TIPONODO>::postOrden()
{ 
   postOrdenAyuda(raizPtr);
}

template<typename TIPONODO>
void Arbol<TIPONODO>::postOrdenAyuda(NodoArbol<TIPONODO> *ptr)
{
   if(ptr != 0){
      postOrdenAyuda(ptr->izquierdaPtr);
      postOrdenAyuda(ptr->derechaPtr);
      cout << ptr->dato << ' ';
   }
}

template<typename TIPONODO>
void Arbol<TIPONODO>::busquedaSubarbol(TIPONODO valor)
{ 
   NodoArbol<TIPONODO> *auxRaiz;
   auxRaiz = raizPtr;
   bool encontrado = false;
   
   while((encontrado == false) && (auxRaiz != NULL)){
      if((auxRaiz->dato) == valor){
         encontrado = true;
         cout << "El subarbol es:" << endl;
         inOrdenAyuda(auxRaiz);
         cout << endl;
      }
      else if((auxRaiz->dato) > valor){
         auxRaiz = auxRaiz->izquierdaPtr;
      }
      else{
         auxRaiz = auxRaiz->derechaPtr;
      }
   }
   
   if(encontrado == false){
      cout << "\nEl nodo no se encuentra en el arbol" << endl;
   }
}

#endif
