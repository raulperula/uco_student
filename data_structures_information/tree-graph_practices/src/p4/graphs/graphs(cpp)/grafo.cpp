#include "grafo.h"
#define TRUE 1

int
main(void)
{
	Grafo G;
	int opcion;
	int marca = 0;
	
	system("clear");
	while(TRUE){
		
		cout << "  0.  Salir................................" << endl;
		cout << "  1.  Introducir Grafo....................." << endl;
		cout << "  2.  Algoritmo de Dijkstra(GD y GND)......" << endl;
		cout << "  3.  Algoritmo Floyd(GD y GND)............" << endl;
		cout << "  4.  Algoritmo Prim(GND).................." << endl;
		cout << "  5.  Algoritmo Kruskal(GND)..............." << endl;
		cout << "  6.  Recorrido en profundidad(GD y GND)..." << endl;
		cout << "  7.  Recorrido en amplitud(GD y GND)......" << endl;
		cout << "  8.  Clasif. Topologica(GD aciclicos)....." << endl;
		cout << "  9.  Tipos de lados (b.en prof.para GD)..." << endl;
		cout << "  10. Guardar un grafo en un fichero......." << endl;
	
		cout << "\nIntroduzca opcion...: ";
		cin >> opcion;
		
		switch(opcion){
			case 1: marca = 1;
					G.introducirGrafo();
					
					break;
					
			case 2: /*Algoritmo de Dijkstra */
					if(marca == 1){
						G.algoritmoDijkstra();
					}
					else{
						cout << "\nDebe introducir un grafo primero (opcion 1)" << endl;
					}

					break;

			case 3: /*Algoritmo de Floyd */
					if(marca == 1){
						G.algoritmoFloyd();
					}
					else{
						cout << "\nDebe introducir un grafo primero (opcion 1)" << endl;
					}

					break;

			case 4: /*Algoritmo de Prim */
					if(marca == 1){
						if(G.verTipoGrafo() == 'n'){
							G.algoritmoPrim();
						}
						else{
							cout << "\nEl grafo es dirigido" << endl;
						}
					}
					else{
						cout << "\nDebe introducir un grafo primero (opcion 1)" << endl;
					}

					break;

			case 5: /*Algoritmo de Kruskal */
					if(marca == 1){
						if(G.verTipoGrafo() == 'n'){
							G.algoritmoKruskal();
						}
						else{
							cout << "\nEl grafo es dirigido" << endl;
						}
					}
					else{
						cout << "\nDebe introducir un grafo primero (opcion 1)" << endl;
					}

					break;

			case 6: /* busqueda en profundidad */
					if(marca == 1){
						G.profundidad();
					}
					else{
						cout << "\nDebe introducir un grafo primero (opcion 1)" << endl;
					}

					break;

			case 7: /* busqueda en amplitud */
					if(marca == 1){
						G.amplitud();
					}
					else{
						cout << "\nDebe introducir un grafo primero (opcion 1)" << endl;
					}

					break;

			case 8: /* Clasificación Topológica */
					if(marca == 1){
						if(G.verTipoGrafo() == 'd'){
							G.topologica();
						}
						else{
							cout << "\nEl grafo es no dirigido" << endl;
						}
					}
					else{
						cout << "\nDebe introducir un grafo primero (opcion 1)" << endl;
					}

					break;

			case 9: /* Clasificación de los lados de grafo dirigido en base a la búsqueda en profundidad */
					if(marca == 1){
						if(G.verTipoGrafo() == 'd'){
							G.tiposLados();
						}
						else{
							cout << "\nEl grafo es no dirigido" << endl;
						}
					}
					else{
						cout << "\nDebe introducir un grafo primero (opcion 1)" << endl;
					}

					break;
					
			case 10: /* Guarda un grafo en un fichero */
					 if(marca == 1){
						 G.guardarGrafoFich();
					 }
					 else{
						cout << "\nDebe introducir un grafo primero (opcion 1)" << endl;
					 }
					 
					 break;
					
			case 0: exit(-1);
			
			default: cout << "\nOPCION INCORRECTA" << endl;
					 break;
		}
		cout << "\nPulse <ENTER> para continuar..." << endl;
		getchar();
		getchar();
		system("clear");
	}
	
	return 0;
}

