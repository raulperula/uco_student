#ifndef _COLA_H_
#define _COLA_H_

/**
 * @file    cola.h
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
#include <string>
#include <list>

using namespace std;

class Grafo;

class Cola
{
   friend class Grafo;

public:

	void insertarCola(int);
	int extraerCola();
	int colaVacia();
	
private:
	list<int> il;
	
};


void Cola::insertarCola(int n)
{
	il.resize(il.size()+1);
	il.push_front(n);
}

int Cola::extraerCola()
{
	list<int>::iterator it = il.end();
	it--;
	int aux = *it;

	il.pop_back();
	
	return(aux);
}

int Cola::colaVacia()
{
	return(il.empty());
}

#endif

