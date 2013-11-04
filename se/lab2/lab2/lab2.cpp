#include "lab2.h"
#include <iostream>
#include <cmath>

using namespace std;

////////////////////////// GENERAL FUNCTIONS //////////////////////////////////

/**
 * @brief exampleInputOutput illustrates the use of the
 * standard input and output commands and some tricks
 * like cin.ignore()
 */
void exampleInputOutput()
{
    string line;

    cout<<"Introducing the one and unque COUT function!"<<endl;
    cout<<"Please write a word and I'll read it with CIN: "<<endl;
    cin>>line;

    //This is needed because we want to flush non used characters
    cin.ignore(INT_MAX, '\n');
    //This clears the error flag
    cin.clear();

    cout<<"Ok, You entered "<<line<<" with CIN and I've displayed it using COUT. Magic!"<<endl;

    cout<<"Now, I want to test getline(). Please enter something else: "<<endl;
    getline(cin, line);
    cout<<"You entered: "<<line<<endl;
}

/**
 * @brief swap_1 two values that are passed by value
 * This works fine inside the function, but the changes
 * do not persist after
 * @param a first value
 * @param b second value to swap
 */
void swap_1(int a,int b)
{
    int tmp;

    tmp = a;
    a = b;
    b = tmp;
    cout<<" --> Internal result swap_1 function: "<<a<<", "<<b<<endl;
}

/**
 * @brief swap_2 two values that are passed by reference
 * @param a first value
 * @param b second value to swap
 */
void swap_2(int &a,int &b)
{
    int tmp;

    tmp = a;
    a = b;
    b = tmp;

    cout<<" --> Internal result swap_2 function: "<<a<<", "<<b<<endl;
}

/**
 * @brief swap_3 two values that are pointers
 * @param a pointer to the first value
 * @param b pointer to the second value to swap
 */
void swap_3(int* const a, int* const b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;

    cout<<" --> Internal result swap_3 function: "<<a<<", "<<b<<endl;
}

/**
 * @brief cartesianToPolar returns the norm and angle from the elements
 * z = a + ib of a complex number
 * @param a real part
 * @param b imaginary part
 * @param norm returned value with the norm
 * @param angle returned value with the angle
 */
void cartesianToPolar(const double &a, const double &b, double &norm, double &angle)
{
    norm = sqrt(a*a + b*b);
    angle = atan2(b,a);
}

/**
 * @brief isMultipleOf evaluates if a number p is multiple of another (q).
 * If no q is provided it returns if p is even.
 * @param p number we want to know if it is multiple of another
 * @param q number we want to evaluate p to see if it is multiple of it
 * @return true if it is multiple, false otherwise
 */
bool isMultipleOf(const int &p, const int q)
{
    return p%q==0;
}

/**
 * @brief isPrime Determines if a number is prime or not recursively
 * @param p number
 * @param n iterator
 * @return
 */
bool isPrime(const unsigned int &p, const unsigned int &n)
{
    if(n<=1)            //Base case: number is always divisible by 1
        return true;
    else if (p%n==0)    //Number divisible by another different than 1 and itself (NOT PRIME)
        return false;
    else
        return isPrime(p, n-1);
}

/**
 * @brief isPrime Determines if a number is prime or not recursively
 * @param p number
 * @return true if the number is prime, false otherwise
 */
bool isPrime(const unsigned int &p)
{
    //We only need to check if the number is divisible by others
    //lower than the square root
    int psqr = sqrt(p);

    return isPrime(p, psqr);
}
