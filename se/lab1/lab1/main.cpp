#include <iostream>
#include <string>
#include "lab1.h"

using namespace std;

/**
 * @brief show_menu Shows the menu of the options
 */
void show_menu()
{
    cout<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Please select an option:"<<endl;
    cout<<"1 Mean, Min, Max."<<endl;
    cout<<"2 Factorial."<<endl;
    cout<<"3 Combinations"<<endl;
    cout<<"4 Combinations with repetitions"<<endl;
    cout<<"5 Permutations"<<endl;
    cout<<"6 Fibonacci"<<endl;
    cout<<"7 Fibonacci Golden Ratio"<<endl;
    cout<<"8 Pascal triangle"<<endl;
    cout<<"9 std::String sample"<<endl;
    cout<<"0 Exit"<<endl;
    cout<<"=================================="<<endl;
}

/**
 * @brief elementary_functions_UI User interface handler
 */
void elementary_functions_UI()
{
    double a,b;
    cout<<"Please enter 2 numbers"<<endl;
    cin>>a>>b;
    cout << "Mean " <<mean(a,b)<< endl;
    cout << "Min " <<min(a,b)<< endl;
    cout << "Max " <<max(a,b)<< endl;
}

/**
 * @brief factorialUI User interface handler
 */
void factorial_UI()
{
    short n;

    do
    {
        cout<<"Please enter an integer greater or equal than zero to calc factorial: ";
        cin>>n;
    }while(n<0);
    cout<<"The factorial of "<<n<<" is: "<<factorial(n)<<endl;
}

/**
 * @brief combinations_UI User interface handler
 */
void combinations_UI()
{
    short n,k;

    do
    {
        cout<<"Please enter integers n,k greter than zero to calc combinations: ";
        cin>>n>>k;

    }while(n<0 || k<0);

    cout<<"The number of combination is: "<<combinations(n,k)<<endl;
}

/**
 * @brief combinations_rep_UI User interface handler
 */
void combinations_rep_UI()
{
    short n,k;

    do
    {
        cout<<"Please enter integers n,k greter than zero to calc combiations with repetitions: ";
        cin>>n>>k;

    }while(n<0 || k<0);

    cout<<"The number of combination with repetitions is: "<<combinations_rep(n,k)<<endl;
}

/**
 * @brief permutations_UI User interface handler
 */
void permutations_UI()
{
    short n,k;

    do
    {
        cout<<"Please enter integers n,k greter than zero to calc permutations: ";
        cin>>n>>k;

    }while(n<0 || k<0);

    cout<<"The number of permutations is: "<<permutations(n,k)<<endl;
}

/**
 * @brief fibonacci_UI User interface handler
 */
void fibonacci_UI()
{
    short n;

    do
    {
        cout<<"Please enter an integer greater or equal than zero to see the Fibonacci serie: ";
        cin>>n;

    }while(n<0);

    cout<<"The Fibonacci list is: "<<endl;
    fibonacci_print(n);
}

/**
 * @brief golden_ratio_UI User interface handler
 */
void golden_ratio_UI()
{
    int count;
    const double eps[] = {1e-6, 1e-9, 1e-12, 1e-15};

    cout<<"Constant PHI: "<<PHI<<endl;
    for(int i=0; i<4; i++)
    {
        cout<<"--- Golden ratio with eps = "<<eps[i]<<endl;
        count = golden_ratio(eps[i]);
        cout<<"Number of iterations : "<<count<<endl;
    }

}

/**
 * @brief pascal_UI User interface handler
 */
void pascal_UI()
{
    short n;

    do
    {
        cout<<"Please enter the number of levels of the Pascal triangle: ";
        cin>>n;
    }while(n<0);
    pascalTriangle(n);
}

/**
 * @brief eval_option Controller that decides the action according to
 * the user selection.
 * @param opt
 */
void eval_option(const short &opt)
{
    switch (opt)
    {
        case 1:
            elementary_functions_UI();
        break;
        case 2:
            factorial_UI();
        break;
        case 3:
            combinations_UI();
        break;
        case 4:
            combinations_rep_UI();
        break;
        case 5:
            permutations_UI();
        break;
        case 6:
            fibonacci_UI();
        break;
        case 7:
            golden_ratio_UI();
        break;
        case 8:
            pascal_UI();
        break;
        case 9:
            stringSample();
        break;
    }
}

int main(int argc, char* argv[])
{
    unsigned short opt;

    cout << "argc = " << argc << endl;
    for (int i = 0; i<argc; i++)
        cout << "argv[i] = " << argv[i]<<endl;

    do{
        show_menu();
        cin>>opt;
        cin.ignore();
        eval_option(opt);
    }while(opt!=0);

    return 0;
}
