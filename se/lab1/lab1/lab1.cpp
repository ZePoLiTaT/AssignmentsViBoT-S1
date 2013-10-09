#include "lab1.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief mean returns the mean of two variables defined as (val1+val2)/2
 * @param val1 first variable
 * @param val2 second variable
 * @return the mean value
 */
double mean(const double &val1, const double &val2)
{
    return (val1 + val2)/2;
}

/**
 * @brief min returns the minimum value of two variables
 * @param val1 first variable
 * @param val2 second variable
 * @return the minimum value
 */
double min(const double &val1, const double &val2)
{
    return (val1<val2) ? val1 : val2;
}

/**
 * @brief max returns the maximum value between two  variables
 * @param val1 first variable
 * @param val2 second variable
 * @return the maximum value
 */
double max(const double &val1, const double &val2)
{
    return (val1>val2) ? val1 : val2;
}

/**
 * @brief factorial returns the factorial defined as: 1*2*3..*n
 * @param n value should be greater or equal than zero
  * @return the factorial of n
 */
double factorial(const unsigned short &n)
{
    long double result = 1;
    for(int i=2; i<=n; i++)
        result *= i;

    return result;
}

/**
 * @brief combinations find the number of k-combinations (each of size k) from a set S with n elements
 * @param n size of the elements set
 * @param k number of combinations
 * @return returns the number of combinations
 */
double combinations(const unsigned short &n, const unsigned short &k)
{
    double nfac = factorial(n);
    double nminuskfac = factorial(n-k);
    double kfac = factorial(k);

    return nfac/(nminuskfac*kfac);
}

/**
 * @brief The number of combinations with repetitions
 * @param n number of elements in the set
 * @param k number of elements in the subgroup
 * @return number of combinations with repetitions
 */
double combinations_rep(const unsigned short &n, const unsigned short &k)
{
    return combinations(n+k-1, k);
}

/**
 * @brief permutations calculate the number of permutations of n elements in subroups
 * of size k
 * @param n elements in the complete set
 * @param k number of elements in the subroup
 * @return the number of permutations
 */
double permutations(const unsigned short &n, const unsigned short &k)
{
    double nfac = factorial(n);
    double nminuskfac = factorial(n-k);

    return nfac/nminuskfac;
}

/**
 * @brief fibonacci_print Prints the fibonacci terms until Fn
 * @param n Last fibonacci term to print
 */
void fibonacci_print(const unsigned short &n)
{
    unsigned long long fn0 = 0;
    cout<<fn0<<" ";

    if(n == 0)
        return;

    unsigned long long fn1 = 1;
    unsigned long long tmp;
    cout<<fn1<<" ";

    for(int i=2; i<=n; i++)
    {
        tmp = fn1;
        fn1 = fn0 + fn1;
        fn0 = tmp;

        cout<<fn1<<" ";
    }
}

/**
 * @brief fibonacci Caculates the Fibonacci series recursively
 * @param n Term to calculate
 * @return
 */
unsigned long long fibonacci(const unsigned short &n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

/**
 * @brief golden_ratio calculates the golden ratio sistematically
 * until its error is less than an epsilon
 * @param eps is the epsilon of the max allowed error
 */
void golden_ratio(const float &eps)
{
    unsigned int i=1;
    float err = 1e10, r;
    unsigned long long fnp1=1, fn=1, tmp;

    do
    {
        r = (float)fnp1/fn;
        err = abs(r - PHI);
        printf("Ratio Fn(%llu)/Fn(%llu) = %G. Err{%G} vs eps{%E}\n", fnp1, fn, r, err,eps);

        tmp = fnp1;
        fnp1 = fn + fnp1;
        fn = tmp;

        i++;
    }while(err>eps);
}


/**
 * @brief pascalTriangle Prints the first n lines of the Pascal triangle
 * @param n number of lines to print
 */
void pascalTriangle(const unsigned short &n)
{
    for(unsigned short i=0; i<=n; i++)
    {
        for(unsigned short k=0; k<=i; k++)
        {
            cout<<combinations(i,k)<<" ";
        }
        cout<<endl;
    }
}

/**
 * @brief stringSample Playground of the std:string class
 */
void stringSample()
{
    string s1("Hello ");
    string s2 = "World";
    string s3;
    string s4(20, '-');
    string line;

    s3 = s1 + s2;
    s4.append(">>>>>>");
    s4.insert(0,"<<<<<<");

    cout<<s1<<endl<<s2<<endl<<s3<<endl<<s4<<endl;
    cout<<"The length of s4 is "<<s4.length()<<endl<<endl;
    cout<<"Last but not least, the getline function."<<endl;
    cout<<"Please enter your name s'il tu plaît: "<<endl;
    getline(cin, line);
    cout<<"Bonjour <"<<line<<">!!"<<endl;
}
