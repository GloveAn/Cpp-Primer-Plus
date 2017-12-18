#include <iostream>

int main()
{
    using namespace std;
    double x, y;

    cout << "Enter two numbers: ";
    while(cin >> x >> y && x != 0 & y != 0)
    {
        cout << "average = " << x * y * 2 / (x + y) << endl;
        cout << "Enter two numbers: ";
    }
    return 0;
}
