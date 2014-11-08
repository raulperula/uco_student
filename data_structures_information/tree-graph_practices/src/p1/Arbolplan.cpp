#include <iostream>
#include "Arbolp.h" 

#define TRUE 1

using namespace std;

int
main(void)
{
   int opcion1, opcion2;
   Arbol<char> charArbol;
   Arbol<int> intArbol;
   Arbol<float> floatArbol;
   Arbol<double> doubleArbol;
   
   system("clear");
   
   cout << "\n--Elija una opcion--\n" << endl;
   cout << "Opcion 1: Arbol de tipo char\n";
   cout << "Opcion 2: Arbol de tipo int\n";
   cout << "Opcion 3: Arbol de tipo float\n";
   cout << "Opcion 4: Arbol de tipo double\n";
   cout << "Opcion 5: Salir\n";
	   
   cout << "\nOpcion: ";
   cin >> opcion1;
   
   switch(opcion1){
   	  /*Arbol de tipo char*/
   	  case 1: char charValor;
	   			  
			  cout << "\nIntroduce valores de tipo char ";
			  cout << "(Cuando desee acabar pulse 'S'):\n" << endl;

   			  while(charValor != 'S'){
			      cout << "Valor: ";
			      cin >> charValor;
			      if(charValor != 'S'){
			      	charArbol.insertaNodo(charValor);
			      }
			  }
				  
			  cout << "\n--Elija un recorrido--\n" << endl;
			  cout << "Opcion 1: Preorden\n";
			  cout << "Opcion 2: Inorden\n";
			  cout << "Opcion 3: Postorden\n";
			  cout << "\nOpcion: ";
			  cin >> opcion2;
				  
			  switch(opcion2){
			  	  /*Preorden*/
			  	  case 1: cout << "\nRecorrido Preorden \n";
						  charArbol.preOrden();
						  break;
			  	  
			  	  /*Inorden*/
			  	  case 2: cout << "\nRecorrido Inorden \n";
						  charArbol.inOrden();
						  break;
				  	  
			  	  /*Postorden*/
			  	  case 3: cout << "\nRecorrido Postorden \n";
						  charArbol.postOrden();
						  break;
			  	  
			  	  /*Caso por defecto*/
			  	  default: cout << "\nOpcion incorrecta\n";
	  		  			   exit(-1);
			  }
				  
			  charArbol.busquedaSubarbol(charValor);
				  
			  break;
	   	  
   	  /*Arbol de tipo int*/
   	  case 2: int intValor;
	   			  
			  cout << "\nIntroduce valores de tipo int (para acabar pulse 0):\n";

   			  while(intValor != 0){
   			  	  cout << "Valor: ";
			      cin >> intValor;
			      if(intValor != 0){
				      intArbol.insertaNodo(intValor);
				  }
			  }
				  
			  cout << "\n--Elija un recorrido--\n" << endl;
			  cout << "Opcion 1: Preorden\n";
			  cout << "Opcion 2: Inorden\n";
			  cout << "Opcion 3: Postorden\n";
			  cout << "\nOpcion: ";
			  cin >> opcion2;
				  
			  switch(opcion2){
			  	  /*Preorden*/
			  	  case 1: cout << "\nRecorrido Preorden \n";
						  intArbol.preOrden();
						  break;
				  	  
			  	  /*Inorden*/
			  	  case 2: cout << "\nRecorrido Inorden \n";
						  intArbol.inOrden();
						  break;
				  	  
			  	  /*Postorden*/
			  	  case 3: cout << "\nRecorrido Postorden \n";
						  intArbol.postOrden();
						  break;
			  	  
			  	  /*Caso por defecto*/
			  	  default: cout << "\nOpcion incorrecta\n";
	  		  			   exit(-1);
			  }
				  
			  cout << "\n\nIntroduce un valor y mostrare su subarbol en inorden: ";
			  cin >> intValor;
				  
			  intArbol.busquedaSubarbol(intValor);
			  
			  break;
	
   	  /*Arbol de tipo float*/
   	  case 3: float floatValor;
	   			  
		   	  cout << "\nIntroduce valores de tipo float (para acabar pulse 0):\n";
	
			  while(floatValor != 0){
      			  cout << "Valor: ";
      			  cin >> floatValor;
      			  if(floatValor != 0){
				      floatArbol.insertaNodo(floatValor);
				  }
			  }
				  
			  cout << "\n--Elija un recorrido--\n" << endl;
			  cout << "Opcion 1: Preorden\n";
			  cout << "Opcion 2: Inorden\n";
			  cout << "Opcion 3: Postorden\n";
			  cout << "\nOpcion: ";
			  cin >> opcion2;
				  
			  switch(opcion2){
			  	  /*Preorden*/
			  	  case 1: cout << "\nRecorrido Preorden \n";
						  floatArbol.preOrden();
						  break;
				  	  
			  	  /*Inorden*/
			  	  case 2: cout << "\nRecorrido Inorden \n";
						  floatArbol.inOrden();
						  break;
			  	  
			  	  /*Postorden*/
			  	  case 3: cout << "\nRecorrido Postorden \n";
						  floatArbol.postOrden();
						  break;
			  	  
			  	  /*Caso por defecto*/
			  	  default: cout << "\nOpcion incorrecta\n";
	  		  			   exit(-1);
			  }
			  
			  floatArbol.busquedaSubarbol(floatValor);
			  
			  break;
	   	  
   	  /*Arbol de tipo double*/
   	  case 4: double doubleValor;
	   			  
		   	  cout << "\nIntroduce valores de tipo double (para acabar pulse 0):\n";

   			  while(doubleValor != 0){
      			  cout << "Valor: ";
      			  cin >> doubleValor;
      			  if(doubleValor != 0){
				      doubleArbol.insertaNodo(doubleValor);
			      }
			  }
				  
			  cout << "\n--Elija un recorrido--\n" << endl;
			  cout << "Opcion 1: Preorden\n";
			  cout << "Opcion 2: Inorden\n";
			  cout << "Opcion 3: Postorden\n";
			  cout << "\nOpcion: ";
			  cin >> opcion2;
			  
			  switch(opcion2){
			  	  /*Preorden*/
			  	  case 1: cout << "\nRecorrido Preorden \n";
						  doubleArbol.preOrden();
						  break;
				  	  
			  	  /*Inorden*/
			  	  case 2: cout << "\nRecorrido Inorden \n";
						  doubleArbol.inOrden();
						  break;
				  	  
			  	  /*Postorden*/
			  	  case 3: cout << "\nRecorrido Postorden \n";
						  doubleArbol.postOrden();
						  break;
			  	  
			  	  /*Caso por defecto*/
			  	  default: cout << "\nOpcion incorrecta\n";
	  		  			   exit(-1);
			  }
			  
			  doubleArbol.busquedaSubarbol(doubleValor);
			  
			  break;
			  
	  /*Salida del programa*/
	  case 5: exit(-1);
		  
	  /*Caso por defecto*/		  
	  default: cout << "\nOpcion incorrecta\n";
	  		   exit(-1);
   }

   return 0;
}

