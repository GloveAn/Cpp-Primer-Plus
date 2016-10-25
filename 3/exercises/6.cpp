#include <iostream>

int main()
{
    using namespace std;

    const double CONVERTER = 62.14 * 3.875;

    double value;

    cout << "Enter the number: ";
    cin >> value;
    cout << "Result is " << CONVERTER / value << endl;

    return 0;
}
