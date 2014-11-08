#ifndef _MORPHUTILS_H_
#define _MORPHUTILS_H_

/**
 * @file    morphologicalutils.h
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
#include <image.h>
#include <imageexception.h>
#include <imagearith.h>

using namespace std;

class MorphologicalUtils
{
public:
	/** Erosion of an image */
	static void erode(const Image &in, Image &out, int maskSize = 3) throw(ImageException)
	{
		unsigned char *auxIn, *auxOut;
		int cont = 0;
		
		/** Se comprueba que la imagen de entrada este cargada */
		if(in.getType() == -1){
			throw ImageException("Error en 'dilate(in,out,maskSize)': imagen de entrada no cargada previamente");
		}
		if(maskSize%2 == 0){
			throw ImageException("Error en 'dilate(in,out,maskSize)': tamaño de la mascara par");
		}

		auxIn = in.getData();
		out.resize(in.getWidth(), in.getHeight(), in.getType());
		auxOut = out.getData();
		
		/** Se recorre la imagen */
		for(int i=0;i<in.getWidth()*in.getHeight();i++){
			/** Se recorre la mascara */
			for(int j=0;j<maskSize*maskSize;){
				/** Se calcula el nuevo valor.
					* Como los elementos que cambian son 'l' y 'j', se incrementan sus
					*	valores a la vez */
				for(int k=-(maskSize/2);k<=maskSize/2;k++){
					for(int l=-(maskSize/2);l<=maskSize/2;l++,j++){
						/** Comprobacion de que los elementos de la mascara estan dentro del
							* rango */
						if(((i+k*in.getWidth()+l) > 0) && ((i+k*in.getWidth()+l) < in.getWidth()*in.getHeight()*in.getType())){
							if(auxIn[i+k*in.getWidth()+l] == 255){
								cont++;
							}
						}
						else{
							cont++;
						}
					}
				}
			}
			if(cont == maskSize*maskSize){
				auxOut[i] = 255;
			}
			else{
				auxOut[i] = 0;
			}
			cont = 0;
		}
	}
	
	/** Dilation of an image */
	static void dilate(const Image &in, Image &out, int maskSize = 3) throw(ImageException)
	{
		unsigned char *auxIn, *auxOut;
		
		/** Se comprueba que la imagen de entrada este cargada */
		if(in.getType() == -1){
			throw ImageException("Error en 'dilate(in,out,maskSize)': imagen de entrada no cargada previamente");
		}
		if(maskSize%2 == 0){
			throw ImageException("Error en 'dilate(in,out,maskSize)': tamaño de la mascara par");
		}

		auxIn = in.getData();
		out.resize(in.getWidth(), in.getHeight(), in.getType());
		auxOut = out.getData();
		
		/** Se recorre la imagen */
		for(int i=0;i<in.getWidth()*in.getHeight();i++){
			/** Se recorre la mascara */
			for(int j=0;j<maskSize*maskSize;){
				/** Se calcula el nuevo valor.
					* Como los elementos que cambian son 'l' y 'j', se incrementan sus
					*	valores a la vez */
				for(int k=-(maskSize/2);k<=maskSize/2;k++){
					for(int l=-(maskSize/2);l<=maskSize/2;l++,j++){
						/** Comprobacion de que los elementos de la mascara estan dentro del
							* rango */
						if(((i+k*in.getWidth()+l) > 0) && ((i+k*in.getWidth()+l) < in.getWidth()*in.getHeight()*in.getType())){
							if(auxIn[i] == 255){
								auxOut[i+k*in.getWidth()+l] = 255;
							}
						}
					}
				}
			}
		}
	}
	 
	/** Remove noise preserving dimensions (opening=erosion+dilation) */
	static void open(const Image &in, Image &out, int maskSize = 3) throw(ImageException)
	{
		Image aux;
		
		/** Se comprueba que la imagen de entrada este cargada */
		if(in.getType() == -1){
			throw ImageException("Error en 'open(in,out,maskSize)': imagen de entrada no cargada previamente");
		}
		if(maskSize%2 == 0){
			throw ImageException("Error en 'open(in,out,maskSize)': tamaño de la mascara par");
		}

		/** Se calculan las imagenes dilatada y erosionada. Se hace: out = E+D */
		erode(in, aux);
		dilate(aux, out);
	}
	 
	/** Remove noise preserving dimensions (close=dilation+erosion) */
	static void close(const Image &in, Image &out, int maskSize = 3) throw(ImageException)
	{
		Image aux;
		
		/** Se comprueba que la imagen de entrada este cargada */
		if(in.getType() == -1){
			throw ImageException("Error en 'close(in,out,maskSize)': imagen de entrada no cargada previamente");
		}
		if(maskSize%2 == 0){
			throw ImageException("Error en 'close(in,out,maskSize)': tamaño de la mascara par");
		}

		/** Se calculan las imagenes dilatada y erosionada. Se hace: out = D+E */
		dilate(in, aux);
		erode(aux, out);
	}
	 
	/** Extracts outer contour (contour=dilate-original) */
	static void outerContour(const Image &in, Image &out) throw(ImageException)
	{
		Image D;
		
		/** Se comprueba que la imagen de entrada este cargada */
		if(in.getType() == -1){
			throw ImageException("Error en 'outerContour(in,out)': imagen de entrada no cargada previamente");
		}
		
		/** Calculo de la imagen dilatada */
		dilate(in, D);
		out = D;
		
		/** Se hace: out = D-in */
		ImageArith::sub(out, in);
	}
};

#endif

