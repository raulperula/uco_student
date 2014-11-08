#ifndef _DOG_H
#define _DOG_H

/**
 * @file    dog.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <string>
#include <iostream>
#include <animal.h>

using namespace std;

namespace animals{
    class Dog: public Animal{
        public:
            Dog(): Animal() {_hair="no hair";}
            Dog(const Dog &D): Animal(D) {_hair=D._hair;}
            void setHair(string hair){_hair=hair;}
            string getHair(){return _hair;}
            void guauu(){cout<<"guaaauuuuu"<<endl;}
            void eat(){cout<<"dog eat meat"<<endl;}
            int getEspecie(){ return 2;}
            int regSize(){ return (2*sizeof(string)+sizeof(time_t));}
            void writeToStream(ostream& str){
                string name=getName();
                time_t birth=getDateOfBirth();
                str.write((char*)&name,sizeof(string));
                str.write((char*)&birth,sizeof(time_t));
                str.write((char*)&_hair,sizeof(string));
            }
            void readFromStream(istream& str){
                string name=getName();
                time_t birth=getDateOfBirth();
                str.read((char*)&name,sizeof(string));
                str.read((char*)&birth,sizeof(time_t));
                str.read((char*)&_hair,sizeof(string));
            }
        private:
            string _hair;
    };
}

#endif
