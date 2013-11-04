/***************************************************************************
 *
 *
 *   Creation Date: 11/2/2013
 *   Author:        ZePoLiTaT
 *   File:          monoarray.cpp
 *   Class:
 *
 *   Modifications:
 *      11/2/2013 - Creation
 *
 ***************************************************************************/

#include "monoarray.h"
#include <iostream>

using namespace std;

////////////////////////// MONODIMENTIONAL ARRAYS //////////////////////////////////
/**
 * @brief allocateArray reserves memory for n integers
 * @param n number of elements
 * @return the allocated array of integers
 */
int* allocateArray(unsigned const int &n)
{
    int* arr = new int[n];
    return arr;
}

/**
 * @brief deleteArray deletes an array dynamically assignated before
 * @param arr the pointer to the array
 */
void deleteArray(int* arr)
{
    if(arr != NULL)
        delete [] arr;
}

/**
 * @brief displayArray is a helper function that allows
 * a pointer to an array to be displayed.
 * @param arr is the pointer to the first element of the array
 * @param N is the number of elements in the array
 */
void displayArray(int *arr, const short &N)
{
    //Iterate through the array and display in stdout
    for(int i=0; i<N; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

/**
 * @brief arraysExample Shows the use of the statically and dynamically
 * allocated arrays
 */
void arraysExample()
{
    //Static array creation
    int statarr[NSIZE];

    //Dyanmic array declaration and allocation [Welcome to life!]
    int *dynarr;
    dynarr = allocateArray(NSIZE);

    //Initialize the arrays with the corresponding index
    for(int i=0; i<NSIZE; i++)
    {
        statarr[i] = i;
        dynarr[i] = i;
    }

    //Display the contents of the array
    cout<<"Contents of static array: "<<endl;
    displayArray(statarr, NSIZE);

    cout<<"Contents of dynamic array: "<<endl;
    displayArray(dynarr, NSIZE);

    //Release the memory [I dont need you anymore!]
    deleteArray(dynarr);
}



