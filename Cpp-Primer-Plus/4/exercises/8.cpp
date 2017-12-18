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
    pizza *pzz = new pizza;

    cout << "Enter diameter: ";
    cin >> pzz->diameter;
    cin.get();
    cout << "Enter company name: ";
    cin.getline(pzz->name, NAME_LENGTH);
    cout << "Enter weight: ";
    cin >> pzz->weight;

    cout << "Company name: " << pzz->name << ", "
        << "diameter: " << pzz->diameter << ", "
        << "weight: " << pzz->weight << "."
        << endl;

    delete pzz;

    return 0;
}
