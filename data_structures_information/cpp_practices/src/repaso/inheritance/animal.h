#ifndef _ANIMAL_H_
#define _ANIMAL_H_

/**
 * @file    animal.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <ctime>
#include <iostream>
#include <string>

using namespace std;

namespace animals{
    class Animal{
        public:
            Animal(){_name="no name";_dateOfBirth=0;}
            Animal(const Animal &A){_name=A._name;_dateOfBirth=A._dateOfBirth;}
            ~Animal(){}
            string getName(){return _name;}
            time_t getDateOfBirth(){return _dateOfBirth;}
            void setName(string name){_name=name;}
            void setDateOfBirth(time_t birth){_dateOfBirth=birth;}
            virtual void eat()=0;
            virtual int getEspecie()=0;
            virtual int regSize()=0;
            virtual void writeToStream(ostream& str)=0;
            virtual void readFromStream(istream& str)=0;
        private:
            string _name;
            time_t _dateOfBirth;
    };
}

#endif
