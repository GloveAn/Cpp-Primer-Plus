#include <iostream>

int main()
{
    using namespace std;
    int chest = 42;
    int waist = 42;
    int inseam = 42;

    cout << "Monisieur cuts a striking figure!\n";
    cout << "chest = " << chest << " (decimal)" << "\n";
    cout << hex;
    cout << "waist = " << waist << " hexadecimal" << "\n";
    cout << oct;
    cout << "inseam = " << inseam << " (octal)" << "\n";
    return 0;
}
