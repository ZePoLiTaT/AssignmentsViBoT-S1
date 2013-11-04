/***************************************************************************
 *
 *   Creation Date: 10/24/2013
 *   Author:        ZePoLiTaT
 *   File:          dynamic2darray.cpp
 *   Class:
 *
 *   Modifications:
 *      10/24/2013 - Creation
 *
 ***************************************************************************/

#include <iostream>

/**
 * @brief allocateMatrix reserves space for an array of n positions were
 * each position points to an array of n integers, thus giving nxn (squared matrix)
 * of reserved space
 * @param n number of rows and columns
 * @return the double pointer to the allocated space
 */
int **allocateMatrix(const unsigned int &n)
{
    int **mat = new int*[n];

    for(unsigned int i=0; i<n; i++)
        *(mat+i) = new int[n];

    return mat;
}

/**
 * @brief deleteMatrix releases the allocated space for a matrix mat
 * of n columns
 * @param mat matrix to be released
 * @param n number of rows
 */
void deleteMatrix(int ** mat, const unsigned int &n)
{
    //For each row of the matrix delete the pointer array
    for(unsigned int i=0; i<n; i++)
    {
        delete [] *(mat+i);
    }
}

/**
 * @brief initializeMatrix initializes the matrix mat with n rows and n columns.
 * Assigns ones in the first column and zeros in all the other elements
 * @param mat is the matrix to initialize
 * @param n number of rows
 */
void initializeMatrix(int ** mat, const unsigned int &n)
{
    //Initialize the matrix
    for(unsigned int i=0; i<n; i++)
    {
        for(unsigned int j=0; j<n; j++)
        {
            //The first column is all ones
            if(j==0)
                *(*(mat + i) + j) = 1;
            //The others are initialized to zero
            else
                *(*(mat + i) + j) = 0;
        }
    }
}

/**
 * @brief calcPascalStatic Calculate the each position as the sum of the previous 2 elements
 * @param mat is the matrix to initialize
 */
void calcPascal(int ** mat, const unsigned int &n)
{
    //Calculate the each position as the sum of the previous 2 elements
    //from the row before
    for(unsigned int i=1; i<n; i++)
    {
        for(unsigned int j=1; j<n; j++)
        {
            *(*(mat + i) + j) = *(*(mat + i - 1) + j) + *(*(mat + i - 1) + j - 1);
        }
    }
}

/**
 * @brief displayPascalStatic Displays the values of the given matrix of NSIZE columns
 * @param mat is the matrix to initialize
 */
void displayPascal(int ** mat, const unsigned int &n)
{
    //Display the values calculated!
    for(unsigned int i=0; i<n; i++)
    {
        for(unsigned int j=0; j<n; j++)
        {
            printf("%3d ",*(*(mat + i) + j));
        }
        printf("\n");
    }
}

/**
 * @brief pascalTriangleDynamic calculates the elements of the Pascal Triangle
 * obtaining each value from the previous calculated values of the row before.
 */
void pascalTriangleDynamic(unsigned const int &n)
{
    int **mat;

    mat = allocateMatrix(n);
    initializeMatrix(mat, n);
    calcPascal(mat, n);
    displayPascal(mat, n);
    deleteMatrix(mat, n);
}
