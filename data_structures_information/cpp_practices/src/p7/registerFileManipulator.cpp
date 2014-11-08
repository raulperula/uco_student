#include <registerFileManipulator.h>
#include <iostream>

using namespace std;

namespace storage
{
 
RegisterFileManipulator::RegisterFileManipulator(){
    _nElements=0;
    _signature=-1;
	_isOpen=false;
}
 
RegisterFileManipulator::RegisterFileManipulator(string filePath){
    _nElements=0;
    _signature=-1;
	_isOpen=false;
	open(filePath.c_str());
    
}

RegisterFileManipulator::~RegisterFileManipulator(){ 
    if(this->isOpen()) _file.close();
}

bool RegisterFileManipulator::open(string filePath){
	 assert(!isOpen()); //check is not already opened
	//open the file. If it is not created, it creates an empty file
	//If it is created then open it and goes to the end
	_file.open(filePath.c_str());
 
	if (!_file.is_open()){ //file is not created. Create it
    	_file.open(filePath.c_str(),ios::out);
	    if(!_file.is_open()) return false;
	    _file.close();
    	_file.open(filePath.c_str(),ios::in|ios::out);
		if(!_file.is_open())return false;
		_nElements=0;
		_signature=-1;
    	_file.write((char*)&_signature,sizeof(int));
    	_file.write((char*)&_nElements,sizeof(int));
		_isOpen=true;
		return true;
    }

	else{ //The file containts data
     //place the get pointer at the begining of the file  and read the number of elments
    	_file.seekg(0,ios::beg);
		_file.read((char*)&_signature,sizeof(int));
    	_file.read((char*)&_nElements,sizeof(int));
    	//Check data is consistent
    	assert(_nElements>=0);
		_isOpen=true;
		return true;
    }

}
bool RegisterFileManipulator::isOpen() const{
    return _isOpen;
}

void RegisterFileManipulator::close(){
    if (isOpen()){
		_file.close();
		_isOpen=false;
	}
}

int RegisterFileManipulator::getSignature()const{
    assert(isOpen());
    return _signature;
}

unsigned int RegisterFileManipulator::size()const{
    assert(isOpen());
    return _nElements;
}

bool RegisterFileManipulator::add(Register *R){
    assert(isOpen());
    _file.seekp(0,ios::beg);
	if(getSignature()==-1){
		_signature=R->getSignature();
		_file.write((char*)&_signature,sizeof(int));
		_nElements++;
		_file.write((char*)&_nElements,sizeof(unsigned int));
        R->writeToStream(_file);
		return true;
    }

    _file.seekp(0,ios::end);

	if(R->getSignature()!=getSignature()) return false;
    else{
		R->writeToStream(_file);
		_nElements++;
		_file.seekp(sizeof(int),ios::beg);
		_file.write((char*)&_nElements,sizeof(unsigned int));
	    return true;
    }
}

bool RegisterFileManipulator::read(unsigned int i,Register *r){
	if( (!isOpen()) || (_nElements==0) || (_signature!=r->getSignature()) || i>=_nElements ) return false;
	int offset=2*sizeof(int)+i*r->getSizeOfRegister();	
	_file.seekg(offset,ios::beg);
    r->readToStream(_file);
	return true;
}

bool RegisterFileManipulator::overWrite(unsigned int i,Register *r){
	assert(isOpen());
	if(_signature!=r->getSignature() || i>=_nElements ) return false;
	int offset=2*sizeof(int)+i*r->getSizeOfRegister();	
	_file.seekg(offset,ios::beg);
    r->writeToStream(_file);
	return true;
}

}
