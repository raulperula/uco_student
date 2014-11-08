#ifndef _GRAFO_H_
#define _GRAFO_H_

/**
 * @file    grafo.h
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
#include "cola.h"
#include "lado.h"
#define INF 32000

using namespace std;

class Grafo
{

public:
	Grafo();
	Grafo(int, char);
	~Grafo();
	
	void introducirGrafo();
	void asignarTipoGrafo(char);
	char verTipoGrafo();
	void asignarNumeroNodos(int);
	int verNumeroNodos();
	void reservarGrafo();
	void asignarPeso(int, int, double);
	double verPeso(int, int);
	void asignarPesosGrafo();
	void verPesosGrafo();
	
	//////////////////////////////////////////////////////////////////////
	
	void tiposLados();
	void clasificacionLados(int, int *, int *, int *, int *, char **);
	
	//////////////////////////////////////////////////////////////////////
	
	void profundidad();
	void amplitud();
	void topologica();
	void recorridoProfundidad(int, int *);
	void recorridoAmplitud(int, int *, Cola);
	void clasificacionTopologica(int, int *);
	
	//////////////////////////////////////////////////////////////////////
	
	void algoritmoDijkstra();
	void Dijkstra(double *, int *, int);
	void caminoDijkstra(int, int, int *);
	void algoritmoFloyd();
	void Floyd(double **, int **);
	void caminoFloyd(int **, int, int);
	
	//////////////////////////////////////////////////////////////////////
	
	void algoritmoPrim();
	void algoritmoKruskal();
	void Prim(double **);
	void Kruskal(double **);
	void fusionar(Lado, int *, int);
	
	//////////////////////////////////////////////////////////////////////
	//////	Algoritmos practica 5
	//////////////////////////////////////////////////////////////////////
	
	void guardarGrafoFich();
	void recuperarGrafoFich();
	void calculaMinimo(int, int);
	void Minimo(double *, int *, int);
	void camino(int, int, int *);
	void calculaMaximo();
	void Maximo(double *, int *, int);
	void ciudadCercana();
	void calculaDistancias(double *, int *, int);
	
private:
	double **_mConexion;
	int _nNodos;
	char _tipo; 		/*d = dirigido, n = no dirigido */
	
};

Grafo::Grafo()
{
	_mConexion = NULL;
	_nNodos = 0;
}

Grafo::Grafo(int nNodos, char tipo)
{
	_nNodos = nNodos;
	_tipo = tipo;
	
	_mConexion = new double*[nNodos];
	for(int i=0;i<nNodos;i++){
		_mConexion[i] = new double[nNodos];
	}
}

Grafo::~Grafo()
{
	if(_mConexion != NULL){
		for(int i=0;i<_nNodos;i++){
			delete[] _mConexion[i];
		}
		delete[] _mConexion;
	}
}

void Grafo::introducirGrafo()
{
	int n;
	char tipo;
	
	do{
		cout << "\nTipo de grafo (d = dirigido, n = no dirigido): ";
		cin >> tipo;
	}while ((tipo != 'd') && (tipo != 'n'));

	asignarTipoGrafo(tipo);

	cout << "\nNumero de nodos del grafo: ";
	cin >> n;
	
	asignarNumeroNodos(n);
	reservarGrafo();
	asignarPesosGrafo();
}

void Grafo::asignarTipoGrafo(char t)
{
	_tipo = t;
}

char Grafo::verTipoGrafo()
{
	return(_tipo);
}

void Grafo::asignarNumeroNodos(int n)
{
	_nNodos = n;
}

int Grafo::verNumeroNodos()
{
	return(_nNodos);
}

void Grafo::reservarGrafo()
{
	int i;

	_mConexion = new double*[verNumeroNodos()];

	for(i=0;i<verNumeroNodos();i++){
		_mConexion[i] = new double[verNumeroNodos()];
	}
}

void Grafo::asignarPeso(int origen, int destino, double peso)
{
	_mConexion[origen][destino] = peso;
}

double Grafo::verPeso(int origen, int destino)
{
	return(_mConexion[origen][destino]);
}

void Grafo::asignarPesosGrafo()
{
	int i, j;
	double aux;

	if(verTipoGrafo() == 'n'){ /* Grafo ND */
		cout << "\nIntroduzca los pesos:" << endl;
		for(i=0;i<verNumeroNodos();i++){
			for(j=i+1;j<verNumeroNodos();j++){
				cout << "De '" << (char)(i+65) << "' a '" << (char)(j+65) << "': ";
				cin >> aux;
				if(aux == 0.0){
					asignarPeso(i, j, INF);
					asignarPeso(j, i, INF);
				}
				else{
					asignarPeso(i, j, aux);
					asignarPeso(j, i, aux);
				}
			}
			asignarPeso(i, i, 0);
		}
	}
	else{ /* Grafo D*/
		for(i=0;i<verNumeroNodos();i++){
			for(j=0;j<verNumeroNodos();j++){
				/*Mostramos las etiquetas de los nodos e introducimos 1 si hay
				  camino y 0 si no hay*/
				cout << "De '" << (char)(i+65) << "' a '" << (char)(j+65) << "': ";
				cin >> aux;
				if(aux == 0.0){
					asignarPeso(i, j, INF);
					asignarPeso(j, i, INF);
				}
				else{
					asignarPeso(i, j, aux);
					asignarPeso(j, i, aux);
				}
			}
		}
	}
}

void Grafo::verPesosGrafo()
{
	int i, j;

	for(i=0;i<verNumeroNodos();i++){
		for(j=0;j<verNumeroNodos();j++){
			if(verPeso(i, j) != INF){
				cout << verPeso(i, j) << " ";
			}
			else{
				cout << "INF" << " ";
			}
		}
		cout << endl;
	}
}

//////////////////////////////////////////////////////////////////////////

void Grafo::tiposLados()
{
	int *visitado;
	char **tipoLado;
	int *numeroProfundidad;
	int *numeroDescendientes;
	int contadorProfundidad = 0;
	int i, j;

	visitado = new int[verNumeroNodos()];
	numeroDescendientes = new int[verNumeroNodos()];
	numeroProfundidad = new int[verNumeroNodos()];
	tipoLado = new char*[verNumeroNodos()];

	for(i=0;i<verNumeroNodos();i++){
		tipoLado[i] = new char[verNumeroNodos()];
	}

	for(i=0;i<verNumeroNodos();i++){
		visitado[i] = 0;
		numeroDescendientes[i] = 0;
		numeroProfundidad[i] = 0;
	}

	for(i=0;i<verNumeroNodos();i++){
		for(j=0;j<verNumeroNodos();j++){
			tipoLado[i][j] = '*';

			for(i=0;i<verNumeroNodos();i++){
				if(visitado[i] == 0){
					clasificacionLados(i, visitado,numeroDescendientes, numeroProfundidad, &contadorProfundidad, tipoLado);
				}
			}
		}
	}

	/* Clasificacion de lados que no son de árbol  (a = avance, r =	retroceso, c = cruzado */
	for(i=0;i<verNumeroNodos();i++){
		for(j=0;j<verNumeroNodos();j++){
			if((tipoLado[i][j] != 'A') && (verPeso(i, j) < INF)){
				if(numeroProfundidad[i] < numeroProfundidad[j]){
					tipoLado[i][j] = 'a';
				}
				else if((numeroProfundidad[i] > numeroProfundidad[j]) && (numeroProfundidad[i] < numeroProfundidad[j]+numeroDescendientes[j])){
					tipoLado[i][j] = 'r';
				}
				else{
					tipoLado[i][j] = 'c';
				}
			}
		}
	}

	/* Visualizacion de los tipos de lados */
	for(i=0;i<verNumeroNodos();i++){
		for(j=0;j<verNumeroNodos();j++){
			cout << tipoLado[i][j];
		}
		cout << endl;;
	}

	delete[] visitado;
	delete[] numeroDescendientes;
	delete[] numeroProfundidad;

	for(i=0;i<verNumeroNodos();i++){
		delete[] tipoLado[i];
	}

	delete[] tipoLado;
}

void Grafo::clasificacionLados(int i, int *visitado, int *desc, int *prof, int *cont, char **tipoLado)
{
	int j;

	(*cont)++;
	visitado[i] = 1;
	prof[i] = *cont;

	for(j=0;j<verNumeroNodos();j++){
		if((verPeso(i, j) < INF) && (visitado[j] == 0)){
			tipoLado[i][j] = 'A';
			clasificacionLados(j, visitado, desc, prof, cont, tipoLado);
			desc[i] += desc[j]+1;
		}
	}
}

//////////////////////////////////////////////////////////////////////////

void Grafo::profundidad()
{
	int *visitado;
	int i;

	visitado = new int[verNumeroNodos()];

	for(i=0;i<verNumeroNodos();i++){
		visitado[i] = 0;
	}
	
	for(i=0;i<verNumeroNodos();i++){
		if(visitado[i] == 0){
			recorridoProfundidad(i, visitado);
		}
	}
	
	delete[] visitado;
}

void Grafo::recorridoProfundidad(int i, int *visitado)
{
	int j;

	visitado[i] = 1;
	cout << " " << (char)(i+65);

	for(j=0;j<verNumeroNodos();j++){
		if((verPeso(i, j) < INF) && (visitado[j] == 0)){
			recorridoProfundidad(j, visitado);
		}
	}
}

void Grafo::amplitud()
{
	int *visitado;
	int i;    
	Cola colaNodos;

	visitado = new int[verNumeroNodos()];
	
	for(i=0;i<verNumeroNodos();i++){
		visitado[i] = 0;
	}
	
	for(i=0;i<verNumeroNodos();i++){
		if(visitado[i] == 0){
			recorridoAmplitud(i, visitado, colaNodos);
		}
	}
	
	delete[] visitado;
}

void Grafo::recorridoAmplitud(int i, int *visitado, Cola colaNodos)
{
	int j;
	int x;

	visitado[i] = 1;
	
	cout << " " << (char)(i+65);
	
	colaNodos.insertarCola(i);

	while(colaNodos.colaVacia() == false){
		x = colaNodos.extraerCola();
		
		for(j=0;j<verNumeroNodos();j++){
			if((verPeso(x, j) < INF) && (visitado[j] == 0)){
				visitado[j] = 1;
				colaNodos.insertarCola(j);
				cout << " " << (char)(j+65);
			}
		}
	}
}

void Grafo::topologica()
{
	int i;
	int *visitado;

	visitado = new int[verNumeroNodos()];
	
	for(i=0;i<verNumeroNodos();i++){
		visitado[i] = 0;
	}
	
	for(i=0;i<verNumeroNodos();i++){
		if(visitado[i] == 0){
			clasificacionTopologica(i, visitado);
		}
	}
	
	delete[] visitado;
}

void Grafo::clasificacionTopologica(int i, int *visitado)
{
	int j;

	visitado[i] = 1;

	for(j=0;j<verNumeroNodos();j++){
		if((verPeso(i, j) < INF) && (visitado[j] == 0)){
			clasificacionTopologica(j, visitado);
		}
	}
	
	cout << " " << i;
}

//////////////////////////////////////////////////////////////////////////

void Grafo::algoritmoDijkstra()
{
	double *distancias;
	int *predecesores;
	int i;
	char origen;

	predecesores = new int[verNumeroNodos()];
	distancias = new double[verNumeroNodos()];
	
	cout << "Nodo origen: ";
	cin >> origen;
	
	Dijkstra(distancias, predecesores, (int) (origen-65));
	
	for(i=0;i<verNumeroNodos();i++){
		cout << "\nLa distancia minima al nodo " << (char) (i+65) << " es " << distancias[i] << endl;
		cout << "El camino minimo al nodo " << (char) (i+65) << " es: " << endl;
		caminoDijkstra((int) (origen-65), i, predecesores);
	}

	delete[] distancias;
	delete[] predecesores;
}

void Grafo::Dijkstra(double *d, int *p, int origen)
{
	int i, j;
	int *s;
	double minimo;
	int x;

	s = new int[verNumeroNodos()];

	for(i=0;i<verNumeroNodos();i++){
		p[i] = origen;
		d[i] = verPeso(origen, i);
		s[i] = 0;
	}

	s[origen] = 1;

	for(i=0;i<verNumeroNodos()-1;i++){
		/* Buscar Nodo de distancia minima */
		minimo = INF;
		
		for(j=0;j<verNumeroNodos();j++){
			if((d[j] <= minimo) && (s[j] == 0)){
				minimo = d[j];
				x = j;
			}
		}
		
		s[x] = 1; /* El nodo x pasa al conjunto s */
		
		/* Comprobamos si el nodo x acorta las distancias */
		for(j=0;j<verNumeroNodos();j++){
			if((s[j] == 0) && (d[j] > d[x]+verPeso(x, j))){
				d[j] = d[x]+verPeso(x, j);
				p[j] = x;
			}
		}
	}
	
	delete[] s;
}

void Grafo::caminoDijkstra(int origen, int destino, int *p)
{
	int k;

	cout << (char)(destino+65) << " <- ";
	k = p[destino];

	while(k != origen){
		cout << (char)(k+65) << " <- ";
		k = p[k];
	}

	cout << (char)(origen+65) << endl;
}

void Grafo::algoritmoFloyd()
{
	double **distanciasFloyd;
	int **intermedios;
	int i, j;

	distanciasFloyd = new double*[verNumeroNodos()];

	for(i=0;i<verNumeroNodos();i++){
		distanciasFloyd[i] = new double[verNumeroNodos()];
	}

	intermedios = new int*[verNumeroNodos()];

	for(i=0;i<verNumeroNodos();i++){
		intermedios[i] = new int[verNumeroNodos()];
	}

	Floyd(distanciasFloyd, intermedios);
	
	for(i=0;i<verNumeroNodos();i++){
		for(j=i+1;j<verNumeroNodos();j++){
			cout << "\nLa distancia minima entre " << (char)(i+65) << " y " << (char)(j+65) << " es: " << distanciasFloyd[i][j] << endl;
			cout << "El camino minimo entre " << (char)(i+65) << " y " << (char)(j+65) << " es: ";
			caminoFloyd(intermedios, i, j);
			cout << endl;
		}
	}
	
	for(i=0;i<verNumeroNodos();i++){
		delete[] distanciasFloyd[i];
		delete[] intermedios[i];
	}

	delete[] distanciasFloyd;
	delete[] intermedios;
}

void Grafo::Floyd(double **distancias, int **intermedios)
{
	int i, j, k;

	for(i=0;i<verNumeroNodos();i++){
		for(j=0;j<verNumeroNodos();j++){
			distancias[i][j] = verPeso(i, j);
			intermedios[i][j] = -1;
		}
	}
	
	for(k=0;k<verNumeroNodos();k++){
		for(i=0;i<verNumeroNodos();i++){
			for(j=0;j<verNumeroNodos();j++){
				if(distancias[i][j] > distancias[i][k]+distancias[k][j]){
					distancias[i][j] = distancias[i][k]+distancias[k][j];
					intermedios[i][j] = k;
				}
			}
		}
	}
}

void Grafo::caminoFloyd(int **intermedios, int origen, int destino)
{
	int k;

	k = intermedios[origen][destino];

	if(k != -1){
		caminoFloyd(intermedios, origen, k);
		cout << " " << (char)(k+65);
		caminoFloyd(intermedios, k, destino);
	}
}

//////////////////////////////////////////////////////////////////////////

void Grafo::algoritmoPrim()
{
	int i, j;
	double **arbolACM; /*matriz de conexion para el arbol */

	arbolACM = new double*[verNumeroNodos()];

	for(i=0;i<verNumeroNodos();i++){
		arbolACM[i] = new double[verNumeroNodos()];
	}

	Prim(arbolACM);
	
	cout << "\nARBOL ABARCADOR DE COSTE MINIMO" << endl;
	
	for(i=0;i<verNumeroNodos();i++){
		for(j=0;j<verNumeroNodos();j++){
			cout << " " << arbolACM[i][j];
		}
		cout << endl;
	}

	for(i=0;i<verNumeroNodos();i++){
		delete[] arbolACM[i];
	}

	delete[] arbolACM;
}

void Grafo::Prim(double **arbol)
{
	int i,j,k;
	int *cercano;
	double *coste;

	cercano = new int[verNumeroNodos()];
	coste = new double[verNumeroNodos()];

	for(i=0;i<verNumeroNodos();i++){
		for(j=0;j<verNumeroNodos();j++){
			arbol[i][j] = INF;
		}
	}

	for(i=0;i<verNumeroNodos();i++){
		cercano[i] = 0;
		coste[i] = verPeso(0, i);
	}
	
	/* Seleccion de los n-1 lados del arbol*/
	for(i=1;i<verNumeroNodos();i++){
		/* Seleccion del nodo de menor coste */
		k = 1;
		for(j=2;j<verNumeroNodos();j++){
			if((coste[j] < INF) && (coste[j] < coste[k])){
				k = j;
			}
		}
		
		/* El nodo de menor coste pasa a formar parte del arbol */
		coste[k] = INF;
		arbol[k][cercano[k]] = verPeso(k,cercano[k]);
		arbol[cercano[k]][k] = verPeso(k,cercano[k]);

		/* Se corrige el vector cercano, considerando al nodo k */
		for(j=1;j<verNumeroNodos();j++){
			if((coste[j] < INF) && (coste[j] > verPeso(j, k))){
				cercano[j] = k;
				coste[j] = verPeso(j, k);
			}
		}
	}
}

void Grafo::algoritmoKruskal()
{
	int i, j;
	double **arbolACM; /*matriz de conexion para el arbol */

	arbolACM = new double*[verNumeroNodos()];

	for(i=0;i<verNumeroNodos();i++){
		arbolACM[i] = new double[verNumeroNodos()];
	}

	Kruskal(arbolACM);
	
	cout << "\nARBOL ABARCADOR DE COSTE MINIMO (KRUSKAL)" << endl;
	
	for(i=0;i<verNumeroNodos();i++){
		for(j=0;j<verNumeroNodos();j++){
			cout << " " << arbolACM[i][j];
		}
		cout << endl;
	}

	for(i=0;i<verNumeroNodos();i++){
		delete[] arbolACM[i];
	}

	delete[] arbolACM;
}

void Grafo::Kruskal(double **arbol)
{
	int i, j, k;
	int *conjunto;
	int numeroLados = 0;
	Lado aux;

	conjunto = new int[verNumeroNodos()];

	for(i=0;i<verNumeroNodos();i++){
		for(j=0;j<verNumeroNodos();j++){
			arbol[i][j] = INF;
		}
	}

	for(i=0;i<verNumeroNodos();i++){
		for(j=i+1;j<verNumeroNodos();j++){
			if(verPeso(i, j) < INF){
				numeroLados++;
			}
		}
		conjunto[i] = i;
	}
	
	/* reserva y creacion del vector de lados*/
	vector<Lado> l(numeroLados);

	k = 0;
	for(i=0;i<verNumeroNodos();i++){
		for(j=i+1;j<verNumeroNodos();j++){
			if(verPeso(i, j) < INF){
				l[k].setPeso(verPeso(i, j));
				l[k].setOrigen(i);
				l[k].setDestino(j);
				k++;
			}
		}
	}
	
	/* ordenacion del vector de lados*/
	for(i=0;i<numeroLados-1;i++){
		k = i;
		for(j=i+1;j<numeroLados;j++){
			if(l[j].getPeso() < l[k].getPeso()){
				k = j;
			}
		}
		aux = l[k];
		l[k] = l[i];
		l[i] = aux;
	}

	/* recorrido de los lados en orden creciente y formacion del
	arbol */
	k = 0; /* contador de lados evaluados*/
	i = 0; /*contador de lados seleccionados*/
	while(i < verNumeroNodos()-1){
		if(conjunto[l[k].getOrigen()] != conjunto[l[k].getDestino()]){
			arbol[l[k].getOrigen()][l[k].getDestino()] = l[k].getPeso();
			arbol[l[k].getDestino()][l[k].getOrigen()] = l[k].getPeso();
			fusionar(l[k], conjunto, verNumeroNodos());
			i++;
		}
		k++;
	}
}

void Grafo::fusionar(Lado l, int *conjunto, int n)
{
	int aux;
	int i;

	aux = conjunto[l.getDestino()];
	
	for(i=0;i<n;i++){
		if(conjunto[i] == aux){
			conjunto[i] = conjunto[l.getOrigen()];
		}
	}
}

//////////////////////////////////////////////////////////////////////////
/////////	Algoritmos practica 5
//////////////////////////////////////////////////////////////////////////

//Funcion que guarda un grafo en un fichero
void Grafo::guardarGrafoFich()
{
	fstream file;
	char nombre[10];
	
	cout << "\nNombre del fichero donde desea guardar el grafo(sin extension): ";
	cin >> nombre;
	
	strcat(nombre, ".txt");
	
	file.open(nombre, ios::out);
	
	assert(file.is_open());
	
	for(int i=0;i<_nNodos;i++){
		for(int j=0;j<_nNodos;j++){
			file << _mConexion[i][j] << ' ';
		}
		file << endl;
	}
	
	file.close();
}

//Funcion que recupera un grafo de un fichero
void Grafo::recuperarGrafoFich()
{
	fstream file;
	char nombre[] = "matrizconexion.txt";
	int i, j;
	
	_tipo = 'n';
	
	file.open(nombre, ios::in);
	
	for(i=0;i<2;i++){
		file >> _nNodos;
	}
	
	//Reserva de memoria para la matriz de conexion
	_mConexion = new double*[_nNodos];
	for(i=0;i<_nNodos;i++){
		_mConexion[i] = new double[_nNodos];
	}
	
	//Asignacion de valores
	for(i=0;i<_nNodos;i++){
		for(j=0;j<_nNodos;j++){
			file >> _mConexion[i][j];
		}
	}
	
	file.close();
}

//Funcion que muestra una provincia
string mostrarProvincia(int numPro)
{
	fstream file;
	string auxPro;
	int i = 0;
	
	file.open("provincias.txt", ios::in);
	
	while(i <= numPro){
		file >> auxPro;
		i++;
	}
	
	file.close();
	
	return(auxPro);
}

//Funcion que muestra un menu con todas las provincias posibles
int menuProvincias()
{
	fstream file;
	string auxPro;
	int i = 0;
	int opcion;
	
	file.open("provincias.txt", ios::in);
	
	while(!file.eof()){
		file >> auxPro;
		if(!file.eof()){	
			cout << " Opcion " << i << ": " << auxPro << "\t\t";
			if((i%2) != 0){
				cout << endl;
			}
			i++;
		}
	}
	cout << "\n\nOpcion: ";
	cin >> opcion;
	
	file.close();
	
	if((opcion < 0) || (opcion > i-1)){
		system("clear");
		cout << "\n\t***** Opcion incorrecta *****\n" << endl;
		cout << "Pruebe de nuevo:\n" << endl;
		return(menuProvincias());
	}
	else{
		return(opcion);
	}
}

//Funcion opcion 1 del menu
void Grafo::calculaMinimo(int origen, int destino)
{
	double *distancias;
	int *predecesores;

	predecesores = new int[verNumeroNodos()];
	distancias = new double[verNumeroNodos()];
	
	Minimo(distancias, predecesores, origen);
	
	cout << "\nLa distancia minima es " << distancias[destino] << endl;
	cout << "El camino minimo es: " << endl;
	camino(origen, destino, predecesores);

	delete[] distancias;
	delete[] predecesores;
}

//Funcion auxliar opcion 1 del menu
void Grafo::Minimo(double *d, int *p, int origen)
{
	int i, j;
	int *s;
	double minimo;
	int x;

	s = new int[verNumeroNodos()];

	for(i=0;i<verNumeroNodos();i++){
		p[i] = origen;
		d[i] = verPeso(origen, i);
		s[i] = 0;
	}

	s[origen] = 1;

	for(i=0;i<verNumeroNodos()-1;i++){
		/* Buscar Nodo de distancia minima */
		minimo = INF;
		
		for(j=0;j<verNumeroNodos();j++){
			if((d[j] <= minimo) && (s[j] == 0)){
				minimo = d[j];
				x = j;
			}
		}
		
		s[x] = 1; /* El nodo x pasa al conjunto s */
		
		/* Comprobamos si el nodo x acorta las distancias */
		for(j=0;j<verNumeroNodos();j++){
			if((s[j] == 0) && (d[j] > d[x]+verPeso(x, j))){
				d[j] = d[x]+verPeso(x, j);
				p[j] = x;
			}
		}
	}
	
	delete[] s;
}

//Funcion auxliar opciones 1 y 2 del menu
void Grafo::camino(int origen, int destino, int *p)
{
	int k;

	cout << mostrarProvincia(destino) << " <- ";
	k = p[destino];

	while(k != origen){
		cout << mostrarProvincia(k) << " <- ";
		k = p[k];
	}

	cout << mostrarProvincia(origen) << endl;
}

//Funcion auxilar opcion 2 del menu
int maxVector(double *v, int tam)
{
	int des = 0;
	double max = v[0];
	
	for(int i=1;i<tam;i++){
		if(max < v[i]){
			max = v[i];
			des = i;
		}
	}
	
	return(des);
}

//Funcion auxiliar opcion 3 del menu
int minVector(double *v, int tam)
{
	int des = 0;
	double min = v[0];
	
	for(int i=1;i<tam;i++){
		if(min > v[i]){
			min = v[i];
			des = i;
		}
	}
	
	return(des);
}

//Funcion opcion 2 del menu
void Grafo::calculaMaximo()
{
	double *distancias;
	int *predecesores;
	int origen, destino;

	predecesores = new int[verNumeroNodos()];
	distancias = new double[verNumeroNodos()];
	
	cout << "\nElija la provincia de origen:" << endl;
	origen = menuProvincias();
	
	Dijkstra(distancias, predecesores, origen);
	destino = maxVector(distancias, verNumeroNodos());
	
	cout << "\nLa distancia maxima es: " << distancias[destino] << endl;
	cout << "La ciudad mas lejana es " << mostrarProvincia(destino) << " y su camino:\n" << endl;
	camino(origen, destino, predecesores);

	delete[] distancias;
	delete[] predecesores;
}

//Funcion opcion 3 del menu
void Grafo::ciudadCercana()
{
	double *distancias;
	double *sumas;
	int *predecesores;
	int i, j;
	double aux = 0.0;

	predecesores = new int[verNumeroNodos()];
	distancias = new double[verNumeroNodos()];
	sumas = new double[verNumeroNodos()];
	
	for(i=0;i<verNumeroNodos();i++){
		Dijkstra(distancias, predecesores, i);
		aux = 0.0;
		for(j=1;j<verNumeroNodos();j++){
			if(distancias[j] < INF){
				aux += distancias[j];
			}
		}
		sumas[i] = aux;
	}
	
	cout << "\nLa ciudad mas cercana al resto es: " << mostrarProvincia(minVector(sumas, verNumeroNodos())) << endl;

	delete[] distancias;
	delete[] predecesores;
}

//Funcion auxiliar opcion 3 del menu
void Grafo::calculaDistancias(double *d, int *p, int origen)
{
	int i, j;
	int *s;
	double minimo;
	int x;

	s = new int[verNumeroNodos()];

	for(i=0;i<verNumeroNodos();i++){
		p[i] = origen;
		d[i] = verPeso(origen, i);
		s[i] = 0;
	}

	s[origen] = 1;

	for(i=0;i<verNumeroNodos()-1;i++){
		/* Buscar Nodo de distancia minima */
		minimo = INF;
		
		for(j=0;j<verNumeroNodos();j++){
			if((d[j] <= minimo) && (s[j] == 0)){
				minimo = d[j];
				x = j;
			}
		}
		
		s[x] = 1; /* El nodo x pasa al conjunto s */
		
		/* Comprobamos si el nodo x acorta las distancias */
		for(j=0;j<verNumeroNodos();j++){
			if((s[j] == 0) && (d[j] > d[x]+verPeso(x, j))){
				d[j] = d[x]+verPeso(x, j);
				p[j] = x;
			}
		}
	}
	
	delete[] s;
}

#endif

