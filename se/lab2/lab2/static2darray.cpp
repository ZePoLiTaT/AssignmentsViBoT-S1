/***************************************************************************
 *
 *   Creation Date: 10/24/2013
 *   Author:        ZePoLiTaT
 *   File:          static2darray.cpp
 *
 *   Modifications:
 *      10/24/2013 - Creation
 *
 ***************************************************************************/
#include <iostream>
#include <cmath>
#include "static2darray.h"

using namespace std;

////////////////////////// BIDIMENTIONAL ARRAYS //////////////////////////////////
/**
 * @brief initialize the matrix mat with NSIZE columns with
 * ones in the first column and zeros in all the other elements
 * @param mat is the matrix to initialize
 */
void initialize(int mat[][NSIZE])
{
    //Initialize the matrix
    for(int i=0; i<NSIZE; i++)
    {
        for(int j=0; j<NSIZE; j++)
        {
            //The first column is all ones
            if(j==0)
                mat[i][j] = 1;
            //The others are initialized to zero
            else
                mat[i][j] = 0;
        }
    }
}

/**
 * @brief calcPascalStatic Calculate the each position as the sum of the previous 2 elements
 * @param mat is the matrix to initialize
 */
void calcPascal(int mat[][NSIZE])
{
    //Calculate the each position as the sum of the previous 2 elements
    //from the row before
    for(int i=1; i<NSIZE; i++)
    {
        for(int j=1; j<NSIZE; j++)
        {
            mat[i][j] = mat[i-1][j] + mat[i-1][j-1];
        }
    }
}

/**
 * @brief displayPascalStatic Displays the values of the given matrix of NSIZE columns
 * @param mat is the matrix to initialize
 */
void displayPascal(int mat[][NSIZE])
{
    //Display the values calculated!
    for(int i=0; i<NSIZE; i++)
    {
        for(int j=0; j<NSIZE; j++)
        {
            printf("%3d ",mat[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief pascalTriangle1 calculates the elements of the Pascal Triangle
 * obtaining each value from the previous calculated values of the row before.
 */
void pascalTriangleStatic()
{
    int pascal[NSIZE][NSIZE];

    initialize(pascal);
    calcPascal(pascal);
    displayPascal(pascal);
}

/**
 * @brief multMatrix multiplies a 3x3 static matrix C=AxB
 * @param A Matrix 1
 * @param B Matrix 2
 * @param C Result matrix
 */
void multMatrix(int A[][SQRMAT], int B[][SQRMAT], int C[][SQRMAT])
{
    for(unsigned short i=0; i<SQRMAT; i++)
    {
        for(unsigned short j=0; j<SQRMAT; j++)
        {
            for(unsigned short k=0; k<SQRMAT; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

/**
 * @brief displayMatrix Displays a 3x3 matrix
 * @param C matrix to display
 */
void displayMatrix(int C[][SQRMAT])
{
    for(unsigned short i=0; i<SQRMAT; i++)
    {
        for(unsigned short j=0; j<SQRMAT; j++)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
}
