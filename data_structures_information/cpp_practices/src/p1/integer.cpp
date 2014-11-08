#include<integer.h>
namespace values{

  //////////////////////
  //
  //////////////////////

  Integer::Integer()
  {
  _ivalue=0;
  }
  //////////////////////
  //
  //////////////////////

  Integer::Integer(int v)
  {
  _ivalue=v;
  }

  //////////////////////
  //
  //////////////////////
  Integer::Integer(const Integer & I)
  {
  _ivalue=I._ivalue;
  }

  //////////////////////
  //
  //////////////////////
  
  Integer & Integer::operator=(const Integer & I)
  {
    _ivalue=I._ivalue;
    return *this;
  }

  Integer & Integer::operator=(int v)
  {
    _ivalue=v;
    return *this;
  }

  //////////////////////
  //
  //////////////////////

  int Integer::getValue()
  {
    return _ivalue;
  }

  //////////////////////
  //
  //////////////////////

  void Integer::setValue(int v)
  {
    _ivalue=v;
  }
}
