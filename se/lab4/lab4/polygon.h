/***************************************************************************
 *
 *   Creation Date: 10/23/2013
 *   Author:        ZePoLiTaT
 *   File:          polygon.h
 *   Class:         Polygon
 *
 *   Modifications:
 *      10/23/2013 - Creation
 *
 ***************************************************************************/

#ifndef POLYGON_H
#define POLYGON_H

#include "point2d.h"
#include <iostream>

using namespace std;

class Polygon
{
private:
    Point2D *start;
public:
    Polygon();
    Polygon(const Polygon &){}
    ~Polygon();

    void buildPolygon(unsigned const int &);
    void display();

    Point2D *begin();
    int size();
    Point2D *get_item(unsigned const int &) ;
    bool insert_at(Point2D *, const unsigned int &);
    bool delete_at(const unsigned int &);

    Point2D* &operator [] (unsigned int);
    //Point2D* operator [] (unsigned int) const;
    friend ostream& operator <<(ostream &, const Polygon &);
};

#endif // POLYGON_H
