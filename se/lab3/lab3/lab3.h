/***************************************************************************
 *
 *   Creation Date: 10/14/2013
 *   Author:        ZePoLiTaT
 *   File:          lab3.h
 *   Class:
 *
 *   Modifications:
 *      10/14/2013 - Creation
 *
 ***************************************************************************/

#ifndef LAB3_H
#define LAB3_H

int* AllocateArray(unsigned const int &);
void DeleteArray(int*);
void InitializeArray(int* const, unsigned const int &);
void DisplayArray(const int* const, unsigned const int &);
void ReverseArray(int* const, unsigned const int &);
void SwapArraysDangerous(int* &, int* &);
void SwapArrays(int*, int*, unsigned const int &n);
void SpanArray1(int *, const int &);
void SpanArray2(int* &, const int &);

int **AllocateMatrix(const unsigned int &, const unsigned int &);
void InitializeMatrix(int ** const, const unsigned int &, const unsigned int &);
void DisplayMatrix(int const* const* const, const unsigned int &, const unsigned int &);
void DeleteMatrix(int **, const unsigned int &);
int **MatrixMultiplication(int const* const* const, int const* const* const,
                           const unsigned int &, const unsigned int &,
                           const unsigned int &, const unsigned int &);


long long InnerProduct(const int * const, const int * const,
                       const unsigned int &, const unsigned int &);

int *CrossProduct(const int * const , const int * const );

#endif // LAB3_H
