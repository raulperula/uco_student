#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

/**
 * @file    employee.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <register.h>
#include <iostream>
#include <string>

using namespace storage;
using namespace std;

namespace company{
class Employee: public Register
{
    public:
        enum Positions{mantainace=0,proffessor=1,cathedratic=2};

        /**Empty Constructor
        */
        Employee(){
                    strcpy(_name,"invalid");
                    _dateOfBirth=0;
                    _salary=0;
                    _position=mantainace;
                    }
        /**Copy Constructor
        */
        Employee(const Employee &E){strcpy(_name,E._name);
                                    _dateOfBirth=E._dateOfBirth;
                                    _salary=E._salary;
                                    _position=E._position;
                                    }
        /**
        */
        char * getName(){return _name;}
        void setName(char * n){strcpy(_name,n);}
        time_t getDateOfBirth(){return _dateOfBirth;}
        void setDateOfBirth(time_t t){_dateOfBirth=t;}
        float getSalary(){return _salary;}
        void setSalary(float s){_salary=s;}
        Positions getPosition(){return _position;}
        void setPosition(Positions p){_position=p;}
        bool operator==(const Employee & E){
        return strcmp(_name,E._name)==0 && _dateOfBirth==E._dateOfBirth;}
        Employee & operator=(const Employee & E)
        {
            strcpy(_name,E._name);
            _dateOfBirth=E._dateOfBirth;
            _salary=E._salary;
            _position=E._position;
            return *this;
        }
        friend  ostream& operator<< (ostream &str, const Employee &E){
            str<<E._name<<" "<<E._dateOfBirth<<" "<<E._salary<<" "<<E._position<<endl;
            return str;
        }
        int getSignature(){
            return 1;
        }
        void writeToStream(ostream & str){
            str.write(_name,100*sizeof(char));
            str.write((char*)&_dateOfBirth,sizeof(time_t));
            str.write((char*)&_salary,sizeof(float));
            str.write((char*)&_position,sizeof(Positions));
        }
        void readToStream(istream &str){
            str.read(_name,100*sizeof(char));
        cout<<"reading "<<_name<<endl;
            str.read((char*)&_dateOfBirth,sizeof(time_t));
            str.read((char*)&_salary,sizeof(float));
            str.read((char*)&_position,sizeof(Positions));
        }
        int getSizeOfRegister(){
            int size=0;
            size+=100*sizeof(char);
            size+=sizeof(time_t);
            size+=sizeof(float);
            size+=sizeof(Positions);
            return size;
        }




    private:
        char _name[100];
        time_t _dateOfBirth;
        float _salary;
        Positions _position;
};


}

#endif
