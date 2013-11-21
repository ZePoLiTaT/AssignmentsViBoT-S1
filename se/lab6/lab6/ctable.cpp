#include "ctable.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>



using namespace std;
/*
CTable::CTable() : CTable(DEFVAL)
{

}*/

CTable::CTable(unsigned const int &ne)
{
    n = ne;
    elems = new int[n];
    initialize();
}

void CTable::initialize()
{
    for(unsigned int i=0; i<n; i++)
        elems[i] = rand()%MAXNUM;
}

void CTable::display()
{
    for(unsigned int i=0; i<n; i++)
        cout<<elems[i]<<" ";
    cout<<endl;
}

void CTable::insert(const unsigned int &idx, int &val)
{
    if(idx>=this->n)
        return;

    elems[idx] = val;
}

int CTable::read(const unsigned int &idx)
{
    if(idx>=this->n)
        return -1;

    return elems[idx];
}

void CTable::swap(const unsigned int &idx1, const unsigned int &idx2)
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

    cout<<x<<endl;

    for(int j = i+1; j<lims; j++)
    {
        cout<<"["<<i<<","<<j<<"]"<<endl;
        if(elems[j] < x)
        {
            cout<<"***["<<elems[i+1]<<","<<elems[j]<<"]"<<endl;
            swap(i+1, j);
            display();
            i++;
        }
    }

    cout<<(i+1)<<endl;
    return i;
}


void CTable::quickSort(int limi, int lims)
{
    cout<<"---------------------("<<limi<<","<<lims<<")"<<endl;

    if(limi<0 || lims>n || (lims-limi)<=1)
        return;

    int pivot = limi, newpivot;

    newpivot = partition(pivot, lims);

    cout<<"--> newp["<<newpivot<<"] = "<<elems[newpivot]<<endl;
    cout<<".."<<limi<<","<<(newpivot)<<endl;
    cout<<".."<<(newpivot+1)<<","<<lims<<endl;

    swap(pivot, newpivot);
    display();

    quickSort(limi, newpivot);
    quickSort(newpivot+1, lims);
}

