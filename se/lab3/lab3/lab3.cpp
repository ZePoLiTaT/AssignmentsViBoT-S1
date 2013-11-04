/***************************************************************************
 *
 *   Creation Date: 10/14/2013
 *   Author:        ZePoLiTaT
 *   File:          lab3.cpp
 *
 *   Modifications:
 *      10/14/2013 - Creation
 *
 ***************************************************************************/

#include <stdlib.h>
#include <iostream>
#include "lab3.h"

#define MAX_NUM 99;

using namespace std;

/**
 * @brief AllocateArray reserves memory for n integers
 * @param n number of elements
 * @return the allocated array of integers
 */
int* AllocateArray(unsigned const int &n)
{
    int* arr = new int[n];
    return arr;
}

/**
 * @brief DeleteArray deletes an array dynamically assignated before
 * @param arr the pointer to the array
 */
void DeleteArray(int* arr)
{
    if(arr != NULL)
        delete [] arr;
}

/**
 * @brief InitializeArray initializes the array with random values
 * between 0 and MAX_NUM
 * @param arr the pointer to the array
 * @param n number of elements of the array
 */
void InitializeArray(int* const arr, unsigned const int &n)
{
    for(unsigned int i=0; i<n; i++)
    {
        arr[i] = rand()%MAX_NUM;
    }
}

/**
 * @brief DisplayArray is a helper function that allows
 * a pointer to an array to be displayed.
 * @param arr is the pointer to the first element of the array
 * @param N is the number of elements in the array
 */
void DisplayArray(const int* const arr, unsigned const int &n)
{
    for(unsigned int i=0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }
}

/**
 * @brief ReverseArray reverses the order of the elements of the array
 * @param arr pointer to the array
 * @param n number of elements of the array
 */
void ReverseArray(int* const arr, unsigned const int &n)
{
    int tmp;
    for(unsigned int i=0; i<n/2; i++)
    {
        tmp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = tmp;
    }
}

/**
 * @brief SwapArraysDangerous swaps the values of two arrays by
 * changing the physical address of each one. This is dangerous!
 * @param arr1 pointer to the first array
 * @param arr2 pointer to the second array
 */
void SwapArraysDangerous(int* &arr1, int* &arr2)
{
    int* tmp;
    tmp = arr1;
    arr1 = arr2;
    arr2 = tmp;
}

/**
 * @brief SwapArrays swaps the elements of two given arrays.
 * The size of both arrays must be the same and equal to n
 * @param arr1 pointer to the first array
 * @param arr2 pointer to the second array
 * @param n number of elements in both arrays
 */
void SwapArrays(int* arr1, int* arr2, unsigned const int &n)
{
    int tmp;
    for(unsigned int i = 0; i<n; i++)
    {
        tmp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = tmp;
    }
}

/**
 * @brief SpanArray1 iterates through an dynamic array pointer
 * using pointer arithmetic. The variable is received by value.
 * @param p array pointer (by value)
 * @param n number of elements
 */
void SpanArray1(int *p, const int &n)
{
    for(int i=0; i<n; p++, i++) {}
}

/**
 * @brief SpanArray2 iterates through an dynamic array pointer
 * using pointer arithmetic. The variable is received by reference.
 * @param p array pointer (by reference)
 * @param n number of elements
 */
void SpanArray2(int* &p, const int &n)
{
    for(int i=0; i<n; p++, i++) {}
}

/**
 * @brief InnerProduct Calculates the n-D inner product between
 * the vectors v1 and v2 of size n1 and n2 respectively. \f$v_i \times v_j\f$
 * @param v1 Vector 1
 * @param v2 Vector 2
 * @param n1 Size vector 1
 * @param n2 Size vector 2
 * @return The inner product between v1 and v2
 */
long long InnerProduct(const int * const v1, const int * const v2, const unsigned int &n1, const unsigned int &n2)
{
    if(n1 != n2)
    {
        cerr<<"Matrix dimmensions must agree"<<endl;
        return 0;
    }

    long long res = 0;
    for(unsigned int i=0; i<n1; i++)
    {
        res += v1[i] * v2[i];
    }

    return res;
}

/**
 * @brief CrossProduct Obtains the cross product between the
 * 3D vector v1 and v2. The obtained vector is orthogonal
 * to both v1 and v2.
 * @param v1 Vector 1
 * @param v2 Vector 2
 * @return Cross product between vector v1 and v2
 */
int *CrossProduct(const int * const v1, const int * const v2)
{
    int *vout;
    vout = AllocateArray(3);

    vout[0] = v1[1] * v2[2] - v1[2] * v2[1];
    vout[1] = v1[2] * v2[0] - v1[0] * v2[2];
    vout[2] = v1[0] * v2[1] - v1[1] * v2[0];

    return vout;
}

/**
 * @brief AllocateMatrix reservers memory for a bidimentional
 * array of n rows and m columns
 * @param n number of rows
 * @param m number of columns
 * @return allocated matrix of nxm
 */
int **AllocateMatrix(const unsigned int &n, const unsigned int &m)
{
    int **mat = new int*[n];

    for(unsigned int i=0; i<n; i++)
        mat[i] = new int[m];

    return mat;
}

/**
 * @brief InitializeMatrix initializes the nxm matrix with random
 * values between 0 and MAX_NUM
 * @param mat matrix to initialize
 * @param n number of rows
 * @param m number of columns
 */
void InitializeMatrix(int ** const mat, const unsigned int &n, const unsigned int &m)
{
    for(unsigned int i=0; i<n; i++)
    {
        for(unsigned int j=0; j<m; j++)
        {
            mat[i][j] = rand()%MAX_NUM;
        }
    }
}

/**
 * @brief InitializeMatrixOnes initializes the nxm matrix with ones
 * @param mat matrix to initialize
 * @param n number of rows
 * @param m number of columns
 */
void InitializeMatrixOnes(int ** const mat, const unsigned int &n, const unsigned int &m)
{
    for(unsigned int i=0; i<n; i++)
    {
        for(unsigned int j=0; j<m; j++)
        {
            mat[i][j] = 0;
        }
    }
}

/**
 * @brief DisplayMatrix outputs to the standard output
 * the values of the matrix
 * @param mat matrix to display
 * @param n number of rows
 * @param m number of columns
 */
void DisplayMatrix(int const* const* const mat, const unsigned int &n, const unsigned int &m)
{
    cout<<" Matrix "<<mat<<" Contents: "<<endl<<"  ";
    for(unsigned int i=0; i<n; i++)
    {
        for(unsigned int j=0; j<m; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl<<"  ";
    }
}

/**
 * @brief DeleteMatrix releases the space of a matrix with
 * n rows
 * @param mat matrix to be deleted
 * @param n number of rows
 */
void DeleteMatrix(int ** mat, const unsigned int &n)
{
    for(unsigned int i=0; i<n; i++)
    {
        delete [] mat[i];
    }
}

/**
 * @brief MatrixMultiplication is a generic function to multiply
 * two dynamic bidimentional arrays mat1 of size n1xm1 and
 * mat2 of size n2xm2. Recall that m1 and n2 must be equal for
 * the operation to be valid.
 * @param mat1 Matrix 1
 * @param mat2 Matrix 2
 * @param n1 Number of rows of matrix 1
 * @param m1 Number of columns of matrix 1
 * @param n2 Number of rows of matrix 2
 * @param m2 Number of columns of matrix 2
 * @return mat1 x mat2
 */
int **MatrixMultiplication(int const* const* const mat1, int const* const* const mat2,
                           const unsigned int &n1, const unsigned int &m1,
                           const unsigned int &n2, const unsigned int &m2)
{
    if(m1!=n2)
    {
        cerr<<"Matrix dimmensions must match ["<<n1<<","<<m1<<"] - ["<<n2<<","<<m2<<"]"<<endl;
        return NULL;
    }

    int **mmult;
    mmult = AllocateMatrix(n1, m2);
    InitializeMatrixOnes(mmult, n1, m2);

    for(unsigned int i=0; i<n1; i++)
    {
        for(unsigned int j=0; j<m2; j++)
        {
            for(unsigned int k=0; k<m1; k++)
            {
                mmult[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return mmult;
}


