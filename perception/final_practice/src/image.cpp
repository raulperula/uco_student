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
	_height = 0;
	_type = -1;
	_data = NULL;
}

/** Crea una imagen a partir de otra */
Image::Image(const Image & I)
{
	if(I._data == NULL){
		throw ImageException("Error en Image(I): imagen no cargada previamente");
	}

	_width = I._width;
	_height = I._height;
	_type = I._type;
	
	if(_type != -1){
		_data = new unsigned char[_width*_height*_type];
		
		memcpy(_data, I._data, _width*_height*_type*sizeof(unsigned char));
	}
	else{
		throw ImageException("Error en Image(I): imagen no cargada previamente");
	}
}

/** Crea una imagen con un tamaño y tipo indicado y con un valor por defecto */
Image::Image(int w, int h, int type, unsigned char c)
{
	_width = w;
	_height = h;
	_type = type;
	
	if((_type == GREY) || (_type == COLOR)){
		_data = new unsigned char[_width*_height*_type];
		
		memset(_data, c, _width*_height*_type*sizeof(unsigned char));
	}
	else{
		throw ImageException("Error en Image(w,h,type,c): imagen no cargada previamente");
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
int Image::getWidth() const
{
	return(_width);
}

///////////////////////////////////////////////////
//														                   //
// Nombre funcion: getHeight                     //
// Descripcion: devuelve el alto de la imagen.   //
// Parametros de entrada: void                   //
// Devuelve: un entero con el alto de la imagen. //
//														                   //
///////////////////////////////////////////////////
int Image::getHeight() const
{
	return(_height);
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
int Image::getType() const
{
	return(_type);
}

unsigned char * Image::getData() const
{
	return(_data);
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
	int auxGris;
	char garbage;
	
	file.open(nombre.c_str(), ios::in);
	
	/** Si no se ha abierto el fichero, se muestra mensaje de error */
	if(!file.is_open()){
		throw ImageException("Error en loadFromFile(nombre): apertura de fichero fallida");
	}
	
	/** Se lee la parte en modo texto */
	
	file >> numMag;
	file >> _width;
	file >> _height;
	file >> auxGris;
	/** Se desecha la posible basura que pueda haber */
	file.read(&garbage, sizeof(char));
	while(garbage != '\n'){
		file.read(&garbage, sizeof(char));
	}

	if(numMag == "P5"){
		_type = GREY;
	}
	else if(numMag == "P6"){
		_type = COLOR;
	}
	else{
		throw ImageException("Error en loadFromFile(nombre): tipo de imagen no soportado");
	}
	
	/** Se lee la parte en modo binario */

	/** Se comprueba que no tuviese valor previo el array */
	if(_data != NULL){
		delete[] _data;
		_data = NULL;
	}
	
	/** Reserva de la memoria del array y lectura de imagen */
	_data = new unsigned char[_width*_height*_type];

	file.read((char *) _data, _width*_height*_type*sizeof(unsigned char));
	
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
		throw ImageException("Error en saveToFile(nombre): apertura de fichero fallida");
	}
	
	/** Dependiendo del tipo que sea se pone un numero magico u otro */
	if(_type == GREY){
		file << "P5\n";
	}
	else if(_type == COLOR){
		file << "P6\n";
	}
	else{
		throw ImageException("Error en saveToFile(nombre): imagen no cargada previamente");
	}
	file << _width << ' ' << _height << endl;
	file << 255 << endl;

	/** Escritura en binario de la imagen */
	file.write((char *) _data, _width*_height*_type*sizeof(unsigned char));

	file.close();
}

/** Accede al elemento x,y de una imagen y modificarlo. Permite hacer cosas como
* Image I(100,100,0,10);
* I(10,10) = 19;
* cout << I(10,10)
*/
unsigned char & Image::operator()(unsigned int x, unsigned int y, unsigned int c) throw(ImageException)
{
	if((x >= (unsigned int) _width) || (y >= (unsigned int) _height)){
		throw ImageException("Error en operator(): las coordenadas estan fuera de rango");
	}
	else{
		if((_type == GREY) && (c != 0)){
			throw ImageException("Error en operator(): el tipo y la capa no coinciden");
		}
		else if((_type == GREY) && (c == 0)){
			return(_data[y*_width+x]);
		}
		else{
			return(_data[((y*_width+x)*_type)+c]);
		}
	}
}

/** Operador de asignación */
Image & Image::operator=(const Image &I) throw(ImageException)
{
	if(_data != NULL){
		delete[] _data;
		_data = NULL;
	}
	
	_width = I._width;
	_height = I._height;
	_type = I._type;
	
	if(_type == -1){
		throw ImageException("Error en operator=(I): imagen no cargada previamente");
	}
	
	if(_data == NULL){
		_data = new unsigned char[_width*_height*_type];
	}
	
	memcpy(_data, I._data, _width*_height*_type*sizeof(unsigned char));
	
	return *this;
}

/** Operador de asignación. Asigna a todos los pixels el mismo valor */
Image & Image::operator=(unsigned char v) throw(ImageException)
{	
	if(_data == NULL){
		throw ImageException("Error en operator=(v): imagen no cargada previamente");
	}
	
	if(_type == -1){
		throw ImageException("Error en operator=(v): imagen no cargada previamente");
	}
	
	memset(_data, v, _width*_height*_type*sizeof(unsigned char));
	
	return *this;
}

/** Funcion de reasignacion de tamaño de una imagen */
void Image::resize(int width, int height, int type) throw(ImageException)
{
	if(_data != NULL){
		delete[] _data;
	}
	
	_width = width;
	_height = height;
	_type = type;
	
	if(_type == -1){
		throw ImageException("Error en resize(width,height,type): imagen no cargada previamente");
	}
	else{
		_data = new unsigned char[_width*_height*_type];
	}
}

