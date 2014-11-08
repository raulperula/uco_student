#ifndef _IMAGE_H_
#define _IMAGE_H_

/**
 * @file    image.h
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
#include <cstring>
#include <imageexception.h>

using namespace std;

class Image
{
friend class ImageArith;

public:

	Image();
	
	/** Crea una imagen con un tamaño y tipo indicado y con un valor por defecto */
	Image(const Image & I);
	
	/** Crea una imagen con un tamaño y tipo indicado y con un valor por defecto */
	Image(int w, int h, int type = 0, unsigned char c = 0);
	
	~Image();
	
	int getWidth();
	int getHeigth();
	int getType();
	
	void loadFromFile(string) throw(ImageException);
	void saveToFile(string) throw(ImageException);
	
	/** Accede al elemento x,y de una imagen y modificarlo. Permite hacer cosas como
	* Image I(100,100,0,10);
	* I(10,10)=19;
	* cout <<I(10,10)
	*/
	unsigned char & operator()(unsigned int x, unsigned int y, unsigned int c = 0) throw(ImageException);
	
	/** Operador de asignación */
	Image &operator=(const Image &I) throw(ImageException);
	
	/** Operador de asignación. Asigna a todos los pixels el mismo valor */
	Image &operator=(unsigned char v) throw(ImageException);
	
private:
	int _width, _heigth;
	int _type;						//0->GREY, 1->COLOR
	unsigned char * _data;
};

#endif
