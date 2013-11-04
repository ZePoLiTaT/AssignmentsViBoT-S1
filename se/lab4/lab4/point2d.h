/***************************************************************************
 *
 *   Creation Date: 10/23/2013
 *   Author:        ZePoLiTaT
 *   File:          point2d.h
 *   Class:         Point2D
 *
 *   Modifications:
 *      10/23/2013 - Creation
 *
 ***************************************************************************/

#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
using namespace std;

class Point2D
{
private:
    float x,y;                      //The x and y coordenates of the systems
public:
    Point2D *next;
    Point2D *prev;

    Point2D();
    Point2D(float, float);
    Point2D(Point2D&);
    ~Point2D(){}

    void setX(const float &px) {this->x = px; }       //Setter of the x variable by reference
    void setY(const float &py) {this->y = py; }       //Setter of the y variable by reference
    float getX(){ return x; }
    float getY(){ return y; }


    void setXY(const float *, const float *);   //Setter with pointers

    void askvalue();
    void display();

    friend ostream &operator <<(ostream &, const Point2D &);
};

#endif // POINT2D_H
