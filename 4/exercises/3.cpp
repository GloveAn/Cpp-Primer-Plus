#include <iostream>
#include <cstring>

int main()
{
    using namespace std;

    char first_name[20], last_name[20];

    cout << "Enter your first name: ";
    cin.getline(first_name, 20);
    cout << "Enter your last name: ";
    cin.getline(last_name, 20);
    cout << "Here's the information in a single string: "
        << last_name << ", " << first_name << endl;

    return 0;
}
