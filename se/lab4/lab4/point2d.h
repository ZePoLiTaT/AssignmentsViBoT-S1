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

/**
 * @class Point2D
 * @brief Point2D The Point2D class represents a point in R2.
 * It contains a reference to the next and previous points
 * which can be used as elements in a double linked list
 */
class Point2D
{
private:
    float x,y;        /** The x and y coordenates of the systems*/
public:
    Point2D *next;    /** Pointer to the next point*/
    Point2D *prev;    /** Pointer to the previous point*/

    /**
     * @brief Point2D Default constructor.
     * Initializes the x,y values to the origin of coordinates (0,0)
     * and the next and previous pointer to NULL
     */
    Point2D();

    /**
     * @brief Point2D Initializes the point with the given position in the plane x,y
     */
    Point2D(float, float);

    /**
     * @brief Point2D Copy constructor that clones the given coordinate system (x,y)
     * It does not copy the value of the Next,Prev references
     */
    Point2D(const Point2D&);

    /**
     * @brief Point2D destructor.
     */
    ~Point2D(){}

    /**
     * @brief Sets the value of the x coordinate by reference
     * @param px New value of the x coordinate
     */
    void setX(const float &px) {this->x = px; }

    /**
     * @brief Sets the value of the y coordinate by reference
     * @param py New value of the y coordinate
     */
    void setY(const float &py) {this->y = py; }

    /**
     * @brief Return the value of the x coordinate of the point
     * @return Value of the x coordinate
     */
    float getX(){ return x; }

    /**
     * @brief Return the value of the y coordinate of the point
     * @return Value of the y coordinate
     */
    float getY(){ return y; }

    /**
     * @brief Update the value of the x and y coordinate by pointer
     * @param px Pointer with the new value of the x coordinate
     * @param py Pointer with the new value of the y coordinate
     */
    void setXY(const float *px, const float *py);

    /**
     * @brief Asks the user to input a value for the x and y coordinates
     */
    void askvalue();

    /**
     * @brief Show the value of the x and y coordinates by using the
     * overload operator <<
     */
    void display();

    /**
     * @brief Overload of the = operator in order to make valid assignments
     * between points. This is mainly used in the last test of the main where
     * the asingment between points is performed like this: p[1] = p[2];
     * @return A reference to the value of the Point2D after the assignment
     */
    Point2D &operator= (const Point2D &);

    /**
     * @brief Overload of the << operator in order to print
     * the relevant information of a Point2D.
     * This operator is marked as a friend and is not implemented inside
     * the Point2D class because the << operator belongs to the ostream
     * class and here we are just overloading it to work with our
     * object which is of type Point2D.
     * In other words, recall that the other to invoke a binary operator a@b is
     * A::operator@(B) -- operator(A,B)
     * As can be seen here, the owner of the operator is the first class
     * which is ostream and not Point2D
     * @return The
     */
    friend ostream &operator <<(ostream &, const Point2D &);
};

#endif // POINT2D_H
