#include <iostream>

double light_year2astronomical_unit(double l)
{
    return l * 63240;
}

int main()
{
    using namespace std;

    double light_year, astronomical_unit;

    cout << "Enter the number of light years: ";
    cin >> light_year;
    astronomical_unit = light_year2astronomical_unit(light_year);
    cout << light_year << " light years = "
        << astronomical_unit << " astronomical units." << endl;

    return 0;
}
