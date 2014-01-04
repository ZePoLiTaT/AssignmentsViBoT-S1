#include <iostream>
#include "ctable.h"
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(NULL));

    unsigned int n = 10;
    CTable table(n);

    cout<<"********* Bubble Sort ***********"<<endl;
    table.display();
    table.bubbleSort();
    cout<<table;

    cout<<"********* Quick Sort ***********"<<endl;
    table.initialize();
    cout<<table;
    table.quickSort(0, n);
    cout<<table;

    cout<<"********* Selection Sort ***********"<<endl;
    table.initialize();
    cout<<table;
    table.selectionSort();
    cout<<table;

    cout<<"********* Insertion Sort ***********"<<endl;
    table.initialize();
    cout<<table;
    table.insertSort();
    cout<<table;

    return 0;
}

