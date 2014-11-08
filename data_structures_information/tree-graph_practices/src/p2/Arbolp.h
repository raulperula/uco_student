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

class Arbol
{

public:

   Arbol();
   void insertaNodo(int);
   
   int busquedaNodo(int);
   
   void borrarNodo(int);
   void cuentaNodos(NodoArbol *, int *, int *);
   
   int mostrarHermano(int);
   void mostrarHijos(int);
   int mostrarNietos(int);
   int mostrarPrimos(int);
   int mostrarSobrinos(int);
   void buscaPadre(NodoArbol **, NodoArbol **, int);
   
   int alturaNodo(int);
   
   void completoNodo(int);
   
   void inOrden();

private:

   NodoArbol *raizPtr;

   void insertaNodoAyuda(NodoArbol **, int);
   void inOrdenAyuda(NodoArbol *);
   int completoNodoAyuda(NodoArbol*);
   
}; 

Arbol::Arbol()
{ 
   raizPtr = 0;
} 

void Arbol::insertaNodo(int valor)
{ 
   insertaNodoAyuda(&raizPtr, valor);
} 

void Arbol::insertaNodoAyuda(NodoArbol **ptr, int valor)
{
   if(*ptr == NULL){
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

int Arbol::busquedaNodo(int valor)
{ 
   NodoArbol *auxRaiz;
   auxRaiz = raizPtr;
   bool encontrado = false;
   
   while((encontrado == false) && (auxRaiz != NULL)){
      if((auxRaiz->dato) == valor){
         encontrado = true;
      }
      else if((auxRaiz->dato) > valor){
         auxRaiz = auxRaiz->izquierdaPtr;
      }
      else{
         auxRaiz = auxRaiz->derechaPtr;
      }
   }
   
   if(encontrado == false){
      return(0);
   }
   
   return(1);
}

void Arbol::borrarNodo(int valor)
{
	NodoArbol *padre;
	NodoArbol *auxRaiz;
	NodoArbol *auxRaiz2;
	int cont1 = 0, cont2 = 0;
	
	buscaPadre(&auxRaiz, &padre, valor);

	if(((auxRaiz->izquierdaPtr) == NULL) && ((auxRaiz->derechaPtr) == NULL)){
		if((auxRaiz->dato) > (padre->dato)){
			padre->derechaPtr = NULL;
		}
		else{
			padre->izquierdaPtr = NULL;
		}
	}
	else{
		cuentaNodos(auxRaiz, &cont1, &cont2);
		
		if(cont1 >= cont2){
			auxRaiz2 = auxRaiz->izquierdaPtr;
			padre = auxRaiz2;
			while((auxRaiz2->derechaPtr) != NULL){
				if(auxRaiz2 != NULL){
					padre = auxRaiz2;
					auxRaiz2 = auxRaiz2->derechaPtr;
				}
			}
			auxRaiz->dato = auxRaiz2->dato;
			padre->derechaPtr = NULL;
		}
		else{
			auxRaiz2 = auxRaiz->derechaPtr;
			padre = auxRaiz2;
			while((auxRaiz2->izquierdaPtr) != NULL){
				if(auxRaiz2 != NULL){
					padre = auxRaiz2;
					auxRaiz2 = auxRaiz2->izquierdaPtr;
				}
			}
			auxRaiz->dato = auxRaiz2->dato;
			padre->izquierdaPtr = NULL;
		}
	}
}

void Arbol::cuentaNodos(NodoArbol *padre, int *cont1, int *cont2)
{
	NodoArbol *auxIzq;
	NodoArbol *auxDer;
	
	auxIzq = padre->izquierdaPtr;
	auxDer = padre->derechaPtr;
	
	while((auxIzq != NULL) || (auxDer != NULL)){
    if(auxIzq != NULL){
      if((auxIzq->dato) > (padre->dato)){
  	     auxIzq = auxIzq->izquierdaPtr;
  	     (*cont1)++;
  	  }
  	  else if((auxIzq->dato) < (padre->dato)){
  	     auxIzq = auxIzq->derechaPtr;
  	     (*cont1)++;
  	  }
    }
    
    if(auxDer != NULL){
      if((auxDer->dato) > (padre->dato)){
         auxDer = auxDer->izquierdaPtr;
         (*cont2)++;
      }
      else if((auxDer->dato) < (padre->dato)){
         auxDer = auxDer->derechaPtr;
         (*cont2)++;
      }
  	}
  }
}

int Arbol::mostrarHermano(int valor)
{
	NodoArbol *padre;
	NodoArbol *auxRaiz;
	int marca = 0;
	
	if((alturaNodo(valor)) == -1){
		cout << "Nodo no encontrado\n";
		return(0);
	}
	
	buscaPadre(&auxRaiz, &padre, valor);
	
	while(auxRaiz != NULL){
    if((padre->dato) > valor){
       auxRaiz = padre->derechaPtr;
    }
    else{
       auxRaiz = padre->izquierdaPtr;
    }
    if(auxRaiz != NULL){
    	 cout << auxRaiz->dato << " ";
    	 marca = 1;
    }
    break;
  }
   
	if(marca == 0){
   	  cout << "No tiene hermanos\n";
	}
	
	return(0);
}

void Arbol::mostrarHijos(int valor)
{
	NodoArbol *auxRaiz;
	NodoArbol *auxRaiz2;
	auxRaiz = raizPtr;
	int marca = 0;
	
	while(auxRaiz != NULL){
    if(auxRaiz->dato == valor){
       auxRaiz2 = auxRaiz->izquierdaPtr;
       if(auxRaiz2 != NULL){
       	cout << "\tIzquierdo: " << auxRaiz2->dato << endl;
       	marca = 1;
       }
       auxRaiz2 = auxRaiz->derechaPtr;
       if(auxRaiz2 != NULL){
       	cout << "\tDerecho: " << auxRaiz2->dato << endl;
       	marca = 1;
       }
       break;
    }
    else if((auxRaiz->dato) > valor){
       auxRaiz = auxRaiz->izquierdaPtr;
    }
    else{
       auxRaiz = auxRaiz->derechaPtr;
    }
  }
   
	if(marca == 0){
   	  cout << "No tiene hijos\n";
	}
}

int Arbol::mostrarNietos(int valor)
{
	NodoArbol *auxRaiz;
	NodoArbol *auxRaiz2;
	auxRaiz = raizPtr;
	int marca = 0;
	
	if((alturaNodo(valor)) == -1){
		cout << "Nodo no encontrado\n";
		return(0);
	}
	
	while(auxRaiz != NULL){
      if((auxRaiz->dato) == valor){
         auxRaiz2 = auxRaiz->izquierdaPtr;
         cout << "Nietos hijo izquierdo:\n";
         mostrarHijos(auxRaiz2->dato);
         auxRaiz2 = auxRaiz->derechaPtr;
         cout << "Nietos hijo derecho:\n";
         mostrarHijos(auxRaiz2->dato);
         break;
      }
      else if((auxRaiz->dato) > valor){
         auxRaiz = auxRaiz->izquierdaPtr;
      }
      else{
         auxRaiz = auxRaiz->derechaPtr;
      }
    }
}

int Arbol::mostrarPrimos(int valor)
{
	NodoArbol *abuelo;
	NodoArbol *padre;
	NodoArbol *auxRaiz;
	
	if((alturaNodo(valor)) == -1){
		cout << "Nodo no encontrado\n";
		return(0);
	}
	
	buscaPadre(&auxRaiz, &padre, valor);
	buscaPadre(&padre, &abuelo, padre->dato);
	
	while(auxRaiz != NULL){
    if((abuelo->dato) > (padre->dato)){
       auxRaiz = abuelo->derechaPtr;
    }
    else{
       auxRaiz = abuelo->izquierdaPtr;
    }
    if(auxRaiz != NULL){
    	 mostrarHijos(auxRaiz->dato);
    }
    break;
  }
}

int Arbol::mostrarSobrinos(int valor)
{
	NodoArbol *padre;
	NodoArbol *auxRaiz;
	
	if((alturaNodo(valor)) == -1){
		cout << "Nodo no encontrado\n";
		return(0);
	}
	
	buscaPadre(&auxRaiz, &padre, valor);
	
	while(auxRaiz != NULL){
    if((padre->dato) > valor){
       auxRaiz = padre->derechaPtr;
    }
    else{
       auxRaiz = padre->izquierdaPtr;
    }
    if(auxRaiz != NULL){
    	 mostrarHijos(auxRaiz->dato);
    }
    break;
  }
}

void Arbol::buscaPadre(NodoArbol **hijo, NodoArbol **padre, int valor)
{
	NodoArbol *auxRaiz;
	auxRaiz = raizPtr;
   
	while(auxRaiz != NULL){
		if((auxRaiz->dato) == valor){
			*hijo = auxRaiz;
			break;
  	}
  	else if((auxRaiz->dato) > valor){
    	*padre = auxRaiz;
    	auxRaiz = auxRaiz->izquierdaPtr;
  	}
  	else{
    	*padre = auxRaiz;
    	auxRaiz = auxRaiz->derechaPtr;
  	}
 	}
}

int Arbol::alturaNodo(int valor)
{
	NodoArbol *auxRaiz;
	auxRaiz = raizPtr;
	int cont = 0;
	
	while((busquedaNodo(valor)) && (auxRaiz != NULL)){
    if((auxRaiz->dato) == valor){
       return(cont);
    }
    else if((auxRaiz->dato) > valor){
       auxRaiz = auxRaiz->izquierdaPtr;
       cont++;
    }
    else{
       auxRaiz = auxRaiz->derechaPtr;
       cont++;
    }
  }
	
	return(-1);
}

void Arbol::completoNodo(int valor)
{
	NodoArbol *padre;
	NodoArbol *auxRaiz;
	int i;
	
	buscaPadre(&auxRaiz, &padre, valor);
	if(auxRaiz == NULL){
		cout << "El nodo no existe" << endl;
	}
	
	i = completoNodoAyuda(auxRaiz);
	
	if(i == 1){
		cout << valor << " es Nodo completo" << endl;
	}
	else{
		cout << valor << " no es Nodo completo" << endl;
	}
}

int Arbol::completoNodoAyuda(NodoArbol* ptr)
{
	int i = 0;
	
	if(((ptr->izquierdaPtr) == NULL) && ((ptr->derechaPtr) == NULL))
		return(1);
	else{
		if((ptr->izquierdaPtr) != NULL){
			i += completoNodoAyuda(ptr->izquierdaPtr);
		}
		if((ptr->derechaPtr) != NULL){
			i += completoNodoAyuda(ptr->derechaPtr);
		}
		if(i == 2){
			return(1);
		}
		else{
			return(0);
		}
	}
}

void Arbol::inOrden()
{ 
   inOrdenAyuda(raizPtr);
}

void Arbol::inOrdenAyuda(NodoArbol *ptr)
{
   if(ptr != 0){
      inOrdenAyuda(ptr->izquierdaPtr);
      cout << ptr->dato << ' ';
      inOrdenAyuda(ptr->derechaPtr);
   }
}

#endif
