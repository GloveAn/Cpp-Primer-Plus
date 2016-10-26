#include <iostream>
#include <string>

using namespace std;

int main()
{
    string first_name, last_name;
    int age;
    char grade;

    cout << "What's yout first name? ";
    getline(cin, first_name);
    cout << "What's yout last name? ";
    getline(cin, last_name);
    cout << " What letter grade do you deserve? ";
    cin >> grade;
    cout << "What is your age? ";
    cin >> age;

    cout << "Name: " << last_name << ", " << first_name << endl
        << "Grade: " << (char)(grade + 1) << endl
        << "Age: " << age << endl;

    return 0;
}
