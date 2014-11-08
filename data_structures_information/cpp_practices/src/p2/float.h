#ifndef _float_h_
#define _float_h_

/**
 * @file    float.h
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
  class Float
  {
  public:

    /**Empty constructor
    */
    Float();

    /**Parametrized constructor
    */

    Float(float v);

    /**Copy constructor
    */

    Float(const Float &F);

    /**Copy Operator
    */
    Float & operator=(const Float & f);
    Float & operator=(float v);

    /**Returns the current value of the float
    */
    float getValue();

    /** Sets a value in this object
    */
    void setValue(float v);

    /** Addition operator
    */
    Float operator+(const Float & F);

    /** Addition operator2
    */
    Float operator+(float f);

    /** Substraction operator
    */
    Float operator-(const Float & F);

    /** Substraction operator2
    */
    Float operator-(float f);

    /** Multiplication operator
    */
    Float operator*(const Float & F);

    /** Multiplication operator2
    */
    Float operator*(float f);

    /** Division operator
    */
    Float operator/(const Float & F);

    /** Division operator
    */
    Float operator/(float f);

    /** Less operator
    */
    bool operator<(const Float & F);

    /**less-equal operator
    */
    bool operator<=(const Float & F);
    /**greater operator
    */

    bool operator>(const Float & F);

    /**greater-equal operator
    */
    bool operator>=(const Float & F);
 
    /**equal operator
    */
    bool operator==(const Float & F);
 
    /**not equal operator
    */
    bool operator!=(const Float & F);


    /**Increment operator
    */
    void operator++(int);
 
    /**Decrement operator
    */
    void operator--(int);

  };
}
#endif
