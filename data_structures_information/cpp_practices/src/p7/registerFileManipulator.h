#ifndef _RegisterFileManipulator_H__
#define _RegisterFileManipulator_H__

/**
 * @file    registerFileManipulator.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <register.h>
#include <string>
#include <fstream>

using namespace std;
namespace storage
{
/**\brief This class allows to keep a file with registers
*
*The file has the following format:
_signature _nElments REG(0) REG(1) ... REG(NELEMENTS-1)
Where:
_signature:Integer that indicates the type of register
_nElments: Integer that indicates the total number of registers
REG(i): i-th register
*/
class  RegisterFileManipulator
{
    public:
        /**Emtpy constructor
        */
        RegisterFileManipulator();

        /**Parametrized constructor. Creates an object opening the file indicated
        *@param filePath path to the file to be managed
        */
        RegisterFileManipulator(string filePath);

        /**Destructor. Closes the file if opened
        */
        ~RegisterFileManipulator();
        /**Opens a file. If the objet has already an opened file, the program is aborted.
        *
        * If the file is not created, this function creates it. Then, writes the _signature. Since at this point   _signature is not known, writes -1 indicating that the signature is not valid yet. Then, writes the _nElments that at this point must be 0.
        *
        * If the file is already created, the function reads _signature and _nElments.
        *
        *@param true if  the file can be opened withour problems. false if the file can't be opened
        */
        bool open(string filePath);

        /**Indicates wherther the file is already opened
        */
        bool isOpen() const;

        /**Closes the file if opened.If it is not opened, does nothing
        */
        void close();
        /**When the file is opened, returns the signature of the class stored in the file.
        * If the file does not contains any register yet, returns -1.
        */
        int getSignature()const;

        /**Returns the number of registers in the file
        */
        unsigned int size()const;

        /**Adds a register to the end of the file.
        *
        * If the file is not opened, the program is aborted.
        *
        * If it is the first register to be written, first, get the _signature from the Register. Second, write _signature in the file. Thrid, write the new value of _nElments in the file. Finally, write the register
        *
        * If it is not the first register in the file, the function must examine wherther * the signature of the register passed is the one of the elements already stored in the file. If so,  write the register at the end of the file, and then, update  _nElments in the file.
        *
        * In case, the register passed as parameters is not of the same type than these stored previously, the register is not written and the function returns false.
        *
        *@return true if the register can be written and false otherwise
        */
        bool add(Register *R);
        /**Reads the i-th register and the information is introduced in "r"
        *
        * If the file has not elements, return false and "r" is not modified
        *
        * If the file is closed, return false and "r" is not modified
        *
        * If "i" is greater or equal than _nElments, return false and "r" is not modified
        *
        * If the signature of "r" is no the same that the _signature of the file, returns false and "r" is not modified
        *
        * Else, "r" contains the information of the i-th register and true is returned
        *
        *Note: you can set the put pointer in the position desired using the Register::getSizeOfRegister function
        */
        bool read(unsigned int i,Register *r) ;

        /**Overwrites the register indicated. This function goes to the position of the register indicated and rewrites it with the new value passed.
        *
        * If the file is closed, return false and the file is not modified

        * If the signature of "r" is no the same that the _signature of the file, returns false and the file is not mdified.
        *
        * If "i" is greater or equal that the number of elements, returns false and the file is not modified.
        *
        * Else, rewrites the i-th register with "r" and returns true
        *
        *Note: you can set the put pointer in the position desired using the Register::getSizeOfRegister function
        */
        bool overWrite(unsigned int i,Register *r);

    private:
        //This object manipulates the file. Open it for I/O access
        fstream _file;
        //Number of registers in the file
        unsigned int _nElements;
        //Signture of the elements in the file
        int _signature;
        bool _isOpen;
};

};
#endif
