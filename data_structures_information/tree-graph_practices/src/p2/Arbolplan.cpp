#include <iostream>
#include "Arbolp.h"
using namespace std;

int
main(void)
{
	int opcion1;
	int cont = 0;
	Arbol intArbol;
	int valor;
	char res;
	int alt;
	   			  
	cout << "\nIntroduce valores de tipo int (para acabar pulse 0):\n";

	while(valor != 0){
		cout << "Valor: ";
		cin >> valor;
		      
		if((valor != 0) && (intArbol.busquedaNodo(valor) == 0)){
			intArbol.insertaNodo(valor);
			cont++;
		}
	}
			  
	cout << "\nArbol creado con " << cont << " nodos" << endl;
	
	/*Borrado de un nodo*/
	cout << "\nDesea borrar algun nodo? (Y/N): ";
	cin >> res;

	if((res == 'Y') || (res == 'y')){
		cout << "Valor del nodo: ";
		cin >> valor;
		
		intArbol.borrarNodo(valor);
		cout << "\nNuevo arbol:\n";
		intArbol.inOrden();
	}
	
	/*Mostrar miembros de la familia*/
	cout << "\nDesea mostrar algun mienbro de la familia? (Y/N): ";
	cin >> res;
	if((res == 'Y') || (res == 'y')){
		cout << "Valor del nodo: ";
		cin >> valor;
			  	
		cout << "\nElija una opcion:" << endl;
		cout << "Opcion 1: Mostrar hermanos\n";
		cout << "Opcion 2: Mostrar hijos\n";
		cout << "Opcion 3: Mostrar nietos\n";
		cout << "Opcion 4: Mostrar primos\n";
		cout << "Opcion 5: Mostrar sobrinos\n";
		cout << "\nOpcion: ";
		cin >> opcion1;
			  	
		switch(opcion1){
			case 1: cout << "\nHermanos:" << endl;
					intArbol.mostrarHermano(valor);
					break;
			case 2: cout << "\nHijos:" << endl;
					intArbol.mostrarHijos(valor);
					break;
			case 3: intArbol.mostrarNietos(valor);
					break;
			case 4: cout << "\nPrimos:" << endl;
			  		intArbol.mostrarPrimos(valor);
					break;
			case 5: cout << "\nSobrinos:" << endl;
					intArbol.mostrarSobrinos(valor);
					break;
			default: break;
		}
	}

	/*Altura de un nodo*/
	cout << "\nDesea saber la altura de un nodo? (Y/N): ";
	cin >> res;
	if((res == 'Y') || (res == 'y')){
		cout << "Valor del nodo: ";
		cin >> valor;
		alt = intArbol.alturaNodo(valor);
		if(alt != -1){
			cout << "\nLa altura del nodo con valor " << valor << " es: " << alt << endl;
		}
		else{
			cout << "\nEl nodo no existe" << endl;
		}
	}
	
	/*Nodo completo*/
	cout << "\nDesea saber si un nodo es completo? (Y/N): ";
	cin >> res;

	if((res == 'Y') || (res == 'y')){
		cout << "Valor del nodo: ";
		cin >> valor;
		
		intArbol.completoNodo(valor);
	}

	cout << endl;

	return 0;
}

