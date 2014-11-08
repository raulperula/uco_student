#include<animalreg.h>


namespace registers{

	Animalreg::Animalreg(){
		_nElements=0;
		_especie=-1;
		_isOpen=false;
	}
	Animalreg::Animalreg(string path){
		_nElements=0;
		_especie=-1;
		_isOpen=false;
		open(path.c_str());
	}
	Animalreg::~Animalreg(){
		if(isOpen()) _file.close();
	}
	bool Animalreg::open(string path){
		assert(!isOpen());
		_file.open(path.c_str());
		if(!_file.is_open()){
			_file.open(path.c_str(),ios::out);
			if(!_file.is_open()) return false;
			_file.close();
			_file.open(path.c_str(),ios::in|ios::out);
			if(!_file.is_open()) return false;
			_especie=0;
			_nElements=0;
			_file.write((char*)&_especie,sizeof(int));
			_file.write((char*)&_nElements,sizeof(int));
			_isOpen=true;
			return true;
		}
		else{
			_file.seekg(0,ios::beg);
			_file.read((char*)&_especie,sizeof(int));
			_file.read((char*)&_nElements,sizeof(int));
			_isOpen=true;
			return true;
		}
	}
	bool Animalreg::isOpen(){ return _isOpen;}
	void Animalreg::close(){ 
		if(isOpen()){
			_file.close();
			_isOpen=false;
		}
	}
	int Animalreg::getEspecie(){ return _especie;}
	int Animalreg::getSize(){ return _nElements;}
	bool Animalreg::add(Animal*A){
		assert(isOpen());
		if(_nElements==0){
			_especie=A->getEspecie();
			_file.seekp(0,ios::beg);
			_file.write((char*)&_especie,sizeof(int));
			_nElements++;
			_file.write((char*)&_nElements,sizeof(int));
			A->writeToStream(_file);
			return true;
		}
		if(getEspecie()!=A->getEspecie()) return false;
		else{
			_file.seekp(0,ios::end);
			A->writeToStream(_file);
			_nElements++;
			_file.seekp(sizeof(int),ios::beg);
			_file.write((char*)&_nElements,sizeof(int));
			return true;
		}
	}
	bool Animalreg::read(int i,Animal* A){
		if( !isOpen() || (_nElements==0) || (getEspecie()!=A->getEspecie()) || (i>=_nElements)) return false;
		int offset=2*sizeof(int)+i*A->regSize();
		_file.seekg(offset,ios::beg);
		A->readFromStream(_file);
		return true;
	}
	bool Animalreg::overWrite(int i,Animal* A){
		if( !isOpen() || (_nElements==0) || (getEspecie()!=A->getEspecie()) || (i>=_nElements)) return false;
		int offset=2*sizeof(int)+i*A->regSize();
		_file.seekp(offset,ios::beg);
		A->writeToStream(_file);
		return true;
	}
};
