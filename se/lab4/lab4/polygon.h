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

/**
 * @class Polygon
 * @brief Polygon The Polygon class that handles a collection of Point2D in a
 * circular double linked list.
 */
class Polygon
{
private:
    Point2D *start;    /** Starting point of the polygon */
public:
    /**
     * @brief Polygon constructor by default.
     * This sets the starting point to NULL which means that there are
     * no points in the polygon
     */
    Polygon();

    /**
     * @brief Destructor of the Polygon
     */
    ~Polygon();

    /**
     * @brief Creates a new Polygon of n points
     * and for each point asks the value for the value of
     * the x,y coordinates.
     * @param n Number of points of the polygon
     */
    void buildPolygon(unsigned const int &n);

    /**
     * @brief Displays the information of all the points inside the Polygon.
     * For each point it prints the index inside the Polygon, its address,
     * the x,y coordinate and previous and next adresses.
     */
    void display();

    /**
     * @brief Returns the starting point of the Polygon
     * @return The pointer to the first element of the Polygon
     */
    Point2D *begin();

    /**
     * @brief Returns the size of the Polygon by iterating until
     * it reaches again the starting point of the Polygon since
     * the linked list is circular. The complexity
     * of this function is O(n).
     * @return Return the number of elements in the Polygon
     */
    int size();

    /**
     * @brief Returns the Point2D given in a specific index
     * given by n
     * @param n The index of the desired Point2D
     * @return The Point2D at the position n in the Polygon
     */
    Point2D *get_item(unsigned const int &n) const;

    /**
     * @brief Inserts an element in a given position.
     * These special cases must be taken into account to initialize the *oldIt variable:
     *    1. The user wants to insert at the begining
     *       1.1 The polygon is empty -> Link the newIt with itself
     *       1.2 The polygon is not empty -> Link the newIt with the old starting point and update start
     *    2. The user wants to insert at the end -> Link the newIt with the starting point
     *    3. The user wants to insert in the middle -> Link the newIt with the oldIt that was before in that pos
     * @param newIt Pointer to the Point2D to insert
     * @param n Poisition at which item will be inserted
     * @return True if success, False otherwise
     */
    bool insert_at(Point2D *newIt, const unsigned int &n);

    /**
     * @brief Deletes an element in a given position.
     * When the element to delete is the starting point of the Polygon,
     * the start pointer must be updated to the next value of the old start
     * If there was only one element in the list, then the start point is
     * set to NULL
     * @param n Position at which the Point2D will be deleted
     * @return True if sucess, False otherwise
     */
    bool delete_at(const unsigned int &n);

    /**
     * @brief Overload of the bracket operator for to act
     * like a set in order to acess a
     * Point2D located at the given Position. This function
     * uses get_item() and returns a reference to the Point2D
     * @param n Position at which the Point2D is located
     * @return A reference to the Point2D
     */
    Point2D &operator [] (unsigned int n);

    /**
     * @brief Overload of the bracket operator for to act
     * like a get in order to acess a
     * Point2D located at the given Position. This function
     * does not modify anything inside the Polygon and only
     * returns a copy of the value
     * @param n Position at which the Point2D is located
     * @return The Point2D at the given location
     */
    Point2D operator [] (unsigned int n) const;

    /**
     * @brief Overload of the << operator in order to print
     * the information of all the points inside the Polygon.
     * For each point it prints the index inside the Polygon, its address,
     * the x,y coordinate and previous and next adresses.
     * This operator is marked as a friend and is not implemented inside
     * the Polygon class because the << operator belongs to the ostream
     * class and here we are just overloading it to work with our
     * object which is of type Polygon.
     * @return The
     */
    friend ostream& operator <<(ostream &, const Polygon &);
};

#endif // POLYGON_H
