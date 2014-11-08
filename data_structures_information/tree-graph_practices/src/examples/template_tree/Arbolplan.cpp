#include <iostream>
#include "Arbolp.h" 

using namespace std;

int
main()
{
   Arbol<int> intArbol;
   int intValor;

   cout << "Introduce 10 valores enteros:\n";

   for(int i=0;i<10;i++){
      cin >> intValor;
      intArbol.insertaNodo(intValor);
   }

   cout << "\nRecorrido Preorden \n";
   intArbol.preOrden();

   cout << "\nRecorrido Inorden \n";
   intArbol.inOrden();

   cout << "\nRecorrido Postorden \n";
   intArbol.postOrden();

   Arbol<double> doubleArbol;
   double doubleValor;
   cout << "\n\n\nIntroduce 10 valores double:\n";

   for(int j=0;j<10;j++){
      cin >> doubleValor;
      doubleArbol.insertaNodo(doubleValor);
   }

   cout << "\nRecorrido Preorden \n";
   doubleArbol.preOrden();

   cout << "\nRecorrido Inorden \n";
   doubleArbol.inOrden();

   cout << "\nRecorrido Postorden \n";
   doubleArbol.postOrden();

   cout << endl;

   return 0;
} 
