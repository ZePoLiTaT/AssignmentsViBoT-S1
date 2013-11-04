/***************************************************************************
 *
 *   Creation Date: 10/23/2013
 *   Author:        ZePoLiTaT
 *   File:          polygon.cpp
 *   Class:         Polygon
 *
 *   Modifications:
 *      10/23/2013 - Creation
 *
 ***************************************************************************/

#include "polygon.h"

Polygon::Polygon()
{
    start = NULL;
}

Polygon::~Polygon()
{
    if(start != NULL)
        delete start;
}

void Polygon::buildPolygon(unsigned const int &n)
{
    if(n==0) return;

    Point2D *cur, *last = NULL;

    //Create and fix the root of the polygon
    start = new Point2D;
    start->askvalue();
    last = start;

    //Create all the nodes and link them
    for(unsigned int i=0; i<(n-1); i++)
    {
        cur = new Point2D;
        cur->askvalue();

        cur->prev = last;
        last->next = cur;

        last = cur;
    }
}

void Polygon::display()
{
    Point2D *it = start;
    while(it != NULL)
    {
        it->display();
        it = it->next;
    }
}

Point2D *Polygon::begin()
{
    return start;
}

int Polygon::size()
{
    int n = 0;

    Point2D *it = start;
    while(it != NULL)
    {
        n++;
        it = it->next;
    }

    return n;
}

Point2D* Polygon::get_item(const unsigned int &n)
{
    unsigned int i = 0;

    Point2D *it = start;
    while(it != NULL)
    {
        if(i==n) return it;

        i++;
        it = it->next;
    }

    return NULL;
}

bool Polygon::insert_at(Point2D *item, const unsigned int &n)
{
    Point2D *it = get_item(n);

    if(it!=NULL)
    {
        item->next = it;
        item->prev = it->prev;

        it->prev = item;
        if(item->prev != NULL)
        {
            item->prev->next = item;
        }
        return true;
    }
    else
        return false;
}

bool Polygon::delete_at(const unsigned int &n)
{
    Point2D *it = get_item(n);

    if(it!=NULL)
    {
        if(it->prev != NULL)
            it->prev->next = it->next;
        if(it->next != NULL)
            it->next->prev = it->prev;

        delete it;
        return true;
    }
    else
        return false;
}

/*
Point2D* Polygon::operator [] (unsigned int n) const
{
    Point2D *it = get_item(n);
    return it;
}*/

Point2D* &Polygon::operator [] (unsigned int n)
{
    Point2D *it = get_item(n);
    return it;
}

ostream& operator<<(ostream &os, const Polygon &p)
{
    os<<"in construction ...";
    return os;
}
