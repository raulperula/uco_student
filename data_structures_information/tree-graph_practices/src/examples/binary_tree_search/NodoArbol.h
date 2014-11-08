#ifndef _NODOARBOL_H_
#define _NODOARBOL_H_

/**
 * @file    NodoArbol.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

class NodoArbol
{
   friend class Arbol;

public:
   NodoArbol(const int &d): izquierdaPtr(0), dato(d), derechaPtr(0)
   {

   }

private:

   NodoArbol *izquierdaPtr;
   int dato;
   NodoArbol *derechaPtr;
};

#endif
