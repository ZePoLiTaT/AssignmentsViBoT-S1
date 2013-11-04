/***************************************************************************
 *
 *   Creation Date: 11/2/2013
 *   Author:        ZePoLiTaT
 *   File:          ptrarithmetic.cpp
 *   Class:
 *
 *   Modifications:
 *      11/2/2013 - Creation
 *
 ***************************************************************************/

#include <stdlib.h>
#include <iostream>
#include "lab3.h"
#include "ptrarithmetic.h"

#define MAX_NUM 99;

using namespace std;

/**
 * @brief AllocateArray reserves memory for n integers
 * @param n number of elements
 * @return the allocated array of integers
 */
int* AllocateArrayPA(unsigned const int &n)
{
    int* arr = new int[n];
    return arr;
}

/**
 * @brief DeleteArray deletes an array dynamically assignated before
 * @param arr the pointer to the array
 */
void DeleteArrayPA(int* arr)
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
void InitializeArrayPA(int* const arr, unsigned const int &n)
{
    for(unsigned int i=0; i<n; i++)
    {
        *(arr+i) = rand()%MAX_NUM;
    }
}

/**
 * @brief DisplayArray is a helper function that allows
 * a pointer to an array to be displayed.
 * @param arr is the pointer to the first element of the array
 * @param N is the number of elements in the array
 */
void DisplayArrayPA(const int* const arr, unsigned const int &n)
{
    for(unsigned int i=0; i<n; i++)
    {
        cout<<*(arr+i)<<endl;
    }
}

/**
 * @brief ReverseArray reverses the order of the elements of the array
 * @param arr pointer to the array
 * @param n number of elements of the array
 */
void ReverseArrayPA(int* const arr, unsigned const int &n)
{
    int tmp;
    for(unsigned int i=0; i<n/2; i++)
    {
        tmp = *(arr+i);
        *(arr+i) = *(arr+n-1-i);
        *(arr+n-1-i) = tmp;
    }
}

/**
 * @brief SwapArrays swaps the elements of two given arrays.
 * The size of both arrays must be the same and equal to n
 * @param arr1 pointer to the first array
 * @param arr2 pointer to the second array
 * @param n number of elements in both arrays
 */
void SwapArraysPA(int* arr1, int* arr2, unsigned const int &n)
{
    int tmp;
    for(unsigned int i = 0; i<n; i++)
    {
        tmp = *(arr1+i);
        *(arr1+i) = *(arr2+i);
        *(arr2+i) = tmp;
    }
}


int **AllocateMatrixPA(const unsigned int &n, const unsigned int &m)
{
    int **mat = new int*[n];

    for(unsigned int i=0; i<n; i++)
        *(mat+i) = new int[m];

    return mat;
}

void InitializeMatrixPA(int ** const mat, const unsigned int &n, const unsigned int &m)
{
    for(unsigned int i=0; i<n; i++)
    {
        for(unsigned int j=0; j<m; j++)
        {
            *(*(mat+i)+j) = rand()%MAX_NUM;
        }
    }
}

void InitializeMatrixOnesPA(int ** const mat, const unsigned int &n, const unsigned int &m)
{
    for(unsigned int i=0; i<n; i++)
    {
        for(unsigned int j=0; j<m; j++)
        {
            *(*(mat+i)+j) = 0;
        }
    }
}

void DisplayMatrixPA(int const* const* const mat, const unsigned int &n, const unsigned int &m)
{
    cout<<"Matrix "<<mat<<" Contents: "<<endl;
    for(unsigned int i=0; i<n; i++)
    {
        for(unsigned int j=0; j<m; j++)
        {
            cout<<*(*(mat+i)+j)<<" ";
        }
        cout<<endl;
    }
}

void DeleteMatrixPA(int ** mat, const unsigned int &n)
{
    for(unsigned int i=0; i<n; i++)
    {
        delete [] *(mat+i);
    }
}

int **MatrixMultiplicationPA(int const* const* const mat1, int const* const* const mat2,
                           const unsigned int &n1, const unsigned int &m1,
                           const unsigned int &n2, const unsigned int &m2)
{
    if(m1!=n2)
    {
        cerr<<"Matrix dimmensions must match +"<<n1<<","<<m1<<") - +"<<n2<<","<<m2<<")"<<endl;
        return NULL;
    }

    int **mmult;
    mmult = AllocateMatrixPA(n1, m2);
    InitializeMatrixOnesPA(mmult, n1, m2);

    for(unsigned int i=0; i<n1; i++)
    {
        for(unsigned int j=0; j<m2; j++)
        {
            for(unsigned int k=0; k<m1; k++)
            {
                *(*(mmult+i)+j) += *(*(mat1+i)+k) * *(*(mat2+k)+j);
            }
        }
    }

    return mmult;
}

long long InnerProductPA(const int * const v1, const int * const v2, const unsigned int &n1, const unsigned int &n2)
{
    if(n1 != n2)
    {
        cerr<<"Matrix dimmensions must agree"<<endl;
        return 0;
    }

    long long res = 0;
    for(unsigned int i=0; i<n1; i++)
    {
        res += *(v1+i) * *(v2+i);
    }

    return res;
}

int *CrossProductPA(const int * const v1, const int * const v2)
{
    int *vout;
    vout = AllocateArray(3);

    *(vout+0) = *(v1+1) * *(v2+2) - *(v1+2) * *(v2+1);
    *(vout+1) = *(v1+2) * *(v2+0) - *(v1+0) * *(v2+2);
    *(vout+2) = *(v1+0) * *(v2+1) - *(v1+1) * *(v2+0);

    return vout;
}

