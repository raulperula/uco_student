#ifndef _Contact_List_H_
#define _Contact_List_H_

/**
 * @file    contactlist.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <vector.h>
#include <iostream>
#include <contact.h>

using namespace std;
using namespace storage;

namespace contacts
{
/**\brief Contact list
*/
class ContactList:private Vector<Contact>
{
    public:
        /**
        */
        ContactList(){
            _nContacts=0;//number of contacts currently in the list
            resize(5); //Maximum number of initial contact
        }
        /**
        */
        ~ContactList(){}
        /**Adds a contact to the list if it is not yet
        */
        void add(const Contact &C)
        {
            if(!isContact(C)){
                //See if we reached the maximum
                if (_nContacts==Vector<Contact>::size()) {
                    //yes, resize the vector
                    //first, keep a copy
                    Vector<Contact> copy=(*this);
                    resize(size()+5);
                    for(unsigned int i=0;i<copy.size();i++)
                        (*this)[i]=copy[i];
                }
                //Now, add the element
                (*this)[_nContacts]=C;
                _nContacts++;
            }
        }
        /**Indicates if there is the contact indicated
        */
        bool isContact(const Contact &C)
        {
            for(unsigned int i=0;i<Vector<Contact>::size();i++)
                if ((*this)[i]==C) return true;
            return false;
        }
        /**Indicates the number of contacts in the list
        */
        int size(){return _nContacts;}
        /**prints the contacts
        */
        void print()
        {
            for(unsigned int i=0;i<size();i++)
            {
                (*this)[i].print();
            }
        }
        /**Delete a contact
        */
        int delete_contact(const Contact &C){
            unsigned int i,j,pos;
            int encontrado=0;
            Vector<Contact> copy(size());
            for(i=0;i<size()-1;i++){
                if((*this)[i]==C){//if C is the contact, makes a copy of the contacts below
                    for(j=i+1;j<size()-1;j++){
                        copy[j]=((*this)[j]);
                    }
            pos=i;//mark the position of the contact finded
                    i=size();
                    encontrado=1;
                }
            }
            if(encontrado==1){
                for(i=pos;i<size()-2;i++){
                    (*this).add(copy[i+1]);
                }
        _nContacts=size()-1;//decrement the number of contacts in one unit
            }
            //returns 1 if find the contact and 0 if doesn't find it
            return encontrado;
        }

    private:
    int  _nContacts;
};
};

#endif
