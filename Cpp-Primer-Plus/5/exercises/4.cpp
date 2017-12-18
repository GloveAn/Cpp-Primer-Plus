#include <iostream>

using namespace std;

int main()
{
    const char *months[] =
    {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    int selling[13] = {0};

    for(int i = 0; i < 12; i++)
    {
        cout << "Enter the sales volume of " << months[i] << " : ";
        cin >> selling[i];
        selling[12] += selling[i];
    }
    cout << "Sales volume of the year is " << selling[12] << endl;

    return 0;
}
