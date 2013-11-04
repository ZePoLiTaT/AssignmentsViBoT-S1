#include <iostream>
#include <time.h>
#include "ptrarithmetic.h"
#include "lab3.h"

using namespace std;

/**
 * @brief show_menu Shows the menu of the options
 */
void showMenu()
{
    cout<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Please select an option:"<<endl;
    cout<<"1 Array basic operations"<<endl;
    cout<<"2 Array span"<<endl;
    cout<<"3 Some geometry"<<endl;
    cout<<"4 Matrix operations"<<endl;
    cout<<"0 Exit"<<endl;
    cout<<"=================================="<<endl;
}

/**
 * @brief ArrayPlaygroundCaller allocates, initializes
 * displays and deletes two dynamic arrays. In the middle
 * it performs two basic operations also: reverse and swap.
 */
void arrayPlaygroundCaller()
{
    int n = 3;
    int *arr1, *arr2;

    arr1 = AllocateArray(n);
    InitializeArray(arr1, n);
    cout<<"Array 1"<<endl;
    DisplayArray(arr1,n);

    ReverseArray(arr1, n);

    cout<<"Array 1 Reversed"<<endl;
    DisplayArray(arr1,n);

    arr2 = AllocateArray(n);
    InitializeArray(arr2, n);
    cout<<"Array 2"<<endl;
    DisplayArray(arr2,n);

    SwapArrays(arr1, arr2, n);

    cout<<"Swapped Array 1"<<endl;
    DisplayArray(arr1, n);
    cout<<"Swapped Array 2"<<endl;
    DisplayArray(arr2, n);

    DeleteArray(arr2);
    DeleteArray(arr1);
}

/**
 * @brief spanPtrCaller allocates, initializes
 * displays and deletes two dynamic arrays. In the middle
 * it performs a span in each of the arrays in a safe and
 * unsafe way.
 */
void spanPtrCaller()
{
    int n = 3;
    int *arr1, *arr2;

    arr1 = AllocateArray(n);
    arr2 = AllocateArray(n);

    InitializeArray(arr1, n);
    InitializeArray(arr2, n);

    cout<<"Array 1"<<endl;
    DisplayArray(arr1,n);

    cout<<"Array 2"<<endl;
    DisplayArray(arr2,n);

    cout<<"Address Array 1 [Before Span1] = "<<arr1<<endl;
    SpanArray1(arr1,n);
    cout<<"Address Array 1 [After Span1] = "<<arr1<<endl;

    cout<<"Address Array 2 [Before Span2] = "<<arr2<<endl;
    SpanArray2(arr2,n);
    cout<<"Address Array 2 [After Span2] = "<<arr2<<endl;

    //DeleteArray(arr2);
    DeleteArray(arr1);
}

/**
 * @brief someGeometryCaller allocate and Initialize
 * two vectors. Then perform inner product calculus and
 * obtain a new vector by using the cross product.
 */
void someGeometryCaller()
{
    int n = 3;
    int *arr1, *arr2, *arr3;
    long long inner, inner0_1, inner0_2;

    arr1 = AllocateArray(n);
    arr2 = AllocateArray(n);

    InitializeArray(arr1, n);
    InitializeArray(arr2, n);

    cout<<"Array 1"<<endl;
    DisplayArray(arr1,n);

    cout<<"Array 2"<<endl;
    DisplayArray(arr2,n);


    inner = InnerProduct(arr1, arr2, n, n);
    cout<<"Inner product between Array 1 and Array 2 = "<<inner<<endl;


    arr3 = CrossProduct(arr1, arr2);
    cout<<"Cross product between Array 1 and Array 2: "<<endl;
    DisplayArray(arr3, n);


    cout<<"** BONUS: Checking the cross product ;)"<<endl;
    cout<<"   Since the cross product between two 3D-vectors gives us"<<endl<<
          "   an orthogonal vector to both of them, then the inner "<<endl<<
          "   product bewteen the result and any of them must be 0!!"<<endl<<endl;


    inner0_1 = InnerProduct(arr1, arr3, n, n);
    inner0_2 = InnerProduct(arr2, arr3, n, n);
    cout<<"   -> Inner product between Array 1 and Array 3 = "<<inner0_1<<endl;
    cout<<"   -> Inner product between Array 2 and Array 3 = "<<inner0_2<<endl<<endl;

    DeleteArray(arr1);
    DeleteArray(arr2);
    DeleteArray(arr3);
}

void matrixPlaygroundCaller()
{
    int n=3, m=2;
    int **mat1, **mat2, **mat3;
    mat1 = AllocateMatrix(n, m);
    mat2 = AllocateMatrix(m,n);

    cout<<"Matrix without initialization:"<<endl;
    DisplayMatrix(mat1, n, m);

    InitializeMatrix(mat1, n, m);
    cout<<"Matrix 1 after initialization:"<<endl;
    DisplayMatrix(mat1, n, m);

    InitializeMatrix(mat2, m, n);
    cout<<"Matrix 2 after initialization:"<<endl;
    DisplayMatrix(mat2, m, n);

    mat3 = MatrixMultiplication(mat1, mat2, n,m, m,n);
    cout<<"Matrix 1 times Matrix 2:"<<endl;
    DisplayMatrix(mat3, n, n);

    DeleteMatrix(mat1, n);
    DeleteMatrix(mat2, m);
    DeleteMatrix(mat3, m);
}

/**
 * @brief eval_option Controller that decides the action according to
 * the user selection.
 * @param opt
 */
void evalOption(const short &opt)
{
    switch (opt)
    {
        case 1:
            arrayPlaygroundCaller();
        break;
        case 2:
            spanPtrCaller();
            break;
        case 3:
            someGeometryCaller();
        break;
        case 4:
            matrixPlaygroundCaller();
        break;
    }
}

int main(void)
{
    srand(time(NULL));

    short int opt;
    do{
        showMenu();
        cin>>opt;
        evalOption(opt);
    }while(opt!=0);

    return 0;
}

