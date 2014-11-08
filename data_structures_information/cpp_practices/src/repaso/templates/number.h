#ifndef _NUMBER_H_
#define _NUMBER_H_

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

namespace values{
    template<class Type>
    class Number{
        public:
            Number(){_value=0;}
            Number(Type v){_value=v;}
            Number(const Number & N){_value=N._value;}
            void setValue(Type v){_value=v;}
            Type getValue(){return _value;}
            Number & operator=(const Number & N){_value=N._value;return *this;}
            Number operator+(const Number & N){
                Number aux;
                aux=_value+N._value;
                return aux;
            }
            Number operator+(Type v){
                Number aux;
                aux=_value+v;
                return aux;
            }
            bool operator<(const Number &N){return (_value<N._value);}
        private:
            Type _value;
    };
};

#endif
