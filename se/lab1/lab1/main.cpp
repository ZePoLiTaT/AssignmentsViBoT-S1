#include <iostream>
#include <string>
#include "lab1.h"

using namespace std;

void showMenu()
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

void evalOption(const short &opt)
{
    short n,k;
    double a,b;
    const float eps[] = {1e-6, 1e-9, 1e-12, 1e-15};

    switch (opt)
    {
        case 1:
            cout<<"Please enter 2 numbers"<<endl;
            cin>>a>>b;
            cout << "Mean " <<mean(a,b)<< endl;
            cout << "Min " <<min(a,b)<< endl;
            cout << "Max " <<max(a,b)<< endl;
        break;
        case 2:
            do
            {
                cout<<"Please enter an integer greater or equal than zero to calc factorial: ";
                cin>>n;
            }while(n<0);
            cout<<"The factorial of "<<n<<" is: "<<factorial(n)<<endl;
        break;
        case 3:
            do
            {
                cout<<"Please enter integers n,k greter than zero to calc combinations: ";
                cin>>n>>k;

            }while(n<0 || k<0);

            cout<<"The number of combination is: "<<combinations(n,k)<<endl;
        break;
        case 4:
            do
            {
                cout<<"Please enter integers n,k greter than zero to calc combiations with repetitions: ";
                cin>>n>>k;

            }while(n<0 || k<0);

            cout<<"The number of combination with repetitions is: "<<combinations_rep(n,k)<<endl;
        break;
        case 5:
            do
            {
                cout<<"Please enter integers n,k greter than zero to calc permutations: ";
                cin>>n>>k;

            }while(n<0 || k<0);

            cout<<"The number of permutations is: "<<permutations(n,k)<<endl;
        break;
        case 6:
            do
            {
                cout<<"Please enter an integer greater or equal than zero to see the Fibonacci serie: ";
                cin>>n;

            }while(n<0);

            cout<<"The Fibonacci list is: "<<endl;
            fibonacci_print(n);
        break;
        case 7:
            cout<<"Constant PHI: "<<PHI<<endl;
            for(int i=0; i<4; i++)
            {
                cout<<"--- Golden ratio with eps = "<<eps[i]<<endl;
                golden_ratio(eps[i]);
            }
        break;
        case 8:
            do
            {
                cout<<"Please enter the number of levels of the Pascal triangle: ";
                cin>>n;
            }while(n<0);
            pascalTriangle(n);
        break;
        case 9:
            stringSample();
        break;
    }
}

int main(int argc, char* argv[])
{
    unsigned short opt;

    cout << "argc = " << argc << endl; for (int i = 0; i<argc; i++)
    cout << "argv[i] = " << argv[i]<<endl;

    do{
        showMenu();
        cin>>opt;
        cin.ignore();
        evalOption(opt);
    }while(opt!=0);

    return 0;
}
