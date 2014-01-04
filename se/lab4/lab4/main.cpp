#include <iostream>
#include "point2d.h"
#include "polygon.h"

using namespace std;

int main()
{
    /*************************************************/
    /************* TESTING POINT2D CLASS *************/
    /*************************************************/
    Point2D *p1 = new Point2D;

    //Play with the setters by reference
    p1->setX(999);
    p1->setY(222);
    p1->display();

    Point2D *p2 = new Point2D;

    //Ask for the input
    p2->askvalue();
    p2->display();

    /*************************************************/
    /************* TESTING POLYGON CLASS *************/
    /*************************************************/
    unsigned int nPoints;
    Polygon p;

    cout<<"How many points do you need for the Polygon?: "<<endl;
    cin>>nPoints;

    p.buildPolygon(nPoints);

    cout<<endl<<"--> Testing function display()"<<endl;
    p.display();

    cout<<endl<<"--> Testing function size() ["<<p.size()<<"] vs Real ["<<nPoints<<"]"<<endl;

    cout<<endl<<"--> Testing function get_item()"<<endl;
    for(unsigned int i=0; i<nPoints; i++)
    {
        cout<<"     - get_item("<<i<<") = "<<*p.get_item(i);
    }

    cout<<endl<<"--> Testing function insert_at()" <<endl;
    cout<<"     - Inserting p1 at position 0]"<<endl;
    p.insert_at(p1, 0);
    p.display();
    cout<<"     - Inserting p2 at position 3]"<<endl;
    p.insert_at(p2, 3);

    cout<<endl<<"--> Testing overload operator <<"<<endl;
    cout<<p<<endl;

    cout<<endl<<"--> Testing Bracket operator [] (Read value): p[0]"<<p[0]<<endl;
    p[1] = p[2];

    cout<<endl<<"--> Testing Bracket operator [] (Write) p[1]=p[2]"<<endl<<p<<endl;

    cout<<"--> Testing function delete_at() [Deleting start point]"<<endl;
    p.delete_at(0);
    cout<<"    Result after deletion: "<<p<<endl;

    return 0;
}
