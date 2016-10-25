#include <iostream>

int main()
{
    using namespace std;

    double celsius, fahrenheit;

    cout << "Please enter a celsius value: ";
    cin >> celsius;
    fahrenheit = celsius * 1.8 + 32;
    cout << celsius << " degrees Celsius is "
        << fahrenheit << " degrees Fahrenheit." << endl;

    return 0;
}
