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

    /** Converts a FImage to an Image   */
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

    /** Convolves image "in" with mask "mask" and set the result in "out"   */
    static void convolve(const FImage &in, const FImage &mask, FImage &out) throw(ImageException)
    {
        float *auxIn, *auxOut, *auxMask;
        float subTotal = 0.0;

        /** Se comprueban los posibles errores */
        if((mask.getWidth()%2 == 0) || (mask.getHeight()%2 == 0)){
            throw ImageException("Error en 'convolve(Fimage in,mask,FImage out)': dimensiones de la mascara erroneas");
        }
        if((in.getType() == -1) || (mask.getType() == -1)){
            throw ImageException("Error en 'convolve(Fimage in,mask,FImage out)': imagen de entrada no cargada previamente");
        }
        if(in.getType() != mask.getType()){
            throw ImageException("Error en 'convolve(Fimage in,mask,FImage out)': tipos distintos, imagen de entrada y mascara");
        }

        auxIn = in.getData();
        out.resize(in.getWidth(), in.getHeight(), in.getType());
        auxOut = out.getData();
        auxMask = mask.getData();

        /** Para aplicar la mascara habra que acceder a los elementos adyacentes, ej.
            x-2n-2  x-2n-1  x-2n-0  x-2n+1  x-2n+2  |   20-2*8-2=2  20-2*8-1=3  20-2*8+0=4  20-2*8+1=5  20-2*8+2=6
            x-1n-2  x-1n-1  x-1n-0  x-1n+1  x-1n+2  |   20-1*8-2=10 20-1*8-1=11 20-1*8+0=12 20-1*8+1=13 20-1*8+2=14
            x-0n-2  x-0n-1  x-0n-0  x+0n+1  x+0n+2  |   20+0*8-2=18 20+0*8-1=19 20+0*8+0=20 20+0*8+1=21 20+0*8+2=22
            x+1n-2  x+1n-1  x+1n-0  x+1n+1  x+1n+2  |   20+1*8-2=26 20+1*8-1=27 20+1*8+0=28 20+1*8+1=29 20+1*8+2=30
            x+2n-2  x+2n-1  x+2n-0  x+2n+1  x+2n+2  |   20+2*8-2=34 20+2*8-1=35 20+2*8+0=36 20+2*8+1=37 20+2*8+2=38
        */
        /** Se recorre la imagen */
        for(int i=0;i<in.getWidth()*in.getHeight();i++){
            /** Se recorre la mascara */
            for(int j=0;j<mask.getWidth()*mask.getHeight();){
                /** Se calcula el nuevo valor.
                    * Como los elementos que cambian son 'l' y 'j', se incrementan sus
                    *   valores a la vez */
                for(int k=-(mask.getWidth()/2);k<=mask.getWidth()/2;k++){
                    for(int l=-(mask.getWidth()/2);l<=mask.getWidth()/2;l++,j++){
                        /** Si los elementos adyacentes no existen */
                        if(((i+k*in.getWidth()+l) < 0) || ((i+k*in.getWidth()+l) > in.getWidth()*in.getHeight()*in.getType())){
                            subTotal += 128.0;
                        }
                        else{
                            subTotal += auxIn[i+k*in.getWidth()+l]*auxMask[j];
                        }
                    }
                }
            }
            auxOut[i] = subTotal;
            subTotal = 0.0;
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
            auxGrad[i] = atan(auxV[i]/auxH[i]);
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
        *   values in 'in' below the value 'th', and to 255 the rest.
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
};

#endif

