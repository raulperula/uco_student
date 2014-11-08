#ifndef _ANIMALREG_H_
#define _ANIMALREG_H_

/**
 * @file    animalreg.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <fstream>
#include <animal.h>

using namespace std;
using namespace animals;

namespace registers{
    class Animalreg{
        public:
            Animalreg();
            Animalreg(string path);
            ~Animalreg();
            bool open(string path);
            bool isOpen();
            void close();
            int getEspecie();
            int getSize();
            bool add(Animal* A);
            bool read(int i, Animal* A);
            bool overWrite(int i, Animal* A);
        private:
            fstream _file;
            int _nElements;
            int _especie;
            bool _isOpen;
    };
}

#endif
