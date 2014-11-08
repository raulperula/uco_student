#ifndef _REGISTER_H_
#define _REGISTER_H_

/**
 * @file    register.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <iostream>

using namespace std;
namespace storage
{
class Register
{
    public:
    virtual int getSignature()=0;
    virtual void writeToStream(ostream & str)=0;
    virtual void readToStream(istream &str)=0;
    virtual int getSizeOfRegister()=0;

};
}

#endif
