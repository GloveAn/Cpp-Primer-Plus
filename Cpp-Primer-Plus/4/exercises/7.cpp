#include <iostream>

using namespace std;

const int NAME_LENGTH = 80;

struct pizza
{
    char name[NAME_LENGTH];
    double diameter;
    double weight;
};

int main()
{
    pizza pzz;

    cout << "Enter company name: ";
    cin.getline(pzz.name, NAME_LENGTH);
    cout << "Enter diameter: ";
    cin >> pzz.diameter;
    cout << "Enter weight: ";
    cin >> pzz.weight;

    cout << "Company name: " << pzz.name << ", "
        << "diameter: " << pzz.diameter << ", "
        << "weight: " << pzz.weight << "."
        << endl;

    return 0;
}
