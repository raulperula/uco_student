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
/** Representa un numero generico*/

   template<class Type>

   class Number
   {
   public:

      /**Empty constructor*/
      Number() {_value=0;}

      /**Parametrized constructor*/
      Number(Type v) {_value=v;}

      /**Sets the current value*/
      void setValue(Type v)
      {
         _value=_value;
      }

      /**Returns the current value*/
      Type getValue(void) {return _value;}

      /**Retruns the current value*/
      Number & operator=(const Number &N)
      {
         _value=N._value;
     return *this;
      }

      /**Addition operator*/
      Number operator+ (const Number & N)
      {
         Number aux;
     aux._value=_value+N.value;
     return aux;
      }

      /**Substraction operator*/
      Number operator- (const Number & N)
      {
         Number aux;
         aux._value=_value-N._value;
         return aux;
      }

      /**Multiplication operator*/
      Number operator* (const Number & N)
      {
         Number aux;
         aux._value=_value*N._value;
         return aux;
      }

      /**Division operator*/
      Number operator/ (const Number & N)
      {
         Number aux;
         aux._value=_value/N._value;
         return aux;
      }

      /**Less operator*/
      bool operator< (const Number & N)
      {
         return _value<N._value;
      }

      /**Less-equal operator*/
      bool operator<= (const Number & N)
      {
         return _value<=N._value;
      }

      /**Greater operator*/
      bool operator> (const Number & N)
      {
         return _value>N._value;
      }

      /**Greater-equal operator*/
      bool operator>= (const Number & N)
      {
         return _value>N._value;
      }

      /**equal operator*/
      bool operator== (const Number & N)
      {
         return _value==N._value;
      }

      /**not equal operator*/
      bool operator!= (const Number & N)
      {
         return _value!=N._value;
      }

      /**Increment operator*/
      void operator++(int)
      {
         _value++;
      }

      /**Decrement operator*/
      void operator--(int)
      {
         _value--;
      }

   private:
      Type _value;
   };
};
#endif
