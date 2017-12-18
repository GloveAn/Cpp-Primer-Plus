#include <iostream>

int main()
{
    using namespace std;

    double l, m;

    cout << "Enter L: ";
    cin >> l;
    cout << "Enter kilometers: ";
    cin >> m;

    cout << "Result is " << l * 100 / m << "L/100km" << endl;

    return 0;
}
