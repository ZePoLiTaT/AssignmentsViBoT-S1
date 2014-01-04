#ifndef CTABLE_H
#define CTABLE_H

#include <iostream>

#define MAXNUM 20
#define DEFVAL 5

using namespace std;

/**
 * @class CTable
 * @brief The CTable class contains a dynamic table of integers (dynamically allocated).
 * - It provides the following sorting methods:
 *  - Bubble Sort
 *  - Quick Sort
 *  - Selection Sort
 *  - Insertion Sort
 *
 * - Some utilitary functions are also provided in order to help the sorting
 * algorithms. For example, swap(..) is used by Bubble Sort, Quick Sort and
 * Insertion Sort, whereas insert(..) is used by Insertion Sort
 *
 * - The overloaded << operator displays the relevant information about this object.
 *   That is to say, it concatenates the value of all the elements into the ostream given.
 *   The display function just invokes the overloaded << with cout and *this
 *
 * In order to analyze each algorithm, the following definitions are provided:
 * - Temporal Complexity \cite leiserson2001introduction : The running time of an algorithm on a particular input is the number of primitive operations or “steps” executed.
 *   O-notation is used to give an upper bound on a function, to within a constant factor.
 * - Spatial Complexity \cite spatialcomp : This is essentially the number of memory cells which an algorithm needs.
 *   There is often a time-space-tradeoff involved in a problem, that is,
 *   it cannot be solved with few computing time and low memory consumption.
 *   One then has to make a compromise and to exchange computing time for memory consumption or vice versa,
 *   depending on which algorithm one chooses and how one parameterizes it.
 */
class CTable
{
    int *elems;         /** Pointer to the dynamically allocated integers of the table */
    unsigned int n;     /** Number of elements in the array */

    /**
     * @brief partition This is a helper function for quickSort.
     * It performs the partitioning step as described in the exercise:
     * "- Split the initial list of numbers into parts around a "pivot";
     *    all the values in the first part are less than the pivot; all the values in the second
     *    part are greater than or equal to the pivot"
     * @return The new pivot
     */
    int partition(int, int);
public:
    /**
     * @brief CTable Default constructor. If no value for the parameter is specified
     * then the table is initialized with the number given by DEFVAL
     * @param ne Number of elements
     */
    CTable(unsigned const int &ne = DEFVAL);

    /**
     * @brief Destructor of the class
     */
    ~CTable();

    /**
     * @brief initialize Randomly initalizes the array with numbers between 0
     * and MAXNUM
     */
    void initialize();

    /**
     * @brief display Shows in the stdout the relevant information of the
     * table, which means all the elements contained in it.
     * It calls cout with the overloaded operator << for CTable
     */
    void display();

    /**
     * @brief insert Utilitary function used in the insertSort algorithm.
     * It inserts an element in a given position (old_idx) into a new
     * position of the array (new_idx) by shifting all the elements to the
     * right of new_it up to old_idx
     * @param old_idx Old position of the element
     * @param new_idx New position of the element. This is the new place were we want the element to be.
     */
    void insert(const unsigned int old_idx, const unsigned int new_idx);

    /**
     * @brief read Reads an element in a given position of the table determined by the parameter idx
     * @param idx Position of the element to be read
     * @return The element at the idx position
     */
    int read(unsigned const int idx);

    /**
     * @brief swap Swaps an element between the idx1 position and the idx2 position inside the table
     * @param idx1 Index of the 1st element we want to swap
     * @param idx2 Index of the 2nd element that will be swapped with the 1st
     */
    void swap(unsigned const int idx1, unsigned const int idx2);

    /**
     * @brief bubbleSort works as described in the exercise:
     * "Scans the array, comparing each pair of adjacent elements.
     * If two adjacent elements are out of order, they are swapped."
     *
     * The efficiency of the algorithm not only depends only on the size of the table.
     * Since not aditional memory is needed to run the algorithm, the spatial
     * complexity is of order \f$ O(1) \f$.
     * However, the temporal complexity is of the order \f$ O(n^2) \f$
     * in all cases. There is no worst or best case scenario becuase it always
     * performs the same amount of iterations.
     */
    void bubbleSort();

    /**
     * @brief quickSort works as described in the exercise:
     * - "Split the initial list of numbers into parts around a "pivot";
     *   all the values in the first part are less than the pivot; all the values in the second
     *   part are greater than or equal to the pivot.
     * - recursively sort the two parts.
     *
     * The implementation used here was recursive with inline ordering, which means that
     * the ordering is directly performed in the original array with no copies of it.
     * At each step, two recursive calls are made: one on the elements lower than the pivot
     * and other on the elments greater than it. For example, if the analyzed element given
     * by the pivot is always in the middle of the partition and there are \f$ n=2^k\f$ elements in the array,
     * then k levels partitions will be needed (\f$k=log_2(2^k)\f$).
     * Also, each partition has a temporal complexity of \f$O(n)\f$.
     * Therefore, the total temporal complexity is \f$O(n.log(n))\f$.
     * The spatial complexity is given by the total number of recursive calls, that is to say
     * \f$O(log(n))\f$.
     * As stated in \cite leiserson2001introduction the selection of the pivot randomly can improve
     * the worst case scenario in which all elements are ordered, which can lead to
     * \f$O(n^2)\f$ if the first element is always chosen as a pivot.
     * @param limi Lower bound of the sub-array that will be sorted. Set this value to 0
     * and lims to n if you want to sort all the array
     * @param lims Upper bound of the sub-array that will be sorted.
     */
    void quickSort(int limi, int lims);

    /**
     * @brief selectionSort works as described in the exercise:
     * "In selection sort the array is divided into two parts: the first part that is
     *  sorted and the second part that is not sorted yet.
     *  Initially the sorted part is empty and the unsorted part consists of the whole array.
     *  In each step, the algorithm searches through the unsorted part, finds the smallest element
     *  and puts it at the end of the sorted part."
     *
     * The efficiency of the algorithm not only depends only on the size of the table.
     * Since not aditional memory is needed to run the algorithm, the spatial
     * complexity is of order \f$ O(1) \f$.
     * The temporal complexity is equal to the bubbleSort (of the order \f$ O(n^2) \f$)
     */
    void selectionSort();

    /**
     * @brief insertSort works as described in the exercise:
     * "Divides the array into a sorted and an unsorted
     * part. Each step of the algorithm picks the first item of the unsorted
     * array (x) and inserts it into the right slot of the
     * sorted array. The elements of the sorted array > x are shifted
     * one location forward."
     *
     * The efficiency of the algorithm not only depends on the size
     * but also on how "ordered" are the elements initially, because
     * each unordered element will cause a shift in the ordered part
     * just to place it in the right position.
     *
     * The implementation uses inline ordering, which means that
     * every time I find an unordered element, I insert it in the empty
     * slot after shifting all the previous ordered elements that are
     * greater than it, but I do not create a new item and then delete the
     * old one because that would need a new allocation or resize of the array
     * twice.
     *
     * Since not aditional memory is needed to run the algorithm, the spatial
     * complexity is of order \f$ O(1) \f$.
     * However, the temporal complexity is of the order \f$ O(n^2) \f$
     * because, in the worst case scenario, the array will be in reverse order
     * which means that for every element we are analyzing we must shift the entire
     * array.
     * It is worth to notice that in the best case scenario (ordered table)
     * then the temporal complexity will be linear \f$ O(1) \f$.
     */
    void insertSort();

    /**
     * @brief operator << is overloaded in order to support the concatenation
     * of the relevant information of CTable into an ostream flow.
     * That is to say, all the data of the array is shown, each element separated
     * by spaces
     * @param os output stream into which the CTable info will be concatenated
     * @param ctable CTable object
     * @return A reference to the output stream object
     */
    friend ostream &operator <<(ostream &os, const CTable &ctable);
};

#endif // CTABLE_H
