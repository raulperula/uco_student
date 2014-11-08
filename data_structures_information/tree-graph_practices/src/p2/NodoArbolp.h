#ifndef _NODOARBOLP_H_
#define _NODOARBOLP_H_

/**
 * @file    NodoArbolp.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

class Arbol;

class NodoArbol
{
   friend class Arbol;
   
public:
  
   NodoArbol(const int &d): izquierdaPtr(NULL), dato(d), derechaPtr(NULL)
   {

   }

private:

   NodoArbol *izquierdaPtr;
   int dato;
   NodoArbol *derechaPtr;
};

#endif
