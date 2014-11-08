#ifndef _Contact_H_
#define _Contact_H_

/**
 * @file    contact.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

namespace contacts
{
class Contact
{
public:
    /**
    */
    Contact(){}
    /**
    */
    Contact(string name,int phone)
    {
        _name=name;
        _phone=phone;
    }
    /**
    */
    Contact(const Contact & C)
    {
        _name=C._name;
        _phone=C._phone;
    }
    /**
    */
    void setName(string name)
    {
        _name=name;
    }

    /**
    */
    string getName()
    {
        return _name;
    }

    /**
    */
    void setPhone(int phone)
    {
        _phone=phone;
    }
    /**
    */
    int getPhone()
    {
        return _phone;
    }

    /**
    */
    Contact & operator=(const Contact &C)
    {
        _name=C._name;
        _phone=C._phone;
        return *this;
    }

    /**
    */
    bool operator==(const Contact &C)
    {
        return _name==C._name && _phone==C._phone;
    }

    /**
    */
    void print()
    {
        cout<<"Contact Name="<<_name<<" Phone="<<_phone<<endl;
    }
private:
    string _name;
    int _phone;
};
}
#endif
