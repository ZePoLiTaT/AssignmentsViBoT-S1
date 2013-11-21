#ifndef CTABLE_H
#define CTABLE_H

#define MAXNUM 20
#define DEFVAL 5

class CTable
{
    int *elems;
    unsigned int n;

    int partition(int, int);
public:
    //CTable();
    CTable(unsigned const int & = DEFVAL);

    void initialize();
    void display();
    void insert(unsigned const int &, int &);
    int read(unsigned const int &);
    void swap(unsigned const int &, unsigned const int &);

    void bubbleSort();
    void quickSort(int, int);
};

#endif // CTABLE_H
