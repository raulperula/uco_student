#ifndef _Vector_H_
#define _Vector_H_

/**
 * @file    vector.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <cassert>
#include <cstdlib>
using namespace std;
namespace storage
{
template<class Type>
class Vector
{
public:
    /**Empty constructor
    */
    inline Vector();
    /**Parametrized constructor
    */
    inline Vector(unsigned int size);
    /**Copy constructor
    */
    inline Vector(const Vector & V);
    /**Destructor
    */
    inline ~Vector();
    /**Assign operator
    */
    inline Vector  & operator=(const Vector &V);
    /**Resizes the vector
    */
    inline void resize(unsigned int size);
    /**Returns the vector size
    */
    inline int size();
    /**Returns the i-th element
    */
    inline Type & operator[](unsigned int i);

private:
    Type *_data;
    unsigned int _size;
};
//////////////////////////
//
//////////////////////////
template<class Type>
Vector<Type>::Vector()
{
_data=NULL;
_size=0;
}

//////////////////////////
//
//////////////////////////
template<class Type>
Vector<Type>::Vector(unsigned int size){
    _size=size;
    _data=new Type[size];
}
//////////////////////////
//
//////////////////////////
template<class Type>
Vector<Type>::Vector(const Vector & V){
    _size=V._size;
    _data=new Type [_size];
    for(unsigned int i=0;i<_size;i++)
        _data[i]=V._data[i];
}

//////////////////////////
//
//////////////////////////
template<class Type>
Vector<Type>::~Vector(){
if (_data!=NULL)
    delete []_data;
}

//////////////////////////
//
//////////////////////////
template<class Type>
Vector<Type> & Vector<Type>::operator=(const Vector &V)
{
  if (_data!=NULL) delete []_data;
   _size=V._size;
    _data=new Type[_size];
    for(unsigned int i=0;i<_size;i++)
        _data[i]=V._data[i];
    return *this;
}

//////////////////////////
//
//////////////////////////
template<class Type>
void Vector<Type>::resize(unsigned int size)
{
if (_data!=NULL)
    delete [] _data;
_size=size;
_data=new Type[_size];
}
//////////////////////////
//
//////////////////////////
template<class Type>
Type & Vector<Type>::operator[](unsigned int i)
{
assert(i<_size);
return _data[i];
}

//////////////////////////
//
//////////////////////////
template<class Type>
int Vector<Type>::size()
{
return _size;
}
};

#endif
