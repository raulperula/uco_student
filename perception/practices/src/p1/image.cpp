//////////////////////////////////
//														  //
// Nombre: Raul Perula Martinez //
// Curso: 3º I.T.I. Sistemas	  //
//														  //
//////////////////////////////////

#include <image.h>

/* Constructor vacio */
Image::Image()
{
	_width = 0;
	_heigth = 0;
	_type = -1;
	_data = NULL;
	_gris = -1;
}

/* Destructor */
Image::~Image()
{
	if(_data != NULL){
		delete[] _data;
		_data = NULL;
	}
}

////////////////////////////////////////////////////
//														                    //
// Nombre funcion: getWidth                       //
// Descripcion: devuelve el ancho de la imagen.   //
// Parametros de entrada: void	                  //
// Devuelve: un entero con el ancho de la imagen. //
//														                    //
////////////////////////////////////////////////////
int Image::getWidth()
{
	return(_width);
}

///////////////////////////////////////////////////
//														                   //
// Nombre funcion: getHeigth                     //
// Descripcion: devuelve el alto de la imagen.   //
// Parametros de entrada: void                   //
// Devuelve: un entero con el alto de la imagen. //
//														                   //
///////////////////////////////////////////////////
int Image::getHeigth()
{
	return(_heigth);
}

///////////////////////////////////////////////////////////////////////////////
//														                                               //
// Nombre funcion: getType                                                   //
// Descripcion: devuelve el tipo de la imagen, 0 si es en escala de grises y //
//              1 para imagen en color.                                      //
// Parametros de entrada: void	                                             //
// Devuelve: un entero con el tipo de la imagen.                             //
//														                                               //
///////////////////////////////////////////////////////////////////////////////
int Image::getType()
{
	return(_type);
}

////////////////////////////////////////////////////////////////////////////////
//														                                                //
// Nombre funcion: loadFromFile                                               //
// Descripcion: carga una imagen desde un fichero, comprobando si es en escala//
//              de grises o en color.                                         //
// Parametros de entrada: una cadena con el nombre del fichero.               //
// Devuelve: void                                                             //
//														                                                //
////////////////////////////////////////////////////////////////////////////////
void Image::loadFromFile(string nombre) throw(ImageException)
{
	fstream file;
	string numMag;
	
	file.open(nombre.c_str(), ios::in);
	
	// Si no se ha abierto el fichero, se muestra mensaje de error
	if(!file.is_open()){
		throw ImageException("Error en apertura de fichero");
	}
	
	// Se lee la parte en modo texto
	
	file >> numMag;
	file >> _width;
	file >> _heigth;
	file >> _gris;
	char garbage;
	file.read(&garbage, sizeof(char));

	if(numMag == "P5"){
		_type = 0;
	}
	else if(numMag == "P6"){
		_type = 1;
	}
	else{
		throw ImageException("Tipo de imagen no soportado");
	}
	
	// Se lee la parte en modo binario

	if(_type == 0){
		// Si es en escala de grises
		
		// Se comprueba que no tuviese valor previo el array
		if(_data != NULL){
			delete[] _data;
			_data = NULL;
		}
		
		//Reserva de la memoria del array y lectura de imagen
		_data = new unsigned char[_width*_heigth];

		file.read((char *) _data, _width*_heigth*sizeof(unsigned char));
	}
	else{
		// Sino, es en RGB
		
		// Se comprueba que no tuviese valor previo el array
		if(_data != NULL){
			delete[] _data;
			_data = NULL;
		}
		
		//Reserva de la memoria del array y lectura de imagen
		_data = new unsigned char[_width*_heigth*3];

		file.read((char *) _data, _width*_heigth*3*sizeof(unsigned char));
	}
	
	file.close();
}

//////////////////////////////////////////////////////////////////////////////
//														                                              //
// Nombre funcion: saveToFile                                               //
// Descripcion: crea una imagen, en escala de grises o en color dependiendo //
//              del tipo, a partir de una leida.                            //
// Parametros de entrada: una cadena con el nombre del nuevo fichero.       //
// Devuelve: void                                                           //
//														                                              //
//////////////////////////////////////////////////////////////////////////////
void Image::saveToFile(string nombre) throw(ImageException)
{
	fstream file;
	
	file.open(nombre.c_str(), ios::out);
	
	// Si no se ha abierto el fichero, se muestra mensaje de error
	if(!file.is_open()){
		throw ImageException("Error en apertura de fichero");
	}
	
	// Dependiendo del tipo que sea se pone un numero magico u otro
	if(_type == 0){
		file << "P5\n";
	}
	else{
		file << "P6\n";
	}
	file << _width << ' ' << _heigth << endl;
	file << _gris << endl;

	// Escritura en binario de la imagen
	if(_type == 0){
		file.write((char *) _data, _width*_heigth*sizeof(unsigned char));
	}
	else{
		file.write((char *) _data, _width*_heigth*3*sizeof(unsigned char));
	}

	file.close();
}

