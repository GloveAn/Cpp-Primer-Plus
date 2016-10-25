#include <iostream>

using namespace std;

int main()
{
    const int FOOT2INCH = 12;

    int foot, inch;

    cout << "Enter yout height: ";
    cin >> inch;
    cout << endl;

    foot = inch / FOOT2INCH;
    inch = inch % FOOT2INCH;
    cout << "Your height is " << foot << " foot, " << inch << " inch." << endl;

    return 0;
}
