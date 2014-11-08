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
public:
	Image();
	~Image();
	
	int getWidth();
	int getHeigth();
	int getType();
	
	void loadFromFile(string) throw(ImageException);
	void saveToFile(string) throw(ImageException);
	
private:
	int _width, _heigth;
	int _type;						//0->GREY, 1->COLOR
	unsigned char * _data;
	int _gris;
};

#endif

