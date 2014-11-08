#ifndef _PILA_H_
#define _PILA_H_

/**
 * @file    pila.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <vector>
#include <pila.h>

namespace miscontenedores{
    class Pila: public vector{
        public:
            Pila();

            Pila(const Pila P){
                for(int i=0;i<capacity()-1;i++) *this[i]=P[i];
            }

            template<class T>
            void apila(T){
                int pos=capacity-tamano();
                *this[pos]=T;
                _tamano++;
            }

            template<class T>
            T desapila(){
                int pos=capacity-tamano();

            }
    }
}

#endif
