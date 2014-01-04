#include "ctable.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

CTable::CTable(unsigned const int &ne)
{
    n = ne;
    elems = new int[n];
    initialize();
}

CTable::~CTable()
{
    if(elems!=NULL)
        delete [] elems;
}

void CTable::initialize()
{
    for(unsigned int i=0; i<n; i++)
        elems[i] = rand()%MAXNUM;
}

void CTable::display()
{
    cout<<*this;
}

void CTable::insert(const unsigned int old_idx, const unsigned int new_idx)
{
    if(old_idx < new_idx)
        return;

    int val = elems[old_idx];
    for(unsigned int i=old_idx; i>new_idx; i--)
        elems[i] = elems[i-1];
    elems[new_idx] = val;
}

int CTable::read(const unsigned int idx)
{
    if(idx>=this->n)
        return -1;

    return elems[idx];
}

void CTable::swap(const unsigned int idx1, const unsigned int idx2)
{
    if(idx1>=this->n || idx2>=this->n)
        return;

    int tmp = elems[idx1];
    elems[idx1] = elems[idx2];
    elems[idx2] = tmp;
}

void CTable::bubbleSort()
{
    for(unsigned int i=0; i<n; i++)
        for(unsigned int j=i+1; j<n; j++)
            if(elems[j]<elems[i])
                swap(i,j);
}

int CTable::partition(int limi, int lims)
{
    //the pivot is the first element
    int x = elems[limi];

    //the index i is the (non inclusive) limit of elements lower than x
    //at the begining there is no element lower than x so i = pivot+1
    int i = limi;

    for(int j = i+1; j<lims; j++)
    {
        if(elems[j] < x)
        {
            swap(i+1, j);
            i++;
        }
    }

    return i;
}


void CTable::quickSort(int limi, int lims)
{
    if(limi<0 || lims>n || (lims-limi)<=1)
        return;

    int pivot = limi, newpivot;

    newpivot = partition(pivot, lims);
    swap(pivot, newpivot);

    quickSort(limi, newpivot);
    quickSort(newpivot+1, lims);
}

void CTable::selectionSort()
{
     unsigned int smallest_idx;
     int smallest;

     for(unsigned int i=0; i<n; i++)
     {
         smallest_idx = i;
         smallest = elems[smallest_idx];

         for(unsigned int j=i+1; j<n; j++)
         {
             if(elems[j] < smallest)
             {
                smallest = elems[j];
                smallest_idx = j;
             }
         }

         swap(i, smallest_idx);
     }
}

void CTable::insertSort()
{
    //If it has zero or one element is already sorted
    if(n<=1) return;

    //The pointer to the unorganized part is given by the variable i [1..n]
    //For each i we need to find its right place in the organized part [0..i]
    //of the array to insert it there.
    for(unsigned int i=1; i<n; i++)
    {
        for(unsigned int j=0; j<i; j++)
        {
            if(elems[i] <= elems[j])
            {
                insert(i, j);
                break;
            }
        }
    }
}

ostream &operator <<(ostream &os, const CTable &ctable)
{
    for(unsigned int i=0; i<ctable.n; i++)
        os<<ctable.elems[i]<<" ";
    os<<endl;

    return os;
}

