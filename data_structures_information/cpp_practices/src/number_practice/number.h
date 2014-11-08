#ifndef _Number_H_
#define _Number_H_

/**
 * @file    number.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

namespace values
{
  /**This class represent a generic number
  */
  template<class Type>
  class Number
  {
  public:
    /**Empty constructor
    */
    Number() {_value=0;}
    /**Parametrized constructor
    */
    Number(Type v) {_value=v;}
    /**Sets the current value
    */
    void setValue(Type v) {_value=v;}
    /**Returns the current value
    */
    Type getValue(void) {return _value;}
    /**Returns the current value
    */
    Number & operator=(const Number & N) { _value=N._value; return *this;}

    /**Addition operator
    */
    Number operator+(const Number & N){
      Number aux;
      aux._value=_value+N._value;
      return aux;
    }
    /**Substraction operator
    */
    Number operator-(const Number & N){
      Number aux;
      aux._value=_value-N._value;
      return aux;
    }
    /**Multiplication operator
    */
    Number operator*(const Number & N){
      Number aux;
      aux._value=_value*N._value;
      return aux;
    }
    /** Division operator
    */
    Number operator/(const Number & N){
      Number<Type> aux;
      aux._value=_value/N._value;
      return aux;
    }
    /**less operator
    */
    Number operator<(const Number & N){return _value<N.value;}
    /**greater operator
    */
    Number operator>(const Number & N){return _value>N.value;}
    /**less-equal operator
    */
    Number operator<=(const Number & N){return _value<=N.value;}
    /**greater-equal operator
    */
    Number operator>=(const Number & N){return _value>=N.value;}
    /**equal operator
    */
    Number operator==(const Number & N){return _value==N.value;}
    /** not equal operator
    */
    Number operator!=(const Number & N){return _value!=N.value;}
    /** increment operator
    */
    //void operator++(const Number & N){_value++;}
    /** decrement operator
    */
    //void operator--(const Number & N){_value--;}

  private:
    Type _value;

  };

};

#endif
