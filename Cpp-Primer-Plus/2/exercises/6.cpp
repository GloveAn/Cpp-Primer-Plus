#include <iostream>

using namespace std;

void light_year2astronomical_unit(int hour, int minute)
{
    cout << "Time: " << hour << ":" << minute << endl;
}

int main()
{
    int hour, minute;

    cout << "Enter the number of hours: ";
    cin >> hour;
    cout << "Enter the number of minutes: ";
    cin >> minute;

    light_year2astronomical_unit(hour, minute);

    return 0;
}
