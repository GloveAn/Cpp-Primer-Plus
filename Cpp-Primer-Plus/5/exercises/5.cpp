#include <iostream>

using namespace std;

int main()
{
    const char *year[] =
    {
        "First",
        "Second",
        "Third",
    };
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
    int selling[3][12];
    int sum = 0;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            cout << "Enter the sales volume of " << months[j]
                << " of the " << year[i] << " year : ";
            cin >> selling[i][j];
            sum += selling[i][j];
        }

    }
    cout << "Total sales volume is " << sum << endl;

    return 0;
}
