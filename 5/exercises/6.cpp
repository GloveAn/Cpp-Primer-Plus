#include <iostream>
#include <string>

using namespace std;

struct car
{
    string vendor;
    int year;
};

int main()
{
    car *cars;
    int n;

    cout << "How many cars do you wish to catalog? ";
    cin >> n;
    cin.get();

    cars = new car[n];

    for(int i = 0; i < n; i++)
    {
        cout << "Car #" << (i + 1) << endl;
        cout << "Please enter the make: ";
        getline(cin, cars[i].vendor);
        cout << "Please enter the year made: ";
        cin >> cars[i].year;
        cin.get();
    }

    cout << "Here is your collection:" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << cars[i].year << " " << cars[i].vendor << endl;
    }

    delete [] cars;
    return 0;
}
