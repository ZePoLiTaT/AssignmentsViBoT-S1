/***************************************************************************
 *
 *   Creation Date: 11/2/2013
 *   Author:        ZePoLiTaT
 *   File:          ptrarithmetic.h
 *   Class:
 *
 *   Modifications:
 *      11/2/2013 - Creation
 *
 ***************************************************************************/

#ifndef PTRARITHMETIC_H
#define PTRARITHMETIC_H

int **AllocateMatrixPA(const unsigned int &, const unsigned int &);
void InitializeMatrixPA(int ** const, const unsigned int &, const unsigned int &);
void DisplayMatrixPA(int const* const* const, const unsigned int &, const unsigned int &);
void DeleteMatrixPA(int **, const unsigned int &);
int **MatrixMultiplicationPA(int const* const* const, int const* const* const,
                           const unsigned int &, const unsigned int &,
                           const unsigned int &, const unsigned int &);

long long InnerProductPA(const int * const, const int * const,
                       const unsigned int &, const unsigned int &);

int *CrossProductPA(const int * const , const int * const );

#endif // PTRARITHMETIC_H
