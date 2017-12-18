#include <iostream>

using namespace std;

int main()
{
    double income;
    double tax;

    cout << "Enter income: ";
    while(cin >> income && income > 0.0099)
    {
        tax = 0;

        if(income > 0)
        {
            tax += income * 0;
            income -= 5000;
        }
        if(income > 0)
        {
            tax += income * 0.1;
            income -= 10000;
        }
        if(income > 0)
        {
            tax += income * 0.05;
            income -= 20000;
        }
        if(income > 0)
        {
            tax += income * 0.05;
            income -= income;
        }

        cout << "Tax is " << tax << " tvarp(s)." << endl;
        cout << "Enter income: ";
    }

    return 0;
}
