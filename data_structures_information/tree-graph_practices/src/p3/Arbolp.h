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
#include <fstream>
#include <cassert>
#include <string>
#include "NodoArbolp.h"

using namespace std;

class Arbol
{

public:

   Arbol();
   void insertaNodo(int);
   
   int busquedaNodo(int);
   
   void borrarNodo(int);
   int cuentaNodos(NodoArbol *);
   
   int mostrarHermano(int);
   void mostrarHijos(int);
   int mostrarNietos(int);
   int mostrarPrimos(int);
   int mostrarSobrinos(int);
   void buscaPadre(NodoArbol **, NodoArbol **, int);
   
   int alturaNodo(int);
   
   void completoNodo(int);
   
   void inOrden();
   void guardarArbol(fstream &);
   void mostrarCaminoLargo(int);
   void mostrarCaminoMin(int, int);

private:

   NodoArbol *raizPtr;

   void insertaNodoAyuda(NodoArbol **, int);
   int cuentaNodosAyuda(NodoArbol *);
   void inOrdenAyuda(NodoArbol *);
   int completoNodoAyuda(NodoArbol*);
   void guardarArbolAyuda(NodoArbol *, fstream &);
   
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
		cont1 = cuentaNodos(auxRaiz->izquierdaPtr);
		cont2 = cuentaNodos(auxRaiz->derechaPtr);
		
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

int Arbol::cuentaNodos(NodoArbol *raizPtr)
{
	return(cuentaNodosAyuda(raizPtr));
}

int Arbol::cuentaNodosAyuda(NodoArbol *Ptr)
{
	if(Ptr == NULL){
		return(0);
	}
	else{
		return(1+cuentaNodosAyuda(Ptr->izquierdaPtr)+cuentaNodosAyuda(Ptr->derechaPtr));
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
	
	if((alturaNodo(valor)) == -1){
		cout << "\nNodo no encontrado\n";
		return(0);
	}
	
	while(auxRaiz != NULL){
      if((auxRaiz->dato) == valor){
         auxRaiz2 = auxRaiz->izquierdaPtr;
         cout << "\nNietos hijo izquierdo:\n";
         mostrarHijos(auxRaiz2->dato);
         auxRaiz2 = auxRaiz->derechaPtr;
         cout << "\nNietos hijo derecho:\n";
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
    
    return(1);
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
    
    return(1);
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
    
    return(1);
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
		cout << "\nEl nodo no existe" << endl;
	}
	
	i = completoNodoAyuda(auxRaiz);
	
	if(i == 1){
		cout << "\n" << valor << " es nodo completo" << endl;
	}
	else{
		cout << "\n" << valor << " no es nodo completo" << endl;
	}
}

int Arbol::completoNodoAyuda(NodoArbol* ptr)
{
	int i = 0;
	
	if(((ptr->izquierdaPtr) == NULL) && ((ptr->derechaPtr) == NULL))
		return(1);
	else{
		if((ptr->izquierdaPtr) != NULL){
			i+= completoNodoAyuda(ptr->izquierdaPtr);
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
   if(ptr != NULL){
      inOrdenAyuda(ptr->izquierdaPtr);
      cout << ' ' << ptr->dato;
      inOrdenAyuda(ptr->derechaPtr);
   }
}

void Arbol::guardarArbol(fstream &file)
{ 
   guardarArbolAyuda(raizPtr, file);
}

void Arbol::guardarArbolAyuda(NodoArbol *ptr, fstream &file)
{
   if(ptr != NULL){
   	  file << ptr->dato << endl;
      guardarArbolAyuda(ptr->izquierdaPtr, file);
      guardarArbolAyuda(ptr->derechaPtr, file);
   }
}

void Arbol::mostrarCaminoLargo(int valor)
{
	NodoArbol *auxRaiz;
	int contIzq, contDer;
	
	auxRaiz = raizPtr;
	
	while(auxRaiz != NULL){
		contIzq = 0;
		contDer = 0;
		cout << " " << auxRaiz->dato;
		
		if((auxRaiz->dato) == valor){
			contIzq = cuentaNodos(auxRaiz->izquierdaPtr);
			contDer = cuentaNodos(auxRaiz->derechaPtr);
			
			if(contIzq >= contDer){
				auxRaiz = auxRaiz->izquierdaPtr;
				if(auxRaiz != NULL){
					valor = auxRaiz->dato;
				}
			}
			else{
				auxRaiz = auxRaiz->derechaPtr;
				if(auxRaiz != NULL){
					valor = auxRaiz->dato;
				}
			}
		}
		else if((auxRaiz->dato) > valor){
			auxRaiz = auxRaiz->izquierdaPtr;
		}
		else if((auxRaiz->dato) < valor){
			auxRaiz = auxRaiz->derechaPtr;
		}
	}
}

void Arbol::mostrarCaminoMin(int valor1, int valor2)
{
	NodoArbol *auxRaiz;
	int *v1, *v2;
	int i = 0, j = 0, encontrado = 0;
	int tam1, tam2;

	tam1 = 1+alturaNodo(valor1);
	tam2 = 1+alturaNodo(valor2);
	
	v1 = new int[tam1];
	v2 = new int[tam2];
	
	auxRaiz = raizPtr;

	/*Buscamos camino de la raiz al primer nodo*/
	while((auxRaiz != NULL) && (encontrado == 0)){
		v1[i] = auxRaiz->dato;
		if((auxRaiz->dato) == valor1){
			encontrado = 1;
		}
		else if((auxRaiz->dato) > valor1){
			auxRaiz = auxRaiz->izquierdaPtr;
		}
		else{
			auxRaiz = auxRaiz->derechaPtr;
		}
		i++;
	}
	/*Buscamos camino de la raiz al segundo nodo*/
	auxRaiz = raizPtr;
	encontrado = 0;
	i = 0;
	while((auxRaiz != NULL) && (encontrado == 0)){
		v2[i] = auxRaiz->dato;
		if((auxRaiz->dato) == valor2){
			encontrado = 1;
		}
		else if((auxRaiz->dato) > valor2){
			auxRaiz = auxRaiz->izquierdaPtr;
		}
		else{
			auxRaiz = auxRaiz->derechaPtr;
		}
		i++;
	}
	
	encontrado = 0;
	for(i=tam1-1;(i>=0)&&(encontrado==0);i--){
		for(j=tam2-1;(j>=0)&&(encontrado==0);j--){
			if(v1[i] == v2[j]){
				encontrado = 1;
			}
		}
	}
	
	i += 1;
	for(j=tam2-1;j>=i;j--){
		cout << " " << v2[j];
	}
	for(j=i+1;j<tam1;j++){
		cout << " " << v1[j];
	}
	cout << endl;
	
	delete v1;
	delete v2;
}

#endif
