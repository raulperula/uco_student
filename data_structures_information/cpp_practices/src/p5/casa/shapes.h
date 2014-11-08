#ifndef _Shapes_H_
#define _Shapes_H_

/**
 * @file    shapes.h
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
namespace shapes
{

class Shapes
{
    public:
    /**Empty constructor
        */
    Shapes(){ _x=0;_y=0;_color=0;}
    /**copy constructor
    */
    Shapes(const Shapes & S) { _x=S._x;_y=S._y;_color=S._color;}
    /**Get the object position
    */
    void getPosition(int &x, int &y){ x=_x;y=_y;}
    /**Set the object position
    */
    void setPosition(int x, int y){_x=x;_y=y;}
    /**Get the object color
    */
    int getColor(){return _color;}
    /**Set the object color
    */
    void setColor(int c){ _color=c;}
    /**Draw Object
    */
    virtual void draw()=0;

    private:
    int _x;
    int _y;
    int _color;
};
}

#endif
