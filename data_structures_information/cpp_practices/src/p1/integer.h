#ifndef _integer_h_
#define _integer_h_

/**
 * @file    integer.h
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
  class Integer
  {
  public:

    /**Empty constructor
    */
    Integer();

    /**Parametrized constructor
    */

    Integer(int v);

    /**Copy constructor
    */

    Integer(const Integer &I);

    /**Copy Operator
    */
    Integer & operator=(const Integer & i);
    Integer & operator=(int v);

    /**Returns the current value of the integer
    */


    int getValue();

    /** Sets a value in this object
    */
    void setValue(int v);

  private:
    int _ivalue;
  };
}
#endif
