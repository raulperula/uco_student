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

template<typename TIPONODO> class Arbol;

template<typename TIPONODO> class NodoArbol
{
   friend class Arbol<TIPONODO>;
   
public:
  
   NodoArbol(const TIPONODO &d): izquierdaPtr(0), dato(d), derechaPtr(0)
   {

   }

private:

   NodoArbol<TIPONODO> *izquierdaPtr;
   TIPONODO dato;
   NodoArbol<TIPONODO> *derechaPtr;
};

#endif
