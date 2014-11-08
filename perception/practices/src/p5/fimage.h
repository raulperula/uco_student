#ifndef _FIMAGE_H_
#define _FIMAGE_H_

/**
 * @file    fimage.h
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

class FImage
{
friend class ImageArith;
friend class LinearContrast;

public:

    FImage();

    /** Crea una imagen con un tamaño y tipo indicado y con un valor por defecto */
    FImage(const FImage & I);

    /** Crea una imagen con un tamaño y tipo indicado y con un valor por defecto */
    FImage(int w, int h, int type = GREY, unsigned char c = 0);

    ~FImage();

    int getWidth() const;
    int getHeight() const;
    int getType() const;
    float * getData() const;

    void loadFromFile(string) throw(ImageException);
    void saveToFile(string) throw(ImageException);

    /** Accede al elemento x,y de una imagen y modificarlo. Permite hacer cosas como
    * FImage I(100,100,0,10);
    * I(10,10)=19;
    * cout <<I(10,10)
    */
    float & operator()(unsigned int x, unsigned int y, unsigned int c = 0) throw(ImageException);

    /** Asigna al elemento x un valor */
    float & operator()(unsigned int x) throw(ImageException);

    /** Operador de asignación */
    FImage &operator=(const FImage &I) throw(ImageException);

    /** Operador de asignación. Asigna a todos los pixels el mismo valor */
    FImage &operator=(float v) throw(ImageException);

    /** Funcion de reasignacion de tamaño de una imagen */
    void resize(int width, int height, int type) throw(ImageException);

private:
    int _width, _height;
    int _type;                      //0->GREY, 1->COLOR
    float * _data;
};

#endif

