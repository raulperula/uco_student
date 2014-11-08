#ifndef _CAT_H
#define _CAT_H

/**
 * @file    cat.h
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
#include <fstream>
#include <animal.h>
#include <animalreg.h>

using namespace std;
using namespace registers;

namespace animals{
    class Cat: public Animal{
        public:
            Cat(): Animal() {_hair="no hair";}
            Cat(const Cat &C): Animal(C) {_hair=C._hair;}
            void setHair(string hair){_hair=hair;}
            string getHair(){return _hair;}
            void miauu(){cout<<"miaaauuuuu"<<endl;}
            void eat(){cout<<"cat eat birds"<<endl;}
            friend ostream& operator<<(ostream& out,Cat &C){
                out<<C.getName()<<" "<<C.getDateOfBirth()<<" "<<C._hair<<endl;
                return out;
            }
            int getEspecie(){ return 1;}
            int regSize(){ return (2*sizeof(string)+sizeof(time_t));}
            void writeToStream(ostream& str){
                string name=getName();
                time_t birth=getDateOfBirth();
                str.write((char*)&name,sizeof(string));
                str.write((char*)&birth,sizeof(time_t));
                str.write((char*)&_hair,sizeof(string));
            }
            void readFromStream(istream& str){
                string name;
                time_t birth;
                str.read((char*)&name,sizeof(string));
                str.read((char*)&birth,sizeof(time_t));
                str.read((char*)&_hair,sizeof(string));
                setName(name);
                setDateOfBirth(birth);
            }
        private:
            string _hair;
    };
}

#endif
