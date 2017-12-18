#include <iostream>

int main()
{
    using namespace std;

    const int MINUTES2SECONDS = 60;
    const int HOURS2MINUTES = 60;
    const int DAYS2HOURS = 24;

    long seconds;
    long minutes, hours, days;

    cout << "Enter the number of seconds: ";
    cin >> seconds;

    cout << seconds << " seconds = ";

    minutes = seconds / MINUTES2SECONDS;
    hours = minutes / HOURS2MINUTES;
    days = hours / DAYS2HOURS;
    seconds = seconds % MINUTES2SECONDS;
    minutes = minutes % HOURS2MINUTES;
    hours = hours % DAYS2HOURS;

    cout << days << " days, "
        << hours << " hours, "
        << minutes << " minutes, "
        << seconds << " seconds"
        << endl;

    return 0;
}
