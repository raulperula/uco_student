#ifndef _CASA_H_
#define _CASA_H_

/**
 * @file    casa.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

namespace values{

template <class T>

T sum(T *pointer,int nElements)
{
   int aux=0,i;
   for(i=0;i<nElements;i++)
   {
      aux=aux+pointer[i];
   }
   return aux;
}
template <class Ta>
void ordenacion(Ta *v,int nElements)
{
   int i,j,aux;
   for(i=1;i<nElements;i++)
   {
      for(j=1;j<nElements;j++)
      {
         if(v[j-1]>v[j])
         {
            aux=v[j-1];
            v[j-1]=v[j];
            v[j]=aux;
         }
      }
   }
}


};
#endif
