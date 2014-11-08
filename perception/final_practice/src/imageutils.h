#ifndef _IMAGEUTILS_H_
#define _IMAGEUTILS_H_

/**
 * @file    imageutils.h
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
#include <math.h>
#include <image.h>
#include <fimage.h>
#include <imageexception.h>
#include <histogram.h>

using namespace std;

class ImageUtils{
public:
	/** Converts an Image to a Fimage */
	static void convert(const Image &in, FImage &out) throw(ImageException)
	{
		unsigned char * auxIn;
		float * auxOut;

		/** Se comprueba que la imagen de entrada este cargada */
		if(in.getType() == -1){
			throw ImageException("Error en 'convert(Image,FImage)': imagen de entrada no cargada previamente");
		}

		/** Se redimensiona la imagen de salida */
		out.resize(in.getWidth(), in.getHeight(), in.getType());
		auxIn = in.getData();
		auxOut = out.getData();

		for(int i=0;i<in.getWidth()*in.getHeight()*in.getType();i++){
			auxOut[i] = (float) auxIn[i];
		}
	}

	/** Converts a FImage to an Image	*/
	static void convert(const FImage &in, Image &out) throw(ImageException)
	{
		float * auxIn;
		unsigned char * auxOut;

		/** Se comprueba que la imagen de entrada este cargada */
		if(in.getType() == -1){
			throw ImageException("Error en 'convert(FImage,Image)': imagen de entrada no cargada previamente");
		}

		/** Se redimensiona la imagen de salida */
		out.resize(in.getWidth(), in.getHeight(), in.getType());
		auxIn = in.getData();
		auxOut = out.getData();

		for(int i=0;i<in.getWidth()*in.getHeight()*in.getType();i++){
			auxOut[i] = (unsigned char) auxIn[i];
		}
	}

	/** Escales the input to the range of the output
	* The function sets in "out" the image in "in" escaling the input range to the
	* output range [0,255] */
	static void scale(const FImage &in, Image &out) throw(ImageException)
	{
		float * auxIn;
		unsigned char * auxOut;
		float max, min, a, b;

		/** Se comprueba que la imagen de entrada este cargada */
		if(in.getType() == -1){
			throw ImageException("Error en 'scale(FImage,Image)': imagen de entrada no cargada previamente");
		}

		auxIn = in.getData();
		out.resize(in.getWidth(), in.getHeight(), in.getType());
		auxOut = out.getData();

		/** Se buscan los valores maximo y minimo */
		max = min = auxIn[0];
		for(int i=1;i<in.getWidth()*in.getHeight()*in.getType();i++){
			if(max < auxIn[i]){
				max = auxIn[i];
			}
			if(min > auxIn[i]){
				min = auxIn[i];
			}
		}

		/** Se hace el cambio de coordenadas */
		a = (255.0-0.0)/(max-min);
		b = 255.0-a*max;

		for(int i=1;i<in.getWidth()*in.getHeight()*in.getType();i++){
			auxOut[i] = (unsigned char) roundf(a*auxIn[i]+b);
		}
	}

	/** Convolves image "in" with mask "mask" and set the result in "out"	*/
	static void convolve(const FImage &in, const FImage &mask, FImage &out) throw(ImageException)
	{
		int i, j, k, l, tam;
		float *auxIn, *auxOut, *auxMask;
			
		if(in.getType() == -1){
			throw ImageException("la imagen es nula");
		}
		else if(mask.getType() == -1){
			throw ImageException("la mascara es nula");
		}
		else
		{
			auxIn = in.getData();
			auxMask = mask.getData();
			tam = mask.getHeight()/2;
			out.resize(in.getWidth(), in.getHeight(), in.getType());
			auxOut = out.getData();
			for(i=0;i<in.getWidth()*in.getHeight();i++){
				l = 0;
				auxOut[i] = 0;
				for(j=i-tam*in.getWidth();j<=i+tam*in.getWidth();j+=in.getWidth()){
					for(k=j-tam;k<=j+tam;k++){
						if((k < 0) || (k > in.getWidth()*in.getHeight())){
							auxOut[i] += 128*auxMask[l];
						}
						else{
							auxOut[i] += auxIn[k]*auxMask[l];
						}
						l++;
					}
				}
			}
		}
	}

	/** Calculates Sobel modulus and gradient of an image. */
	static void Sobel(const FImage &in, FImage &mod, FImage &grad) throw(ImageException)
	{
		float *maskV, *maskH, *auxV, *auxH;
		float *auxMod, *auxGrad;
		FImage V, H;
		FImage compH, compV;

		/** Se comprueba que la imagen de entrada este cargada */
		if(in.getType() == -1){
			throw ImageException("Error en 'Sobel(FImage in,mod,grad)': imagen de entrada no cargada previamente");
		}

		/** Se crean las mascaras y se le asignan los valores */
		V.resize(3, 3, GREY);
		maskV = V.getData();
		maskV[0] = -1.0;
		maskV[1] = -2.0;
		maskV[2] = -1.0;
		maskV[6] = 1.0;
		maskV[7] = 2.0;
		maskV[8] = 1.0;
		maskV[3] = maskV[4] = maskV[5] = 0.0;

		H.resize(3, 3, GREY);
		maskH = H.getData();
		maskH[0] = -1.0;
		maskH[2] = 1.0;
		maskH[3] = -2.0;
		maskH[5] = 2.0;
		maskH[6] = -1.0;
		maskH[8] = 1.0;
		maskH[1] = maskH[4] = maskH[7] = 0.0;

		/** Se aplican las mascaras */
		convolve(in, H, compH);
		convolve(in, V, compV);

		auxH = compH.getData();
		auxV = compV.getData();

		mod.resize(in.getWidth(), in.getHeight(), in.getType());
		auxMod = mod.getData();
		grad.resize(in.getWidth(), in.getHeight(), in.getType());
		auxGrad = grad.getData();

		/** Se calculan los valores del modulo y el gradiente */
		for(int i=0;i<in.getWidth()*in.getHeight()*in.getType();i++){
			auxMod[i] = sqrt(auxV[i]*auxV[i]+auxH[i]*auxH[i]);
			if(auxH[i] == 0){
				auxGrad[i] = 0;
			}
			else{
				auxGrad[i] = atan2(auxV[i],auxH[i]);
				if(auxGrad[i] < 0){
					auxGrad[i] = 2*M_PI+auxGrad[i];
				}
			}
		}
	}

	/** Applys a mean filter to the image passed with the size indicated */
	static void MeanMask(const FImage &in, int maskSize, FImage &out) throw(ImageException)
	{
		float *auxIn, *auxMask;
		FImage mask;

		/** Se comprueba que la imagen de entrada este cargada */
		if(in.getType() == -1){
			throw ImageException("Error en 'MeanMask(FImage in,maskSize,FImage out)': imagen de entrada no cargada previamente");
		}
		if(maskSize%2 == 0){
			throw ImageException("Error en 'MeanMask(FImage in,maskSize,FImage out)': tamaño de la mascara par");
		}

		auxIn = in.getData();

		/** Se crea la mascara y se le asignan los valores */
		mask.resize(maskSize, maskSize, in.getType());
		auxMask = mask.getData();
		for(int i=0;i<mask.getWidth()*mask.getHeight()*mask.getType();i++){
			auxMask[i] = 1.0/(maskSize*maskSize);
		}

		/** Se aplica la mascara */
		convolve(in, mask, out);
	}

	/** Applys a gaussian convolution with the sigma indicated.
	* Remember that masksize = 4*sigma+1. */
	static void GaussianMask(const FImage &in, float sigma, FImage &out) throw(ImageException)
	{
		float *auxIn, *auxMask;
		FImage mask;
		float maskSize = 4*sigma+1;
		int k = 0;

		/** Se comprueba que la imagen de entrada este cargada */
		if(in.getType() == -1){
			throw ImageException("Error en 'GaussianMask(FImage in,sigma,FImage out)': imagen de entrada no cargada previamente");
		}
		if(sigma == 0){
			throw ImageException("Error en 'GaussianMask(FImage in,sigma,FImage out)': valor de sigma, division por 0");
		}

		auxIn = in.getData();

		/** Se crea la mascara y se le asignan los valores */
		mask.resize(maskSize, maskSize, in.getType());
		auxMask = mask.getData();
		for(int i=-(maskSize/2);i<=maskSize/2;i++){
			for(int j=maskSize/2;j>=-(maskSize/2);j--){
				auxMask[k] = (1.0/(2.0*M_PI*sigma*sigma))*exp((-1.0/2.0)*(((i*i)/(sigma*sigma))+(((j*j)/(sigma*sigma)))));
				k++;
			}
		}

		/** Se aplica la mascara */
		convolve(in, mask, out);
	}

	/** Ecualize an image */
	static void ecualize(const Image &in, Image &out) throw(ImageException)
	{
		Histogram H;
		unsigned char *auxIn, *auxOut, *nValor;

		if(in.getType() == -1){
			throw ImageException("Error en 'ecualize(Image in,Image out)': imagen de entrada no cargada previamente");
		}

		nValor = new unsigned char[256];

		/** Se calculan los nuevos niveles */
		H.calculate(in, 256, true, true);
		for(int i=0;i<(int)H.size();i++){
			nValor[i] = trunc(H[i]*255);
		}

		auxIn = in.getData();
		out.resize(in.getWidth(), in.getHeight(), in.getType());
		auxOut = out.getData();

		/** Se crea la imagen de salida */
		for(int i=0;i<in.getWidth()*in.getHeight()*in.getType();i++){
			auxOut[i] = nValor[auxIn[i]];
		}
	}
	
	/** Segmentates the image passed. By default, the function sets to 0 all 
		*	values in 'in' below the value 'th', and to 255 the rest.
		* However, if 'invert' is set, the result is the opposite.
		*@param in, out images
		*@param th threshold value
		*@param invert the result
	*/
	static void fixedThreshold(const Image &in, Image &out, unsigned char th, bool invert = false) throw(ImageException)
	{
		unsigned char *auxIn, *auxOut;
		
		if(in.getType() == -1){
			throw ImageException("Error en 'fixedThreshold(Image in,Image out,th,invert)': imagen de entrada no cargada previamente");
		}
		
		auxIn = in.getData();
		out.resize(in.getWidth(), in.getHeight(), in.getType());
		auxOut = out.getData();
		
		if(invert){
			for(int i=0;i<in.getWidth()*in.getHeight()*in.getType();i++){
				if(auxIn[i] < th){
					auxOut[i] = 255;
				}
				else{
					auxOut[i] = 0;
				}
			}
		}
		else{
			for(int i=0;i<in.getWidth()*in.getHeight()*in.getType();i++){
				if(auxIn[i] < th){
					auxOut[i] = 0;
				}
				else{
					auxOut[i] = 255;
				}
			}
		}
	}
	
	/** Algoritmo de Canny */
	static void canny(const FImage &in, FImage &mod, FImage &grad, Image &out, float t1, float t2) throw(ImageException)
	{
		FImage auxIn, FI;
		Image I, auxOut, Ima, Im;
		float Pixel_izq = 0.0;
		float Pixel_der = 0.0;
		float nt1 = 0.0, nt2 = 0.0;
		float max = 0.0, min = 0.0;
		int i, j;

		/** Se comprueba que la imagen de entrada este cargada */
		if(in.getType() == -1){
			throw ImageException("Error en 'canny(in,out,t1,t2)': imagen de entrada no cargada previamente");
		}
		/** Se comprueba que el umbral primero sea mayor que el segundo */
		if(t1 > t2){
			throw ImageException("Error en 'canny(in,out,t1,t2)': umbral 1 mayor que umbral 2");
		}

/** -------------------- Paso primero: Suavizado Gausiano ------------------- */
		
		GaussianMask(in, 1, auxIn);

/** -------------------- Paso segundo: Supresion no maxima ------------------ */
		
		/** Calculo del modulo y el angulo del gradiente */
		Sobel(auxIn, mod, grad);

		/** Sectorizacion del angulo del gradiente */
		for(i=0;i<auxIn.getWidth();i++){
			for(j=0;j<auxIn.getHeight();j++){
				grad(i, j) = trunc((grad(i, j)/(2*M_PI))*8);
				if(grad(i, j) == 8){
					grad(i, j) = 0;
				}
			}
		}

		/** Calculo del nuevo modulo del gradiente */
		FI.resize(auxIn.getWidth(), auxIn.getHeight(), auxIn.getType());

		for(i=1;i<auxIn.getWidth()-1;i++){
			for(j=1;j<auxIn.getHeight()-1;j++){
				if(grad(i, j) == 0 || grad(i, j) == 4){
					Pixel_izq = mod(i+1, j);
					Pixel_der = mod(i-1, j);
				}
				else if(grad(i, j) == 1 || grad(i, j) == 5){
					Pixel_izq = mod(i-1, j-1);
					Pixel_der = mod(i+1, j+1);
				}
				else if(grad(i, j) == 2 || grad(i, j) == 6){
					Pixel_izq = mod(i, j-1);
					Pixel_der = mod(i, j+1);
				}
				else if(grad(i, j) == 3 || grad(i, j) == 7){
					Pixel_izq = mod(i+1, j-1);
					Pixel_der = mod(i-1, j+1);
				}
			
				if((mod(i, j) <= Pixel_izq) || (mod(i, j) <= Pixel_der)){
					FI(i, j) = 0;
				}
				else{
					FI(i, j) = mod(i, j);
				}
			}
		}

/** -------------------- Paso tercero: Histeresis --------------------------- */
		
		/** Se calcula el histograma normalizado acumulado para poder concretar los
				valores de t1 y t2 */
		Histogram H;
		H.calculate(mod, 1000, true, true);

		encuentraMaxMin(mod, max, min);
		
		for(i=0;i<(int)H.size();i++){
			if(H[i] < t1){
				nt1 = ((max-min)/1000)*(float)i+min;
			}
			else if((H[i] > t1) && (H[i] < t2)){
				nt2 = ((max-min)/1000)*(float)i+min;
			}
		}

		/** Calculamos cuales son borde y cuales no, para ello se necesita saber:
					auxOut = 0, no visitado
					auxOut = 1, borde
					auxOut = 2, no borde
		*/
		out.resize(auxIn.getWidth(), auxIn.getHeight(), auxIn.getType());
		auxOut.resize(auxIn.getWidth(), auxIn.getHeight(), auxIn.getType());
		auxOut = 0;
		
		/** Se da una pasada para comprobar cuales son bordes seguros y cuales no */
		for(i=0;i<FI.getWidth();i++){
			for(j=0;j<FI.getHeight();j++){
				if(FI(i, j) < nt1){
					out(i, j) = 0;
					auxOut(i, j) = 2;
				}
				else if(FI(i, j) > nt2){
					out(i, j) = 255;
					auxOut(i, j) = 1;
				}
			}
		}
		
		/** Se da la segunda pasada donde si un pixel es borde se recorre en la
				direccion de su gradiente y se pone a borde dicho pixel */
//		for(i=1;i<FI.getWidth()-1;i++){
//			for(j=1;j<FI.getHeight()-1;j++){
//				if(auxOut(i, j) == 1){
//					recursiva(auxOut, FI, nt1, grad, out, i, j);
//				}
//			}
//		}
	}
	
	static void encuentraMaxMin(FImage I, float &max, float &min)
	{
		max = min = I[0];
		for(int i=1;i<I.getWidth()*I.getHeight()*I.getType();i++){
			if(max < I[i]){
				max = I[i];
			}
			if(min > I[i]){
				min = I[i];
			}
		}
	}
	
	static void recursiva(Image &auxOut, FImage &FI, float nt1, FImage &grad, Image &out, int i, int j)
	{
		if(((i > 1) && (i < auxOut.getWidth()-1)) && ((j > 1) && (j < auxOut.getHeight()-1))){
			if(grad(i, j) == 0 || grad(i, j) == 4){
				if(auxOut(i, j-1) == 0 && FI(i, j-1) > nt1){
					out(i, j-1) = 255;
					auxOut(i, j-1) = 1;
					recursiva(auxOut, FI, nt1, grad, out, i, j-1);
				}
				if(auxOut(i, j+1) == 0 && FI(i, j+1) > nt1){
					out(i, j+1) = 255;
					auxOut(i, j+1) = 1;
					recursiva(auxOut, FI, nt1, grad, out, i, j+1);
				}
			}
			else if(grad(i, j) == 1 || grad(i, j) == 5){
				if(auxOut(i+1, j-1) == 0 && FI(i+1, j-1) > nt1){
					out(i+1, j-1) = 255;
					auxOut(i+1, j-1) = 1;
					recursiva(auxOut, FI, nt1, grad, out, i+1, j-1);
				}
				if(auxOut(i-1, j+1) == 0 && FI(i-1, j+1) > nt1){
					out(i-1, j+1) = 255;
					auxOut(i-1, j+1) = 1;
					recursiva(auxOut, FI, nt1, grad, out, i-1, j+1);
				}
			}
			else if(grad(i, j) == 2 || grad(i, j) == 6){
				if(auxOut(i+1, j) == 0 && FI(i+1, j) > nt1){
					out(i+1, j) = 255;
					auxOut(i+1, j) = 1;
					recursiva(auxOut, FI, nt1, grad, out, i+1, j);
				}
				if(auxOut(i-1, j) == 0 && FI(i-1, j) > nt1){
					out(i-1, j) = 255;
					auxOut(i-1, j) = 1;
					recursiva(auxOut, FI, nt1, grad, out, i-1, j);
				}
			}
			else if(grad(i, j) == 3 || grad(i, j) == 7){
				if(auxOut(i-1, j-1) == 0 && FI(i-1, j-1) > nt1){
					out(i-1, j-1) = 255;
					auxOut(i-1, j-1) = 1;
					recursiva(auxOut, FI, nt1, grad, out, i-1, j-1);
				}
				if(auxOut(i+1, j+1) == 0 && FI(i+1, j+1) > nt1){
					out(i+1, j+1) = 255;
					auxOut(i+1, j+1) = 1;
					recursiva(auxOut, FI, nt1, grad, out, i+1, j+1);
				}
			}
		}
	}
	
};

#endif

