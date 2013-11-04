#include <iostream>
#include "point2d.h"
#include "polygon.h"

using namespace std;

int main()
{
    /*************************************************/
    /************* TESTING POINT2D CLASS *************/
    /*************************************************/

    Point2D p1;

    //Ask for the input
    p1.askvalue();
    p1.display();

    //Play with the setters by reference
    p1.setX(58);
    p1.setY(-1.5);
    p1.display();

    //Set the x and y values using the setter by value
    float a=46, b=56;
    p1.setXY(&a, &b);
    cout<<"Testing << overload!: "<<p1<<endl;


    /*************************************************/
    /************* TESTING POLYGON CLASS *************/
    /*************************************************/

    Polygon p;
    p.buildPolygon(3);
    p.display();
    cout<<"The size of your polygon is: "<<p.size()<<endl;
    cout<<"The 2nd item is "<<*p.get_item(2)<<endl;

    Point2D *p2 = new Point2D();
    p2->askvalue();
    p.insert_at(p2, 0);
    p.display();

    return 0;
}

