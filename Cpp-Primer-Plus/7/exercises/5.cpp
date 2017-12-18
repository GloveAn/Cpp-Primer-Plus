#include <iostream>

using namespace std;

long factor(long n)
{
    if(n)
        return factor(n - 1) * n;
    else
        return 1;
}

int main()
{
    long n;

    cout << "Enter a small number: ";
    while(cin >> n)
    {
        cout << n << "! = " << factor(n) << endl;
        cout << "Enter a small number: ";
    }

    return 0;
}
