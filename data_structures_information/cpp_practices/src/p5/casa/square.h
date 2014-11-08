#ifndef _Square_H_
#define _Square_H_

/**
 * @file    square.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <iostream>
#include <shapes.h>

using namespace std;
namespace shapes{

class Square: public Shapes
{
    public:
    /**Empty constructor
        */
    Square() : Shapes() { _squareSize=0;}
    /**copy constructor
    */
    Square(const Square & SQ) : Shapes(SQ) { _squareSize=SQ._squareSize;}
    /**Set the Square size
    */
    void setSquareSize(int ss){_squareSize=ss;}
    /**Get the Square size
    */
    int getSquareSize(){return _squareSize;}
    /**
    */
    void draw(){
        int x,y;
        getPosition(x,y);
        cout<<"x,y="<<x<<" "<<y<<" color="<<getColor()<<" SquareSize="<<_squareSize<<endl;
        }

    private:
    int _squareSize;
};
}

#endif
