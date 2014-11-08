#ifndef _LINEARFUNCTION_H_
#define _LINEARFUNCTION_H_

/**
 * @file    linearfunction.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

#include <utility>
#include <vector>

class LinearFunction
{
public:
	/** Empty constructor
	*/
	LinearFunction()
	{
		
	}
	
	/** Copy constructor
	*/
	LinearFunction(const LinearFunction & LF)
	{
		_points = LF._points;
	}
	
	/** Reads the funcion to apply from a file
	*/
	void loadFromFile(string file) throw(ImageException)
	{
		fstream f;
		int tam;
		pair<float, float> aux;
		
		f.open(file.c_str(), ios::in);
		
		if(f.is_open()){
			f >> tam;
			for(int i=0;i<tam;i++){
				f >> aux.first;
				f >> aux.second;
				_points.push_back(aux);
			}
		}
		else{
			throw ImageException("Error: apertura de fichero erronea");
		}
		
		f.close();
	}
	
	/** Returns the i-th point of the function
	*/
	pair<float,float> get(unsigned int i)
	{
		return(_points[i]);
	}
	
	int getTam()
	{
		return(_points.size());
	}

private:
	/** Vector containing the points of the function
	*/
	vector< pair< float, float > > _points;
};

#endif

