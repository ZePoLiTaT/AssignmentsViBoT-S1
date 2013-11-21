#include <iostream>
#include "ctable.h"

using namespace std;

int main()
{
    srand(time(NULL));

    unsigned int n = 10;
    CTable table(n);

    cout<<"********* Bubble Sort ***********"<<endl;
    table.display();
    table.bubbleSort();
    table.display();

    cout<<"********* Quick Sort ***********"<<endl;
    table.initialize();
    table.display();
    table.quickSort(0, n);
    table.display();

    return 0;
}

