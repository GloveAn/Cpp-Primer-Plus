#include <iostream>
int furlong2yard(int);

int main()
{
    using namespace std;

    int furlong;
    cout << "Enter the length in furlong: ";
    cin >> furlong;

    int yard = furlong2yard(furlong);
    cout << furlong << " furlong = ";
    cout << yard << " yard." << endl;

    return 0;
}

int furlong2yard(int f)
{
    return 220 * f;
}
