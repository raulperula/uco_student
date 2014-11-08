#include "Arbolp.h"
#define TRUE 1

using namespace std;

int
main(void)
{
	Arbol intArbol;
	int opcion, opcion1;
	int cont = 0;
	int valor, valor1;
	int alt;
	char *nombre;
	fstream file;

	system("clear");
	
	while(TRUE){
		cout << "\n ** ARBOLES BINARIOS **" << endl;
	
		cout << "\n\t-- MENU --" << endl;
		cout << "\n Opcion 1: Crear un arbol" << endl;
		cout << " Opcion 2: Guardar arbol en fichero" << endl;
		cout << " Opcion 3: Recuperar arbol de fichero" << endl;
		cout << " Opcion 4: Camino minimo entre dos nodos" << endl;
		cout << " Opcion 5: Camino maximo entre la raiz y que pase por un nodo dado" << endl;
		cout << " Opcion 6: Borrado de un nodo" << endl;
		cout << " Opcion 7: Mostrar miembros de la familia de un nodo" << endl;
		cout << " Opcion 8: Calcular la altura de un nodo" << endl;
		cout << " Opcion 9: Comprobar si un nodo es completo" << endl;
		cout << "\n Opcion 0: Salir" << endl;
		cout << "\nOpcion: ";
		cin >> opcion;
	
		switch(opcion){
			/*Crear un arbol*/
			case 1:	cout << "\nIntroduce valores de tipo int (para acabar pulse 0):\n" << endl;

					while(valor != 0){
						cout << " Valor: ";
						cin >> valor;
						  
						if((valor != 0) && (intArbol.busquedaNodo(valor) == 0)){
							intArbol.insertaNodo(valor);
							cont++;
						}
					}
						  
					cout << "\n Arbol creado con " << cont << " nodos" << endl;
				
					break;
	
			/*Guardar arbol en fichero*/
			case 2:	nombre = new char(10);

					cout << "\n Nombre del fichero (sin extension): ";
					cin >> nombre;

					strcat(nombre, ".txt");
					file.open(nombre, ios::in | ios::out);

					if(file.is_open() == false){
					   	file.open(nombre, ios::out);
					   	file.close();
					   	
					   	file.open(nombre, ios::in | ios::out);
					   	assert(file.is_open()); 
				   	}

					intArbol.guardarArbol(file);

					file.close();
					delete nombre;
			
					break;
	
			/*Recuperar arbol de fichero*/
			case 3: nombre = new char(10);
					cout << "\n Nombre del fichero (sin extension): ";
					cin >> nombre;
		
					strcat(nombre, ".txt");
					file.open(nombre, ios::in);
		
					if(file.is_open() == false){
						cout << "\nERROR: el fichero <" << nombre << "> no existe\n" << endl;
						exit(-1);
					}
		
					cont = 0;
					while(!file.eof()){
						if(!file.eof()){
							file >> valor;
							if(intArbol.busquedaNodo(valor) == 0){
								intArbol.insertaNodo(valor);
								cont++;
							}
						}
					}
		
					cout << "\n El arbol recuperado es:" << endl;
					intArbol.inOrden();
					cout << endl;
		
					file.close();
					delete nombre;
			
					break;
	
			/*Camino minimo entre dos nodos*/
			case 4: cout << "\n Primer nodo: ";
					cin >> valor;
					cout << "\n Segundo nodo: ";
					cin >> valor1;
					
					cout << "\nCamino minimo entre los nodos " << valor << " y " << valor1 << ":" << endl;
					intArbol.mostrarCaminoMin(valor, valor1);
					cout << endl;
				
					break;
	
			/*Camino maximo entre la raiz y que pase por un nodo dado*/
			case 5: cout << "\n Nodo por el que desea que pase: ";
					cin >> valor;
		
					cout << "\nCamino mas largo:" << endl;
					intArbol.mostrarCaminoLargo(valor);
					cout << endl;
				
					break;
	
			/*Borrado de un nodo*/
			case 6: cout << "\n Valor del nodo: ";
					cin >> valor;
		
					intArbol.borrarNodo(valor);
					cout << "\nNuevo arbol:\n";
					intArbol.inOrden();
			
					break;
	
			/*Mostrar miembros de la familia*/
			case 7: cout << "\n Valor del nodo: ";
					cin >> valor;
						  	
					cout << "\nElija una opcion:" << endl;
					cout << " Opcion 1: Mostrar hermanos\n";
					cout << " Opcion 2: Mostrar hijos\n";
					cout << " Opcion 3: Mostrar nietos\n";
					cout << " Opcion 4: Mostrar primos\n";
					cout << " Opcion 5: Mostrar sobrinos\n";
					cout << "\n Opcion: ";
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
			
					break;

			/*Altura de un nodo*/
			case 8: cout << "\n Valor del nodo: ";
					cin >> valor;
					alt = intArbol.alturaNodo(valor);
					if(alt != -1){
						cout << "\n La altura del nodo con valor " << valor << " es: " << alt << endl;
					}
					else{
						cout << "\n El nodo no existe" << endl;
					}
			
					break;
	
			/*Nodo completo*/
			case 9: cout << "\n Valor del nodo: ";
					cin >> valor;
		
					intArbol.completoNodo(valor);

					cout << endl;
			
					break;
			case 0: system("clear");
					cout << "\n** GRACIAS POR UTILIZAR EL PROGRAMA **\n" << endl;
					exit(-1);
			default: cout << "\nOPCION INCORRECTA" << endl;
					 exit(-1);
		}
		cout << "\nPulse <ENTER> para continuar..." << endl;
		getchar();
		getchar();
		system("clear");
	}

	return 0;
}

