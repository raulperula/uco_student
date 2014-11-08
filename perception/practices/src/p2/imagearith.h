#ifndef _IArith_H_
#define _IArith_H_

/**
 * @file    imagearith.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <image.h>

class ImageArith
{
public:
	//A = A+cte
	static void add(Image &A, unsigned char v) throw(ImageException)
	{
		int t;

		/** Se suma a cada elemento de la imagen una constante */
		if(A._type == 0){
			t = 1;
		}
		else if(A._type == 1){
			t = 3;
		}
		else{
			throw ImageException("Error: imagen no cargada previamente");
		}

		for(int i=0;i<A._width*A._heigth*t;i++){
			if(A._data[i]+v <= 255){
				A._data[i] += v;
			}
			else{
				A._data[i] = 255;
			}
		}
	}

	//A = A+B
	static void add(Image &A, const Image &B) throw(ImageException)
	{
		int t;

		/** Se suman dos imagenes */
		if((A._data == NULL) || (B._data == NULL)){
			throw ImageException("Error: alguna de las imagenes no esta cargada");
		}
		else{
			if((A._heigth != B._heigth) || (A._width != B._width)){
				throw ImageException("Error: tamaños de las imagenes distintas");
			}
			else{
				if((A._type == 0) && (B._type == 0)){
					t = 1;
				}
				else if((A._type == 1) && (B._type == 1)){
					t = 3;
				}
				else{
					throw ImageException("Error: esta intentando sumar imagenes de distinto tipo");
				}

				for(int i=0;i<A._width*A._heigth*t;i++){
					if(A._data[i]+B._data[i] <= 255){
						A._data[i] += B._data[i];
					}
					else{
						A._data[i] = 255;
					}
				}
			}
		}
	}

	//A = A-cte
	static void sub(Image &A, unsigned char v) throw(ImageException)
	{
		int t;

		/** Se resta a cada elemento de la imagen una constante */
		if(A._type == 0){
			t = 1;
		}
		else if(A._type == 1){
			t = 3;
		}
		else{
			throw ImageException("Error: imagen no cargada previamente");
		}

		for(int i=0;i<A._width*A._heigth*t;i++){
			if(A._data[i]-v >= 0){
				A._data[i] -= v;
			}
			else{
				A._data[i] = 0;
			}
		}
	}

	//A = A-B
	static void sub(Image &A, const Image &B) throw(ImageException)
	{
		int t;

		/** Se restan dos imagenes */
		if((A._data == NULL) || (B._data == NULL)){
			throw ImageException("Error: alguna de las imagenes no esta cargada");
		}
		else{
			if((A._heigth != B._heigth) || (A._width != B._width)){
				throw ImageException("Error: tamaños de las imagenes distintas");
			}
			else{
				if((A._type == 0) && (B._type == 0)){
					t = 1;
				}
				else if((A._type == 1) && (B._type == 1)){
					t = 3;
				}
				else{
					throw ImageException("Error: esta intentando sumar imagenes de distinto tipo");
				}

				for(int i=0;i<A._width*A._heigth*t;i++){
					if(A._data[i]-B._data[i] >= 0){
						A._data[i] -= B._data[i];
					}
					else{
						A._data[i] = 0;
					}
				}
			}
		}
	}

	//A = A*cte
	static void mul(Image &A, unsigned char v) throw(ImageException)
	{
		int t;

		/** Se multiplica cada elemento de la imagen por una constante */
		if(A._type == 0){
			t = 1;
		}
		else if(A._type == 1){
			t = 3;
		}
		else{
			throw ImageException("Error: imagen no cargada previamente");
		}

		for(int i=0;i<A._width*A._heigth*t;i++){
			if(A._data[i]*v <= 255){
				A._data[i] *= v;
			}
			else{
				A._data[i] = 255;
			}
		}
	}

	//A = A*B
	static void mul(Image &A, const Image &B) throw(ImageException)
	{
		int t;

		/** Se multiplican dos imagenes */
		if((A._data == NULL) || (B._data == NULL)){
			throw ImageException("Error: alguna de las imagenes no esta cargada");
		}
		else{
			if((A._heigth != B._heigth) || (A._width != B._width)){
				throw ImageException("Error: tamaños de las imagenes distintas");
			}
			else{
				if((A._type == 0) && (B._type == 0)){
					t = 1;
				}
				else if((A._type == 1) && (B._type == 1)){
					t = 3;
				}
				else{
					throw ImageException("Error: esta intentando sumar imagenes de distinto tipo");
				}

				for(int i=0;i<A._width*A._heigth*t;i++){
					if(A._data[i]*B._data[i] <= 255){
						A._data[i] *= B._data[i];
					}
					else{
						A._data[i] = 255;
					}
				}
			}
		}
	}

	//A = A/cte
	static void div(Image &A, unsigned char v) throw(ImageException)
	{
		int t;

		/** Se divide cada elemento de la imagen por una constante */
		if(v == 0){
			throw ImageException("Error: division por cero");
		}
		else{
			if(A._type == 0){
				t = 1;
			}
			else if(A._type == 1){
				t = 3;
			}
			else{
				throw ImageException("Error: imagen no cargada previamente");
			}

			for(int i=0;i<A._width*A._heigth*t;i++){
				A._data[i] /= v;
			}
		}
	}

	//A = A/B
	static void div(Image &A, const Image &B) throw(ImageException)
	{
		int t;

		/** Se dividen dos imagenes */
		if((A._data == NULL) || (B._data == NULL)){
			throw ImageException("Error: alguna de las imagenes no esta cargada");
		}
		else{
			if((A._heigth != B._heigth) || (A._width != B._width)){
				throw ImageException("Error: tamaños de las imagenes distintas");
			}
			else{
				if((A._type == 0) && (B._type == 0)){
					t = 1;
				}
				else if((A._type == 1) && (B._type == 1)){
					t = 3;
				}
				else{
					throw ImageException("Error: esta intentando sumar imagenes de distinto tipo");
				}

				for(int i=0;i<A._width*A._heigth*t;i++){
					if(B._data[i] == 0){
						A._data[i] = 255;
					}
					else{
						A._data[i] /= B._data[i];
					}
				}
			}
		}
	}

};

#endif

