#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string &string_to_upper(string &lower)
{
    for(int i = 0; i < lower.size(); i++)
        lower[i] = toupper(lower[i]);
    return lower;
}

int main()
{
    string lower;

    cout << "Enter a string (q to quit): ";
    getline(cin, lower);
    while(lower != "q")
    {
        cout << string_to_upper(lower) << endl;
        cout << "Next string (q to quit): ";
        getline(cin, lower);
    }
    cout << "Bye." << endl;

    return 0;
}
