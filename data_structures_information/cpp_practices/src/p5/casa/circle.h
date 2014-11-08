#ifndef _Circle_H_
#define _Circle_H_

/**
 * @file    circle.h
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

class Circle: public Shapes
{
    public:
    /**Empty constructor
        */
    Circle(): Shapes() { _radius=0;}
    /**copy constructor
    */
    Circle(const Circle & C): Shapes(C) { _radius=C._radius;}
    /**Set the Circle radius
    */
    void setRadius(int r){_radius=r;}
    /**Get the Circle radius
    */
    int getRadius(){return _radius;}
    /**Draw the object
    */
    void draw(){
            int x,y;
            getPosition(x,y);
            cout<<"x,y="<<x<<" "<<y<<" color="<<getColor()<<" radius="<<_radius<<endl;
        }
    private:
    int _radius;
};
}

#endif
