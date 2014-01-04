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
    if(start==NULL) return;

    Point2D *it = start;
    Point2D *cur;

    do
    {
        cur = it;
        it = it->next;
        if(cur!=NULL)
            delete cur;
    }
    while(it != start);
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
    for(unsigned int i=1; i<n; i++)
    {
        cur = new Point2D;
        cur->askvalue();

        cur->prev = last;
        last->next = cur;

        last = cur;
    }

    //Make it circular (as shown in the pdf output sample)
    last->next = start;
    start->prev = last;
}

void Polygon::display()
{
    cout<<(*this);
}

Point2D *Polygon::begin()
{
    return start;
}

int Polygon::size()
{
    //If there are no points -> size=0
    if(start==NULL)
        return 0;

    int n = 0;
    Point2D *it = start;

    do
    {
        n++;
        it = it->next;
    }
    while(it != start);

    return n;
}

Point2D* Polygon::get_item(const unsigned int &n) const
{
    //If there are no points -> get_item()=NULL
    if(start==NULL)
        return NULL;

    unsigned int i = 0;
    Point2D *it = start;
    do
    {
        if(i==n) return it;

        i++;
        it = it->next;
    }
    while(it != NULL);

    return NULL;
}


bool Polygon::insert_at(Point2D *newIt, const unsigned int &n)
{
    Point2D *oldIt;
    unsigned int pSize = size();

    //User wants to insert at the begining
    if(n==0)
    {
        //if the polygon is empty, the element to link will be itself
        if(pSize == 0)
            oldIt=newIt;
        //Otherwise, the element to link with will be the origin
        else
            oldIt=start;

        //Update the starting point of the polygon
        start = newIt;
    }
    else
    {
        //If the user wants to insert in a position larger
        //than the size of the polygon, its wrong!
        if(pSize<n) return false;

        if(pSize == n)
            oldIt = start;
        else
            oldIt = get_item(n);
    }

    //Once we have the old item at the insertion point, it is just a matter to link it with the new item
    newIt->next = oldIt;
    newIt->prev = oldIt->prev;

    if(oldIt->prev!=NULL)
        oldIt->prev->next = newIt;
    oldIt->prev = newIt;

    return true;
}

bool Polygon::delete_at(const unsigned int &n)
{
    Point2D *delIt = get_item(n);

    if(delIt!=NULL)
    {
        //If deleting 1st point, then start must be updated
        if(n==0)
        {
            //If there was only one item, the new list will be empty
            if(start == start->next)
                start = NULL;
            //Otherwise, update the new starting point
            else
                start = delIt->next;
        }

        delIt->prev->next = delIt->next;
        delIt->next->prev = delIt->prev;

        delete delIt;
        return true;
    }
    else
        return false;
}

Point2D Polygon::operator [] (unsigned int n) const
{
    Point2D *it = get_item(n);
    return *it;
}

Point2D &Polygon::operator [] (unsigned int n)
{
    Point2D *it = get_item(n);
    return *it;
}

ostream& operator<<(ostream &os, const Polygon &p)
{
    if(p.start==NULL) return os;
    int idx = 0;

    Point2D *it = p.start;
    do
    {
        os<<"index("<<(idx++)<<") address["<<it<<"]"<<endl;
        os<<"  "<<*it;
        it = it->next;
    }
    while(it != p.start);

    return os;
}
