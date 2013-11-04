/***************************************************************************
 *
 *   Creation Date: 10/23/2013
 *   Author:        ZePoLiTaT
 *   File:          point2d.cpp
 *   Class:         Point2D
 *
 *   Modifications:
 *      10/23/2013 - Creation
 *
 ***************************************************************************/

#include "point2d.h"
#include <iostream>

using namespace std;

Point2D::Point2D()
{
    setX(0);
    setY(0);

    prev = NULL;
    next = NULL;
}

Point2D::Point2D(float px, float py)
{
    setX(px);
    setY(py);
}

Point2D::Point2D(Point2D &p)
{
    setX(p.x);
    setY(p.y);
}

void Point2D::askvalue()
{
    cout<<"Dear user, can you provide a value for my variables x and y?: "<<endl;
    cin>>(this->x)>>(this->y);
}

void Point2D::display()
{
    cout<<x<<", "<<y<<endl;
}


void Point2D::setXY(const float *px, const float *py)
{
    this->x = *px;
    this->y = *py;
}


ostream &operator<<(ostream &os, const Point2D &p)
{
    os << "(" << p.x << " , " << p.y << ")"<<endl;
    return os;
}
