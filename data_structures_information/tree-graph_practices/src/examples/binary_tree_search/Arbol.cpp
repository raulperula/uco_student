#include <iostream>
#include <iomanip>
#include "Arbol.h" 

using namespace std;

int
main()
{
   Arbol intArbol; 
   int intValor, elementos;
   
   cout << "Dime cuantos elementos tendra el arbol: ";
   cin >> elementos;
   cout << "Introduce " << elementos << " valores enteros:\n";

   for(int i=0;i<elementos;i++){
      cin >> intValor;
      intArbol.insertaNodo( intValor );
   } 
   
   cout << "\nRecorrido Preorden \n";
   intArbol.preOrden();

   cout << "\nRecorrido Inorden \n";
   intArbol.inOrden();

   cout << "\nRecorrido Postorden \n";
   intArbol.postOrden();

   cout << endl;
   return 0;
} 
