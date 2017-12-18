#include <iostream>

int main()
{
    using namespace std;

    double degree, minute, second;

    cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
    cout << "First, enter the degrees: ";
    cin >> degree;
    cout << "Next, enter the minutes of the arc: ";
    cin >> minute;
    cout << "Finally, enter the seconds of the arc: ";
    cin >> second;

    cout << degree << " degrees, "
        << minute << " minutes, "
        << second << " seconds = "
        << degree + (minute + second / 60) / 60 << " degrees" << endl;

    return 0;
}
