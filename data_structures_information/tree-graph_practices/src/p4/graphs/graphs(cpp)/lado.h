#ifndef _LADO_H_
#define _LADO_H_

/**
 * @file    lado.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <vector>
#include <iostream>

using namespace std;

class Grafo;

class Lado
{
   friend class Grafo;
   
public:
	Lado();
	Lado(double, int, int);
	Lado(const Lado & );
	~Lado();
	
	Lado & operator=(const Lado &);
	
	double getPeso();
	int getOrigen();
	int getDestino();
	void setPeso(double);
	void setOrigen(int);
	void setDestino(int);
	
private:
	double _peso;
	int _origen;
	int _destino;
	
};

Lado::Lado()
{
	_peso = 0.0;
	_origen = 0;
	_destino = 0;
}

Lado::Lado(double peso, int origen, int destino)
{
	_peso = peso;
	_origen = origen;
	_destino = destino;
}

Lado::Lado(const Lado & L)
{
	_peso = L._peso;
	_origen = L._origen;
	_destino = L._destino;
}

Lado::~Lado()
{

}

Lado & Lado::operator=(const Lado & L)
{
	_peso = L._peso;
	_origen = L._origen;
	_destino = L._destino;
	
	return *this;
}

double Lado::getPeso()
{
	return(_peso);
}

int Lado::getOrigen()
{
	return(_origen);
}

int Lado::getDestino()
{
	return(_destino);
}

void Lado::setPeso(double peso)
{
	_peso = peso;
}

void Lado::setOrigen(int origen)
{
	_origen = origen;
}

void Lado::setDestino(int destino)
{
	_destino = destino;
}

#endif

