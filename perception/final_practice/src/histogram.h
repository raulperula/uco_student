#ifndef _HISTOGRAM_H_
#define _HISTOGRAM_H_

/**
 * @file    histogram.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <image.h>
#include <fimage.h>
#include <imageexception.h>

class Histogram
{
public:

	/** Empty constructor */
	Histogram()
	{
		_bins = NULL;
		_nBins = 0;
		_isNormalized = false;
		_isAccumulated = false;
		_isValid = false;
	}

	/** Copy constructor */
	Histogram(const Histogram &H)
	{
		_nBins = H._nBins;
		_isNormalized = H._isNormalized;
		_isAccumulated = H._isAccumulated;
		_isValid = H._isValid;

		if(_bins != NULL){
			delete[] _bins;
		}
		_bins = new float[_nBins];
		for(int i=0;i<(int)_nBins;i++){
			_bins[i] = H._bins[i];
		}
	}

	/** Creates the histogram from an Image.
	*@param nBins of the histogram
	*@param createNormalized indicates if must create the normalized histogram
	*@param createAccumulated indicates if must create the accumulated histogram
	*/
	void calculate(const Image &I, int nBins = 256, bool createNormalized = true, bool createAccumulated = false) throw(ImageException)
	{
		unsigned char *auxData;

		auxData = I.getData();

		if(_bins != NULL){
			delete[] _bins;
		}
		_bins = new float[nBins];
		_nBins = nBins;
		_isNormalized = createNormalized;
		_isAccumulated = createAccumulated;

		/** Se ponen todos los elementos del histograma a 0 inicialmente */
		memset(_bins, 0.0, sizeof(float)*nBins);

		for(int i=0;i<I.getWidth()*I.getHeight()*I.getType();i++){
			_bins[auxData[i]]++;
		}

		if(createNormalized && createAccumulated){
			/** Histograma normalizado acumulado */

			/** Normalizado */
			for(int i=0;i<nBins;i++){
				_bins[i] /= I.getWidth()*I.getHeight();
			}

			/** Acumulado */
			for(int i=1;i<nBins;i++){
				_bins[i] += _bins[i-1];
			}
		}
		else if(createNormalized){
			/** Histograma normalizado */
			for(int i=0;i<nBins;i++){
				_bins[i] /= I.getWidth()*I.getHeight();
			}
		}
		else if(createAccumulated){
			/** Histograma acumulado */
			for(int i=1;i<nBins;i++){
				_bins[i] += _bins[i-1];
			}
		}
	}

	/** Creates the histogram from a FImage.
	*@param nBins of the histogram
	*@param createNormalized indicates if must create the normalized histogram
	*@param createAccumulated indicates if must create the accumulated histogram
	*/
	void calculate(const FImage &I, int nBins = 100, bool createNormalized = true, bool createAccumulated = false)
	{
		float *auxData;
		float max, min, a, b;

		auxData = I.getData();

		if(_bins != NULL){
			delete[] _bins;
		}
		_bins = new float[nBins];
		_nBins = nBins;
		_isNormalized = createNormalized;
		_isAccumulated = createAccumulated;

		/** Se ponen todos los elementos del histograma a 0 inicialmente */
		memset(_bins, 0.0, sizeof(float)*nBins);

		/** Se buscan los valores maximo y minimo */
		max = min = auxData[0];
		for(int i=1;i<I.getWidth()*I.getHeight()*I.getType();i++){
			if(max < auxData[i]){
				max = auxData[i];
			}
			if(min > auxData[i]){
				min = auxData[i];
			}
		}

		/** Se hace el cambio de coordenadas */
		a = (nBins-0.0)/(max-min);
		b = nBins-a*max;

		for(int i=0;i<I.getWidth()*I.getHeight()*I.getType();i++){
			_bins[lround(a*auxData[i]+b)]++;
		}

		if(createNormalized && createAccumulated){
			/** Histograma normalizado acumulado */

			/** Normalizado */
			for(int i=0;i<nBins;i++){
				_bins[i] /= I.getWidth()*I.getHeight();
			}

			/** Acumulado */
			for(int i=1;i<nBins;i++){
				_bins[i] += _bins[i-1];
			}
		}
		else if(createNormalized){
			/** Histograma normalizado */
			for(int i=0;i<nBins;i++){
				_bins[i] /= I.getWidth()*I.getHeight();
			}
		}
		else if(createAccumulated){
			/** Histograma acumulado */
			for(int i=1;i<nBins;i++){
				_bins[i] += _bins[i-1];
			}
		}
	}

	/** Returns the i-th element of the histogram */
	float operator[](unsigned int i)
	{
		return(_bins[i]);
	}

	/** Returns the number of bins of the histogram */
	unsigned int size()
	{
		return(_nBins);
	}

	/** Indicates if the object is valid, i.e., it is calculated */
	bool isValid()
	{
		return(_isValid);
	}

	/** Indicates if the histogram is normalized */
	bool isNormalized()
	{
		return(_isNormalized);
	}

	/** Indicates if the histogram is accumulated */
	bool isAccumulated()
	{
		return(_isAccumulated);
	}

private:
	float *_bins;
	unsigned int _nBins;
	bool _isNormalized;
	bool _isAccumulated;
	bool _isValid;
};

#endif

