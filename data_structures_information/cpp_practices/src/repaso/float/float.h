#ifndef _FLOAT_H_
#define _FLOAT_H_

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

namespace values{
class Float{
    public:
        /** Empty Constructor
        */
        Float();
        /** Parametrized Constructor
        */
        Float(float f);
        /** Copy Constructor
        */
        Float(const Float & F);
        /** Asignation operator
        */
        Float & operator=(const Float &F);
        /** Asignation operator 2
        */
        Float & operator=(float f);
        /** Returns the current value of the Float
        */
        float getValue();
        /** Set the float value to the object
        */
        void setValue(float f);
        /** Adition operator
        */
        Float operator+(const Float & F);
        /** Adition operator 2
        */
        Float operator+(float f);
        /** Substraction operator
        */
        Float operator-(const Float & F);
        /** Substraction operator 2
        */
        Float operator-(float f);
        /** Multiplication operator
        */
        Float operator*(const Float & F);
        /** less operator
        */
        bool operator<(const Float & F);
    private:
        float _value;
};
}

#endif
