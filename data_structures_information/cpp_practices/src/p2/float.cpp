#include<float.h>
namespace values{

  //////////////////////
  //
  //////////////////////

  Float::Float()
  {
  _fvalue=0;
  }
  //////////////////////
  //
  //////////////////////

  Float::Float(float v)
  {
  _fvalue=v;
  }

  //////////////////////
  //
  //////////////////////
  Float::Float(const Float & F)
  {
  _fvalue=F._fvalue;
  }

  //////////////////////
  //
  //////////////////////
  
  Float & Float::operator=(const Float & F)
  {
    _fvalue=F._fvalue;
    return *this;
  }

  Float & Float::operator=(float v)
  {
    _fvalue=v;
    return *this;
  }

  //////////////////////
  //
  //////////////////////

  float Float::getValue()
  {
    return _fvalue;
  }

  //////////////////////
  //
  //////////////////////

  void Float::setValue(float v)
  {
    _fvalue=v;
  }

  //////////////////////
  //
  //////////////////////

  Float Float::operator+(const Float & F)
  {
  Float aux;
  aux._fvalue=_fvalue+F._fvalue;
  return aux;
  }
  
  //////////////////////
  //
  //////////////////////

  Float Float::operator+(float f)
  {
  Float aux;
  aux._fvalue=_fvalue+f;
  return aux;
  }

  //////////////////////
  //
  //////////////////////

  Float Float::operator-(const Float & F)
  {
  Float aux;
  aux._fvalue=_fvalue-F._fvalue;
  return aux;
  }

  //////////////////////
  //
  //////////////////////
  
  Float Float::operator-(float f)
  {
  Float aux;
  aux._fvalue=_fvalue-f;
  return aux;
  }

  //////////////////////
  //
  //////////////////////

  Float Float::operator*(const Float & F)
  {
  Float aux;
  aux._fvalue=_fvalue*F._fvalue;
  return aux;
  }
  
  //////////////////////
  //
  //////////////////////

  Float Float::operator*(float f)
  {
  Float aux;
  aux._fvalue=_fvalue*f;
  return aux;
  }

  //////////////////////
  //
  //////////////////////

  Float Float::operator/(const Float & F)
  {
  Float aux;
  aux._fvalue=_fvalue/F._fvalue;
  return aux;
  }

  //////////////////////
  //
  //////////////////////

  Float Float::operator/(float f)
  {
  Float aux;
  aux._fvalue=_fvalue/f;
  return aux;
  }

  //////////////////////
  //
  //////////////////////

  bool Float::operator<(const Float & F)
  {
  return _fvalue<F._fvalue;
  }

  //////////////////////
  //
  //////////////////////

  bool Float::operator<=(const Float & F)
  {
  return _fvalue<=F._fvalue;
  }

  //////////////////////
  //
  //////////////////////

  bool Float::operator>(const Float & F)
  {
  return _fvalue>F._fvalue;
  }

  //////////////////////
  //
  //////////////////////

  bool Float::operator>=(const Float & F)
  {
  return _fvalue>F._fvalue;
  }

  //////////////////////
  //
  //////////////////////

  bool Float::operator==(const Float & F)
  {
  return _fvalue==F._fvalue;
  }


  //////////////////////
  //
  //////////////////////

  bool Float::operator!=(const Float & F)
  {
  return _fvalue!=F._fvalue;
  }

  ////////////////////////////
  //
  ////////////////////////////
  void Float::operator++(int)
  {
  _fvalue++;
  }
 
  ////////////////////////////
  //
  ////////////////////////////
  void Float::operator--(int)
  { 
  _fvalue--;
  }
}
