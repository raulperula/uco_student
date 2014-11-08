#ifndef _matrix_H_
#define _matrix_H_

/**
 * @file    matrix.h
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
#include <iostream>
using namespace std;
namespace storage
{
template<class Type>
class matrix
{
public:
    /**Empty constructor
    */
    inline matrix();
    /**Parametrized constructor
    */
    inline matrix(unsigned int fil,unsigned int col);
    /**Copy constructor
    */
    inline matrix(const matrix & V);
    /**Destructor
    */
    inline ~matrix();
    /**Assign operator
    */
    inline matrix  & operator=(const matrix &V);

    /**Resizes the matrix
    */
    inline void resize(unsigned int fil,unsigned int col);
    /**Returns the matrix rows
    */
    inline unsigned int getFils();
    /**Returns the matrix columns
    */
    inline unsigned int getCols();

    /**Returns the i-th element
    */
    inline Type & get(unsigned int f,unsigned int c);
    /**Make the Identity matrix
    */
    inline void setIdentity();
    /**Addition operator
    */
    inline matrix  operator+(const matrix &V);

private:
    Type **_data;
    unsigned int _fil;
    unsigned int _col;
};
//////////////////////////
//
//////////////////////////
template<class Type>
matrix<Type>::matrix()
{
  _data=NULL;
  _fil=0;
  _col=0;
}

//////////////////////////
//
//////////////////////////
template<class Type>
matrix<Type>::matrix(unsigned int fil,unsigned int col){
    unsigned int i;
    _fil=fil;
    _col=col;
    _data=new Type*[fil];
    for(i=0;i<col;i++) _data[i]=new Type[col];
}
//////////////////////////
//
//////////////////////////
template<class Type>
matrix<Type>::matrix(const matrix & V){
    unsigned int i,j;
    _fil=V._fil;
    _col=V._col;
    _data=new Type *[_fil];
    for(i=0;i<_col;i++) _data[i]=new Type[_col];
    for(i=0;i<_fil;i++){
      for(j=0;j<_col;j++) _data[i][j]=V._data[i][j];
      }
}

//////////////////////////
//
//////////////////////////
template<class Type>
matrix<Type>::~matrix(){
    unsigned int i;
    if (_data!=NULL){
      for(i=0;i<_fil;i++) delete [] _data[i];
      delete [] _data;
    }
}

//////////////////////////
//
//////////////////////////
template<class Type>
void matrix<Type>::resize(unsigned int fil,unsigned int col)
{
    unsigned int i;
    if (_data!=NULL) {
      for(i=0;i<_fil;i++) delete [] _data[i];
      delete [] _data;
    }
    _fil=fil;
    _col=col;
    _data=new Type*[fil];
    for(i=0;i<col;i++) _data[i]=new Type[col];
}

//////////////////////////
//
//////////////////////////
template<class Type>
unsigned int matrix<Type>::getFils()
{
return _fil;
}

//////////////////////////
//
//////////////////////////
template<class Type>
unsigned int matrix<Type>::getCols()
{
return _col;
}
//////////////////////////
//
//////////////////////////
template<class Type>
Type & matrix<Type>::get(unsigned int f,unsigned int c)
{
assert(f<_fil);
assert(c<_col);
return _data[f][c];
}

//////////////////////////
//
//////////////////////////
template<class Type>
void matrix<Type>::setIdentity()
{
    unsigned int i,j;
    for(i=0;i<_fil;i++){
      for(j=0;j<_col;j++){
        if(i==j) _data[i][j]=1;
        else _data[i][j]=0;
      }
    }
}

//////////////////////////
//
//////////////////////////
template<class Type>
matrix<Type> & matrix<Type>::operator=(const matrix &V)
{
  unsigned int i,j;
  if (V._fil!=_fil || V._col!=_col) resize(V._fil,V._col);
  for(i=0;i<_fil;i++)
    for(j=0;j<_col;j++) _data[i][j]=V._data[i][j];
  return *this;
}

//////////////////////////
//
//////////////////////////
template<class Type>
matrix<Type>  matrix<Type>::operator+(const matrix &V)
{
    unsigned int i=0,j=0;
    assert((_fil==V._fil)&&(_col==V._col));
    matrix Result(V._fil,V._col);
    for(i=0;i<_fil;i++){
      for(j=0;j<_col;j=j+1){
        Result._data[i][j]=_data[i][j]+V._data[i][j];
        }
    }
    return Result;
}
};

#endif
