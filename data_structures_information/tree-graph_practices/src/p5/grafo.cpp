#include "grafo.h"

int
main(void)
{
	Grafo G;
	int opcion = -1;
	int origen;
	int destino;
	
	system("clear");
	do{
		
		cout << " 0. Salir...................................................." << endl;
		cout << " 1. Dado una provincia origen y una provincia destino,......." << endl;
		cout << "    calcular la distancia y el camino minimo entre ambas....." << endl;
		cout << " 2. Dada una ciudad origen, calcular la ciudad mas lejana...." << endl;
		cout << "    a esa ciudad origen, indicando su distancia y su camino.." << endl;
		cout << " 3. Calcular cual seria la provincia que esta mas cercana a.." << endl;
		cout << "    todas las demas, es decir aquella provincia cuya suma...." << endl;
		cout << "    de distancias al resto de provincias sea minima. Esta...." << endl;
		cout << "    provincia se podria considerar como el centro de todas..." << endl;
		cout << "    las demas................................................" << endl;
	
		cout << "\nIntroduzca opcion...: ";
		cin >> opcion;
		
		switch(opcion){
			case 1: G.recuperarGrafoFich();
			
							cout << "\nElija la provincia de origen:" << endl;
							origen = menuProvincias();
							cout << "\nElija la provincia de destino:" << endl;
							destino = menuProvincias();
							
							G.calculaMinimo(origen, destino);
							
							break;
					
			case 2: G.recuperarGrafoFich();
							G.calculaMaximo();
							
							break;

			case 3: G.recuperarGrafoFich();
							G.ciudadCercana();
							
							break;
			
			default: if(opcion != 0){
									cout << "\nOPCION INCORRECTA\n" << endl;
									break;
							 }
		}
		
		if(opcion != 0){
			cout << "\nPulse <ENTER> para continuar...\n" << endl;
			getchar();
			while(getchar() != '\n');
			system("clear");
		}
	}while(opcion != 0);
	
	return 0;
}

