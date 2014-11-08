#include <float.h>

namespace values{

	///////////////////////////////
	//
	///////////////////////////////
	Float::Float(){_value=0;}
	
	///////////////////////////////
	//
	///////////////////////////////
	Float::Float(float f){_value=f;}

	///////////////////////////////
	//
	///////////////////////////////
	Float::Float(const Float & F){_value=F._value;}

	///////////////////////////////
	//
	///////////////////////////////
	float Float::getValue(){return _value;}

	///////////////////////////////
	//
	///////////////////////////////
	void Float::setValue(float f){_value=f;}
 
	///////////////////////////////
	//
	///////////////////////////////
	Float & Float::operator=(const Float & F){_value=F._value;return *this;}

	///////////////////////////////
	//
	///////////////////////////////
	Float & Float::operator=(float f){_value=f;return *this;}

	///////////////////////////////
	//
	///////////////////////////////
	Float Float::operator+(const Float & F){
		Float aux;
		aux._value=_value+F._value;
		return aux;
	}

	///////////////////////////////
	//
	///////////////////////////////
	Float Float::operator+(float f){
		Float aux;
		aux._value=_value+f;
		return aux;
	}
	///////////////////////////////
	//
	///////////////////////////////
	Float Float::operator-(const Float & F){
		Float aux;
		aux._value=_value-F._value;
		return aux;
	}
	///////////////////////////////
	//
	///////////////////////////////
	Float Float::operator-(float f){
		Float aux;
		aux._value=_value-f;
		return aux;
	}
	///////////////////////////////
	//
	///////////////////////////////
	Float Float::operator*(const Float & F){
		Float aux;
		aux._value=_value*F._value;
		return aux;
	}
	///////////////////////////////
	//
	///////////////////////////////
	bool Float::operator<(const Float & F){ return (_value<F._value);}
}