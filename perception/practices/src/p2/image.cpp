//////////////////////////////////
//														  //
// Nombre: Raul Perula Martinez //
// Curso: 3º I.T.I. Sistemas	  //
//														  //
//////////////////////////////////

#include <image.h>

/** Constructor vacio */
Image::Image()
{
	_width = 0;
	_heigth = 0;
	_type = -1;
	_data = NULL;
}

/** Crea una imagen con un tamaño y tipo indicado y con un valor por defecto */
Image::Image(const Image & I)
{
//comprobar imagen nula
	_width = I._width;
	_heigth = I._heigth;
	_type = I._type;
	
	if(_type == 0){
		_data = new unsigned char[_width*_heigth];
		
		memcpy(_data, I._data, _width*_heigth);
	}
	else{
		_data = new unsigned char[_width*_heigth*3];
		
		memcpy(_data, I._data, _width*_heigth*3);
	}
}

/** Crea una imagen con un tamaño y tipo indicado y con un valor por defecto */
Image::Image(int w, int h, int type, unsigned char c)
{
	_width = w;
	_heigth = h;
	_type = type;
	
	if(_type == 0){
		_data = new unsigned char[_width*_heigth];
		
		memset(_data, c, _width*_heigth);
	}
	else{
		_data = new unsigned char[_width*_heigth*3];
		
		memset(_data, c, _width*_heigth*3);
	}
}

/** Destructor */
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
	char garbage;
	
	file.open(nombre.c_str(), ios::in);
	
	/** Si no se ha abierto el fichero, se muestra mensaje de error */
	if(!file.is_open()){
		throw ImageException("Error: apertura de fichero fallida");
	}
	
	/** Se lee la parte en modo texto */
	
	file >> numMag;
	file >> _width;
	file >> _heigth;
//	file.read(&garbage, sizeof(char));
//	while(garbage != '\n'){
//		file.read(&garbage, sizeof(char));
//	}

	if(numMag == "P5"){
		_type = 0;
	}
	else if(numMag == "P6"){
		_type = 1;
	}
	else{
		throw ImageException("Error: tipo de imagen no soportado");
	}
	
	/** Se lee la parte en modo binario */

	if(_type == 0){
		/** Si es en escala de grises */
		
		/** Se comprueba que no tuviese valor previo el array */
		if(_data != NULL){
			delete[] _data;
			_data = NULL;
		}
		
		/** Reserva de la memoria del array y lectura de imagen */
		_data = new unsigned char[_width*_heigth];

		file.read((char *) _data, _width*_heigth*sizeof(unsigned char));
	}
	else{
		/** Sino, es en RGB */
		
		/** Se comprueba que no tuviese valor previo el array */
		if(_data != NULL){
			delete[] _data;
			_data = NULL;
		}
		
		/** Reserva de la memoria del array y lectura de imagen */
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
	
	/** Si no se ha abierto el fichero, se muestra mensaje de error */
	if(!file.is_open()){
		throw ImageException("Error: apertura de fichero fallida");
	}
	
	/** Dependiendo del tipo que sea se pone un numero magico u otro */
	if(_type == 0){
		file << "P5\n";
	}
	else if(_type == 1){
		file << "P6\n";
	}
	else{
		throw ImageException("Error: imagen no cargada previamente");
	}
	file << _width << ' ' << _heigth << endl;
	file << 255 << endl;

	/** Escritura en binario de la imagen */
	if(_type == 0){
		file.write((char *) _data, _width*_heigth*sizeof(unsigned char));
	}
	else{
		file.write((char *) _data, _width*_heigth*3*sizeof(unsigned char));
	}

	file.close();
}

/** Accede al elemento x,y de una imagen y modificarlo. Permite hacer cosas como
* Image I(100,100,0,10);
* I(10,10) = 19;
* cout << I(10,10)
*/
unsigned char & Image::operator()(unsigned int x, unsigned int y, unsigned int c) throw(ImageException)
{
	if(((x < 0) || (x > _width)) || ((y < 0) || (y > _heigth))){
		throw ImageException("Error: las coordenadas introducidas estan fuera de rango");
	}
	else{
		if((_type == 0) && (c != 0)){
			throw ImageException("Error: el tipo y la capa no coinciden");
		}
		else if((_type == 0) && (c == 0)){
			return(_data[y*_width+x]);
		}
		else{
			return(_data[((y*_width+x)*3)+c]);
		}
	}
}

/** Operador de asignación */
Image & Image::operator=(const Image &I) throw(ImageException)
{
	int t;
	
	if((_heigth != I._heigth) || (_width != I._width)){
		if(_data != NULL){
			delete[] _data;
			_data = NULL;
		}
		
		_width = I._width;
		_heigth = I._heigth;
		_type = I._type;
	}
	
	if(_type == 0){
		t = 1;
	}
	else{
		t = 3;
	}
	
	if(_data == NULL){
		_data = new unsigned char[_width*_heigth*t];
	}
	
	memcpy(_data, I._data, _width*_heigth*t);
	
	return *this;
}

/** Operador de asignación. Asigna a todos los pixels el mismo valor */
Image & Image::operator=(unsigned char v) throw(ImageException)
{
	int t;
	
	if(_data == NULL){
		throw ImageException("Error: imagen no cargada previamente");
	}
	
	if(_type == 0){		
		t = 1;
	}
	else{
		t = 3;
	}
	
	memset(_data, v, _width*_heigth*t);
	
	return *this;
}

