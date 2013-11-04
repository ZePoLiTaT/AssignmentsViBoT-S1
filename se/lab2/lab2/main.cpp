#include <iostream>
#include "lab2.h"
#include "monoarray.h"
#include "static2darray.h"
#include "dynamic2darray.h"

using namespace std;

/**
 * @brief show_menu displays the menu with the options of the application
 */
void showMenu()
{
    cout<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Please select an option: "<<endl;
    cout<<"1. Example input output"<<endl;
    cout<<"2. Swap"<<endl;
    cout<<"3. Cartesian to Polar"<<endl;
    cout<<"4. Is multiple of"<<endl;
    cout<<"5. Prime"<<endl;
    cout<<"6. Monodimensional array"<<endl;
    cout<<"7. Multidimensional array"<<endl;
    cout<<"8. Multidimensional arrays as function parameters"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"=================================="<<endl;
}

/**
 * @brief swapCaller controlls the call to the swap functions
 * by providing the necesary input from the user to the function.
 */
void swapCaller()
{
    int a, b, ina, inb;
    int *pa, *pb;

    cout<<"Please enter two integers to swap: ";
    cin>>ina>>inb;

    a = ina, b = inb;
    swap_1(a,b);
    cout<<"Result from main swap_1 function: "<<a<<", "<<b<<endl;

    a = ina, b = inb;
    swap_2(a,b);
    cout<<"Result from main swap_2 function: "<<a<<", "<<b<<endl;

    a = ina, b = inb;
    pa = &a;
    pb = &b;
    swap_2(a,b);
    cout<<"Result from main swap_3 function: "<<a<<", "<<b<<endl;
}

/**
 * @brief cartesianCaller controlls the call to the cartesianToPolar function
 * by providing the necesary input from the user to the function.
 */
void cartesianCaller()
{
    double x, y, norm, angle;

    cout<<"Please enter the terms (a,b) of the complex number z = a + ib: "<<endl;

    cin>>x>>y;
    cin.clear();
    cin.ignore(INT_MAX, '\n');

    cartesianToPolar(x, y, norm, angle);
    cout<<"The norm of "<<x<<" and "<<y<<" is: "<<norm<<" and the angle is: "<<angle<<endl;
}

/**
 * @brief multipleCaller controlls the call to the isMultipleOf function
 * by providing the necesary input from the user to the function.
 */
void multipleCaller()
{
    int p,q;
    cout<<"Please enter a value for p"<<endl;

    cin>>p;
    cin.clear();
    cin.ignore(INT_MAX, '\n');

    if(isMultipleOf(p))
        cout<<p<<" is multiple of the default value 2"<<endl;
    else
        cout<<p<<" is NOT multiple of the default value 2"<<endl;

    cout<<"Now please enter q"<<endl;

    cin>>q;
    cin.clear();
    cin.ignore(INT_MAX, '\n');

    if(isMultipleOf(p, q))
        cout<<p<<" is multiple of "<<q<<endl;
    else
        cout<<p<<" is NOT multiple of "<<q<<endl;
}

/**
 * @brief pascalTriangleCaller constrolls the call to Pascal Triangle
 * calculated by 2 different ways
 */
void pascalTriangleCaller()
{
    unsigned short n;

    cout<<"-- Pascal Triangle Static MultiDim Arrays"<<endl<<endl;
    pascalTriangleStatic();
    cout<<endl<<"-- Pascal Triangle Dynamic MultiDim Arrays"<<endl;
    cout<<"Please enter the number of termns of the triangle to display: "<<endl;

    cin>>n;
    cin.clear();
    cin.ignore(INT_MAX, '\n');

    pascalTriangleDynamic(n);
}

/**
 * @brief isPrimeCaller controlls the call to the isPrime function
 * by separating the user interface with the logic
 */
void isPrimeCaller()
{
    unsigned int p;
    cout<<"Privet!!"<<endl;
    cout<<"Which number do you want to check? "<<endl;
    cin>>p;
    cin.clear();
    cin.ignore(INT_MAX, '\n');

    if(isPrime(p))
        cout<<"Congratz, "<<p<<" is Prime!"<<endl;
    else
        cout<<"Bad luck :| Your number is NOT Prime"<<endl;
}

/**
 * @brief matMultCaller controlls the call to the matMult function
 */
void matMultCaller()
{
    int A[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[][3] = {{1, 2, -1}, {1, 2, -1}, {1, 2, -1}};
    int C[3][3] = {{}};

    multMatrix(A,B,C);

    displayMatrix(A);
    cout<<"TIMES "<<endl;
    displayMatrix(B);
    cout<<"EQUALS "<<endl;
    displayMatrix(C);
}

/**
 * @brief evalOption calls the corresponding function according to
 * the option selected by the user in the variable opt
 * @param opt
 */
void evalOption(const short& opt)
{
    switch(opt)
    {
        case 1:
            exampleInputOutput();
        break;
        case 2:
            swapCaller();
        break;
        case 3:
            cartesianCaller();
        break;
        case 4:
            multipleCaller();
        break;
        case 5:
            isPrimeCaller();
        break;
        case 6:
            arraysExample();
        break;
        case 7:
            pascalTriangleCaller();
        break;
        case 8:
            matMultCaller();
        break;
    }
}


int main()
{

    short int opt;
    do{
        showMenu();
        cin>>opt;
        evalOption(opt);
    }while(opt!=0);

    return 0;
}

