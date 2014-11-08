#ifndef _LINEARCONTRAST_H_
#define _LINEARCONTRAST_H_

/**
 * @file    linearcontrast.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <linearfunction.h>

using namespace std;

class LinearContrast
{
public:
	/** Applies a linear function to change the contrast of the image passed
	*@param in: input image
	*@param out: output image
	*@param lf: linear function defining the operation to do
	*/
	void applyFunction(Image &in, Image &out, LinearFunction lf) throw(ImageException)
	{
		int i, j = 0;
		unsigned char v[256];
		float x1, x2, y1, y2;
		float m, c;
		
		/* Se rellena el vector con los nuevos valores que tendra la nueva imagen */
		for(i=0;i<256;i++){
			x1 = (lf.get(j)).first;
			y1 = (lf.get(j)).second;
			x2 = (lf.get(j+1)).first;
			y2 = (lf.get(j+1)).second;
			
			if(i == x2){
				j++;
			}	
			
			m = (y2-y1)/(x2-x1);
			c = y1-m*x1;
			
			v[i] = m*i+c;
//			cout <<i<<' '<<(int) v[i] <<endl;
		}
		
		out._width = in._width;
		out._height = in._height;
		out._type = in._type;
		if(out._type == -1){
			throw ImageException("Error: imagen no cargada previamente");
		}
		out._data = new unsigned char[in._width*in._height*in._type];
		
		for(i=0;i<in._width*in._height*in._type;i++){
			out._data[i] = v[in._data[i]];
		}
	}
};

#endif

