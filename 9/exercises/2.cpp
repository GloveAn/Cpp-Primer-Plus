#include <iostream>
#include <string>

using namespace std;

const int ArSize = 10;

void strcount(string & str);

int main()
{
    string input;

    cout << "Enter a line:\n";
    getline(cin, input);
    while(cin && input.size())
    {
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        getline(cin, input);
    }
    cout << "Bye\n";
    return 0;
}

void strcount(string & str)
{
    static int total = 0;

    cout << "\"" << str << "\" contains ";
    total += str.size();
    cout << str.size() << " characters\n";
    cout << total << " characters total\n";
}
